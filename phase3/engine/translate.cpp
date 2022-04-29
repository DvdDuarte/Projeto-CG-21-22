//
// Created by ema on 29/04/22.
//

#include "translate.h"
using namespace std;
#include <string>
#include <GL/glut.h>
#include <iostream>

void buildRotMatrix(float *x, float *y, float *z, float *m) {

    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}


void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

    float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0]/l;
    a[1] = a[1]/l;
    a[2] = a[2]/l;
}
//codigo curvas catmull-rom
void multMatrixVector(float *m, float *v, float *res) {

    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }

}
void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv) {

    // catmull-rom matrix
    float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
                         { 1.0f, -2.5f,  2.0f, -0.5f},
                         {-0.5f,  0.0f,  0.5f,  0.0f},
                         { 0.0f,  1.0f,  0.0f,  0.0f}};
    float T[4]={(t*t*t),(t*t),t,1};
    float T_linha[4]={(3*t*t),2*t,1,0};

    //for each component x,y,z
    for(int i=0;i<3;i++){
        // Compute A = M * P
        float res[4];
        float paux[4];
        paux[0]=p0[i], paux[1]=p1[i], paux[2]=p2[i],paux[3]=p3[i];

        multMatrixVector((float *)m,paux,res);
        // Compute pos = T * A
        pos[i]=T[0]*res[0]+T[1]*res[1]+T[2]*res[2]+T[3]*res[3];
        // compute deriv = T' * A
        deriv[i]=T_linha[0]*res[0]+T_linha[1]*res[1]+T_linha[2]*res[2]+T_linha[3]*res[3];

    }

}




// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv,vector<Point>t_points) {
    float t = gt * t_points.size(); // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    //talvez tenha de se mudar
    int indices[4];
    indices[0] = (index + t_points.size()-1)%t_points.size();
    indices[1] = (indices[0]+1)%t_points.size();
    indices[2] = (indices[1]+1)%t_points.size();
    indices[3] = (indices[2]+1)%t_points.size();

    float p_temp[t_points.size()][3];
    for(int i=0;i<t_points.size();i++){
        p_temp[i][0]=t_points[i].x;
        p_temp[i][1]=t_points[i].y;
        p_temp[i][2]=t_points[i].z;
    }

    getCatmullRomPoint(t, p_temp[indices[0]], p_temp[indices[1]], p_temp[indices[2]], p_temp[indices[3]], pos, deriv);
}


void renderCatmullRomCurve(vector <Point> pontos) {
    //alterar para a fase de desenhar
// draw curve using line segments with GL_LINE_LOOP
    float t=0;
    glBegin(GL_LINE_LOOP);
    float pos[3],deriv[3];
    while(t<1){
        getGlobalCatmullRomPoint(t,pos,deriv,pontos);
        glVertex3fv(pos);
        t+=0.01;
    }
    glEnd();
}
void curveRotation(float *der, float *up){

    float left[3];

    cross(der,up,left);
    cross(left, der, up);

    normalize(der);
    normalize(up);
    normalize(left);

    float m[4][4] = { {der[0], der[1], der[2], 0},
                      {up[0], up[1], up[2], 0},
                      {left[0], left[1], left[2], 0},
                      {0.0f,0.0f,0.0f, 1}
    };
    glMultMatrixf((float*)m);
}
void apply(float time, vector <Point> points, bool talign, int i) {
    float t, g;
    float res[3];
    float derivada[3];
    float up[3];
    up[0] = 0;
    up[1] = 1;
    up[2] = 0;
    float inicial=0;
    float *r_x, *r_y, *r_z, *m;

    if (time != 0) {
        t = glutGet(GLUT_ELAPSED_TIME) % (int) (time * 1000);
        //g = t / (time * 1000);
        g = inicial + i;
        renderCatmullRomCurve(points);
        getGlobalCatmullRomPoint(g, res, derivada, points);
        glTranslatef(res[0], res[1], res[2]);
        curveRotation(derivada, up);
        if (talign) {
            r_x[0] = derivada[0], r_x[1] = derivada[1], r_x[2] = derivada[2];
            cross(r_x, r_y, r_z);
            cross(r_z, r_x, r_y);
            normalize(r_x), normalize(r_y), normalize(r_z);
            buildRotMatrix(r_x, r_y, r_z, m);
            glMultMatrixf(m);
        }
    } //else glTranslatef(getX(), getY(), getZ());
    cout << i<< " i "<<endl;
}

