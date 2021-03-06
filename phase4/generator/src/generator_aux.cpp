#include "../include/generator_aux.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "../include/Torus.h"
#include "../include/Patch.h"
int sizeArray = 100;
Triangle *triangles;
Triangle *normals;
//Vertex * vertices;


void createSphere(float radius, int slices, int stacks, std::string filename) {

    int triangle_nmr = 0;
    ofstream file_handler;
    file_handler.open(filename);
    Vertex *v1,*v2,*v3,*v4;
    Triangle *t1,*t2;
    float delta_alfa=2*M_PI/(slices);
    float delta_beta=M_PI/(stacks);
    float origem=-M_PI/2;

    for(int i=0;i <stacks; i++){
        //triangles = (Triangle *) malloc(2* sizeof(Triangle));
        //vector<int> pt;

        for(int j=0;j < slices; j++){
            triangles = (Triangle *) malloc(2* sizeof(Triangle));
            float x1=radius*cos((origem) + i*delta_beta)*sin(j*delta_alfa);
            float z1=radius*cos((origem) + i*delta_beta)*cos(j*delta_alfa);
            float y1=radius*sin((origem) + i*delta_beta);
            //Vertex *v1,*v2,*v3,*v4;
            v1=new Vertex(x1,y1,z1);

            v2=new Vertex(radius*cos((origem) + (i+1)*delta_beta)*sin(j*delta_alfa),
                          radius*sin((origem) + (i+1)*delta_beta),
                          radius*cos((origem) + (i+1)*delta_beta)*cos(j*delta_alfa));

            v3=new Vertex(radius*cos((origem) + (i+1)*delta_beta)*sin((j+1)*delta_alfa),
                          radius*sin((origem) + (i+1)*delta_beta),
                          radius*cos((origem) + (i+1)*delta_beta)*cos((j+1)*delta_alfa));

            v4=new Vertex(radius*cos((origem) + i*delta_beta)*sin((j+1)*delta_alfa),
                          radius*sin((origem) + i*delta_beta),
                          radius*cos((origem) + i*delta_beta)*cos((j+1)*delta_alfa));
            //primeiro triang = v1,v2,v3
            t1 = new Triangle(v1,v2,v3);
            //segundo triang= v1,v3,v4
            t2 = new Triangle(v1,v3,v4);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            for(triangle_nmr = 0; triangle_nmr < 2; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
        }

    }
    file_handler.close();

}

void createBox(float units, float grid, string filename) {
    //falta completar e testar

    int triangle_nmr_max = 12 * grid * grid;

    int triangle_nmr = 0;

    float halfx = 0, halfz = 0, halfy = 0, halfx_temp = 0, halfy_temp = 0, halfz_temp = 0;
    float aux_x1=0 ,aux_x2=0, aux_y1=0, aux_y2=0, aux_z1=0, aux_z2=0;

    halfx = halfz = halfy = units / 2;

    Triangle *t1, *t2, *t3, *t4;
    Triangle *tn1,*tn2,*tn3,*tn4;

    Vertex *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
    Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8;

    halfx_temp = halfz_temp = halfy_temp =  units / grid;
    //triangles = (Triangle *) malloc(sizeArray * sizeof(Triangle));
    ofstream file_handler;
    file_handler.open(filename);
    //  file_handler << "Number of triangles in the grid: " << triangle_nmr_max << endl;
    cout << "max " << triangle_nmr_max << endl;

    // Faces: Front e Back for x and y
    // aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
    for (int i = 0; -halfx + i * halfx_temp < halfx; i++) {
        for (int j=0; -halfy + j*halfy_temp < halfy; j++) {
            triangles = (Triangle *) malloc(4* sizeof(Triangle));
            normals= (Triangle*)malloc(4* sizeof(Triangle));
            aux_x1 = -halfx + ((i) * halfx_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_y1 = -halfy + (j) * halfy_temp;
            aux_y2 = -halfy + (j + 1) * halfy_temp;
            aux_z1 = -halfz; // fixo
            aux_z2 = halfz;  // fixo

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);


            n1= new Vertex(0,0,1);

            //FRONT
            n1= new Vertex(0,0,1);
            tn1=new Triangle(n1,n1,n1);
            t1 = new Triangle(v1,v2,v3);
            t2 = new Triangle(v1,v3,v4);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;
            normals[triangle_nmr] = tn1;
            normals[triangle_nmr+1] = tn1;

            //BACK
            n2= new Vertex(0,0,-1);
            tn2= new Triangle(n2,n2,n2);
            t3 = new Triangle(v5,v6,v7);
            t4 = new Triangle(v5,v7,v8);
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;
            normals[triangle_nmr+2] = t2;
            normals[triangle_nmr+3] = t2;

            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                string norm = triangleToString(normals[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
            free(normals);
        }
    }

    //Faces : top and bottom x e z
    //  aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
    for (int k=0; -halfz + k* halfz_temp < halfz; k++) {
        for (int i=0; -halfx + i*halfx_temp < halfx; i++) {

            triangles = (Triangle *) malloc(4* sizeof(Triangle));
            normals= (Triangle*)malloc(4* sizeof(Triangle));

            aux_x1 = -halfx + ((i) * halfx_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_z1 = -halfz + (k) * halfz_temp;
            aux_z2 = -halfz + (k+ 1) * halfz_temp;
            aux_y1 = -halfy; //y fixo
            aux_y2 = halfy;  //y fixo

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);

            //TOP
            n1= new Vertex(0,1,0);
            tn1=new Triangle(n1,n1,n1);
            t1 = new Triangle(v4,v3,v7);
            t2 = new Triangle(v3,v8,v7);
            normals[triangle_nmr]=tn1;
            normals[triangle_nmr+1]=tn1;
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            //BOTTOM
            n2=new Vertex(0,-1,0);
            tn2=new Triangle(n2,n2,n2);
            t3 = new Triangle(v2,v1,v6);
            t4 = new Triangle(v5,v2,v6);
            normals[triangle_nmr+2] = tn2;
            normals[triangle_nmr+3] =tn2;
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;

            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                string norm = triangleToString(normals[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
            free(normals);
        }
    }

    // Faces: right and left for z and y
    //  aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
    for (int k=0; -halfz + k* halfz_temp < halfz; k++) {
        for (int j = 0; -halfy + j*halfy_temp < halfy; j++) {

            triangles = (Triangle *) malloc(4* sizeof(Triangle));
            normals= (Triangle*)malloc(4* sizeof(Triangle));

            aux_z1 = -halfz + ((k) * halfz_temp);
            aux_z2 = -halfz + ((k+ 1) * halfz_temp);
            aux_y1 = -halfy + ((j) * halfy_temp);
            aux_y2 = -halfy + ((j + 1) * halfy_temp);
            aux_x1= -halfx;
            aux_x2 = halfx;

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);

            //RIGHT
            n1=new Vertex(1,0,0);
            tn1=new Triangle(n1,n1,n1);
            t1 = new Triangle(v2,v5,v3);
            t2 = new Triangle(v5,v8,v3);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;
            normals[triangle_nmr] = tn1;
            normals[triangle_nmr+1] = tn1;

            //LEFT
            n2=new Vertex(-1,0,0);
            tn2=new Triangle(n2,n2,n2);
            t3= new Triangle(v6,v1,v4);
            t4= new Triangle(v6,v4,v7);
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;
            normals[triangle_nmr+2] = tn2;
            normals[triangle_nmr+3] = tn2;


            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                string norm = triangleToString(normals[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
            free(normals);
        }
    }

    //  free(triangles);
    file_handler.close();
}

void createCone(float radius, float height, float slices, float stacks, string filename){

    float stack_height = height / stacks;
    float stack_radius = radius / stacks;
    float angle = ( 2 * M_PI) / slices;
    ofstream file_cone_handler;
    file_cone_handler.open(filename);

    for (int stack_step = 0; stack_step < stacks; stack_step++){
        float previous_height = stack_height * (stacks - stack_step);
        float next_height = stack_height * (stacks - stack_step - 1);
        float init_radius = stack_radius * stack_step;
        float final_radius = stack_radius * (stack_step + 1);

        for(int slice_step = 0; slice_step < slices; slice_step++){
            float current_angle = angle * slice_step;
            float next_angle = angle * (slice_step + 1);
            if(!stack_step) {
                Vertex *v1 = new Vertex(0.0, 0.0, 0.0);
                Vertex *v2 = new Vertex(radius * sin(next_angle), 0.0, radius * cos(next_angle));
                Vertex *v3 = new Vertex(radius * sin(current_angle), 0.0, radius * cos(current_angle));
                Triangle *t1 = new Triangle(v1, v2, v3);
                string info = triangleToString(t1);
                file_cone_handler << info;
            }
            Vertex *v4 = new Vertex(final_radius * sin(next_angle), next_height, final_radius * cos(next_angle));
            Vertex *v5 = new Vertex(init_radius * sin(next_angle), previous_height, init_radius * cos(next_angle));
            Vertex *v6 = new Vertex(init_radius * sin(current_angle), previous_height, init_radius * cos(current_angle));
            Triangle *t2 = new Triangle(v4, v5, v6);
            string info = triangleToString(t2);
            file_cone_handler << info;
            Vertex *v7 = new Vertex(final_radius * sin(current_angle), next_height, final_radius * cos(current_angle));
            Vertex *v8 = new Vertex(final_radius * sin(next_angle), next_height, final_radius * cos(next_angle));
            Vertex *v9 = new Vertex(init_radius * sin(current_angle), previous_height, init_radius * cos(current_angle));
            Triangle *t3 = new Triangle(v7, v8, v9);
            info = triangleToString(t3);
            file_cone_handler << info;

        }
    }
    file_cone_handler.close();
}

void createPlane(float units, int divisions, std::string filename){

    int triangle_nmr_max = divisions * divisions * 2; // For each slice in the grid generated by the number of divisions we have 2 slices;

    // int sizeArray = 100;
    int triangle_nmr = 0;
    Triangle *t1, *t2;
    float halfx = 0, halfz = 0, halfx_temp = 0, halfz_temp = 0, aux_x1 = 0, aux_z1 = 0, aux_x2 = 0, aux_z2 = 0;
    halfx = halfz = units / 2;
    halfx_temp = halfz_temp = units / divisions;

    Vertex *v1, *v2, *v3, *v4;
    triangles = (Triangle *) malloc(sizeArray * sizeof(Triangle));

    ofstream file_handler;
    file_handler.open(filename);
    //file_handler << "Number of triangles in the grid: " << triangle_nmr_max << endl;

    for (int i = 0; -halfx + i * halfx_temp < halfx; i++) {
        for (int j = 0; -halfz + j * halfz_temp < halfz; j++) {
            aux_x1 = -halfx + (i * halfx_temp);
            aux_z1 = -halfz + (j * halfz_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_z2 = -halfz + ((j + 1) * halfz_temp);

            v1 = new Vertex(aux_x1, 0 , aux_z1);
            v2 = new Vertex(aux_x1, 0, aux_z2);
            v3 = new Vertex(aux_x2, 0 , aux_z2);
            v4 = new Vertex(aux_x2, 0 ,aux_z1);

            if(triangle_nmr >= sizeArray) {
                cout << "entrou " << triangle_nmr << endl;
                sizeArray *=2;
                triangles = (Triangle *) realloc(triangles, sizeArray * sizeof(Triangle));     }


            t1 = new Triangle(v1, v2, v3);
            t2 = new Triangle(v3, v4, v1);

            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr + 1] = t2;
            triangle_nmr += 2;
        }
    }

    for(triangle_nmr = 0; triangle_nmr < triangle_nmr_max; triangle_nmr++) {
        string info = triangleToString(triangles[triangle_nmr]);
        file_handler << info;
    }

    // free(triangles);
    file_handler.close();
}

string vertexToString(Vertex v){
    string vertex_info = to_string(v.x) + ";" + to_string(v.y) + ";" + to_string(v.z);
    return vertex_info;
}

string triangleToString(Triangle t){
    Vertex v1 = t.v1;
    Vertex v2 = t.v2;
    Vertex v3 = t.v3;

    string triangle_info = vertexToString(v1) + "," +vertexToString(v2) + "," +vertexToString(v3) + "\n"; // EOT == End Of Triangle
    return triangle_info;
}

Vertex* BezierCurveCalculate(float t, Vertex* p0, Vertex* p1, Vertex* p2, Vertex* p3) {
// B(t) = (1-t)?? P0 + 3(1-t)?? t P1 + 3 (1-t) t?? P2 + t?? P3

 float coefficient0 = (1-t) * (1-t) * (1-t);
 float coefficient1 = 3 * ((1-t) * (1-t))* t;
 float coefficient2 = 3 * (1-t) * (t*t);
 float coefficient3 = t*t*t;

 float x = coefficient0 * p0->x + coefficient1 * p1->x + coefficient2* p2->x + coefficient3 * p3->x;
 float y = coefficient0 * p0->y + coefficient1 * p1->y + coefficient2* p2->y + coefficient3 * p3->y;
 float z = coefficient0 * p0->z+ coefficient1 * p1->z + coefficient2* p2->z + coefficient3 * p3->z;

 Vertex* result = new Vertex(x,y,z);
 return result;
}
void multMatVet(float* a, float *b, float *res) {
    for (int i = 0; i < 4; ++i) {
        res[i] = 0;
        for (int j = 0; j < 4; ++j) {
            int pos = i * 4 + j;
            res[i] += a[pos] * b[j];
        }
    }
}


Vertex* calculatePatchPoints(float u, float v, vector<Vertex*> controlPoints) {
    float auxmatrix[4][3]; // 4 points x,y,z
    float matrix[4][3];
    int point, j = 0, k=0;

    for (point = 0; point < 16; point ++) { //each patch has 16 points
        auxmatrix[j][0] = controlPoints[point]->x;
        auxmatrix[j][1] = controlPoints[point]->y;
        auxmatrix[j][2] = controlPoints[point]->z;
       // cout << "control P " << controlPoints[point]->x << " " << controlPoints[point]->y << " " << controlPoints[point]->z<<endl;

        j++;
        if (j % 4==0) {
            Vertex* cal= BezierCurveCalculate(u, new Vertex(auxmatrix[0][0],auxmatrix[0][1],auxmatrix[0][2]),
                                                     new Vertex(auxmatrix[1][0],auxmatrix[1][1],auxmatrix[1][2]),
                                                     new Vertex(auxmatrix[2][0],auxmatrix[2][1],auxmatrix[2][2]),
                                                     new Vertex(auxmatrix[3][0],auxmatrix[3][1],auxmatrix[3][2]));
            matrix[k][0] = cal->x;
            matrix[k][1] = cal->y;
            matrix[k][2] = cal->z;

            k++;
            j = 0;
        }
    }

    Vertex* cal2 = BezierCurveCalculate(v,new Vertex(matrix[0][0],matrix[0][1],matrix[0][2]),
                                                new Vertex(matrix[1][0],matrix[1][1],matrix[1][2]),
                                                new Vertex(matrix[2][0],matrix[2][1],matrix[2][2]),
                                                new Vertex(matrix[3][0],matrix[3][1],matrix[3][2]));


    return cal2;
}




void renderPatches(int tesselation, vector<Patch*> patches, string output){
    vector <Triangle* > ts;
    ofstream myFile_Handler;
    myFile_Handler.open(output);
    Triangle *t1, *t2;
    Vertex *p0, *p1,*p2,*p3;
    int triangle_nmr=0, tN=0;
    vector<Vertex*> result;
    float u, u2, v, v2;
    float add = 1.0/ tesselation;
    triangles = (Triangle *) malloc(sizeArray* sizeof(Triangle));
    cout << "n Patches :: "<< patches.size() << endl;
    for(int numberOfPatches = 0; numberOfPatches < patches.size(); numberOfPatches++){ //for each patch
        vector<Vertex*> controlPoints = patches[numberOfPatches]->cp;
        cout <<"control Points  :: "  <<  controlPoints.size()<< endl;
        for(int j=0; j <= tesselation ; j++){ //for v
            for(int i=0; i <= tesselation; i++) { //for u

                u = i * add;
                v = j * add;
                u2 = (i + 1) * add;
                v2 = (j + 1) * add;

                p0 = calculatePatchPoints(u, v, controlPoints);
                p1 = calculatePatchPoints(u, v2, controlPoints);
                p2 = calculatePatchPoints(u2, v, controlPoints);
                p3 = calculatePatchPoints(u2, v2, controlPoints);

                t1 = new Triangle(p0, p2, p3);
                t2 = new Triangle(p0, p3, p1);

                ts.push_back(t1);
                ts.push_back(t2);
                triangle_nmr += 2;


            }
        }


    }

    while (tN<triangle_nmr) {
        cout << tN << endl;
        string info = triangleToString(ts.at(tN));
        tN++;
        myFile_Handler << info;
    }

    cout << "end" << endl;
}

void normalize(float *a) {

    float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0]/l;
    a[1] = a[1]/l;
    a[2] = a[2]/l;
}


float BezierWithDerivadasForU(float u, float v, float p[4][4]) {
    float result= 0;
    float matrixaux[4], matrixaux2[4];
    //matriz de bezier
    float m[4][4] =  {{ -1.0f, 3.0f, -3.0f, 1.0f },
                            { 3.0f, -6.0f, 3.0f, 0.0f },
                            { -3.0f, 3.0f, 0.0f, 0.0f },
                            { 1.0f,  0.0f, 0.0f, 0.0f }};
    // derivada de u = derivada de p por u = [ 3 u?? 2u 1 0]
    // derivada * matriz de bezier * pontos
    for(int i = 0; i<4; i++){
        matrixaux[i] = (3 * powf(u,2.0)*m[0][i]) + (2*u*m[1][i]) + (1*m[2][i]);
    }

    for(int i = 0; i<4; i++){
        matrixaux2[i] = (matrixaux[0]*p[0][i]) + (matrixaux[1]*p[1][i]) + (matrixaux[2]*p[2][i]) + (matrixaux[3]*p[3][i]);
    }

    // matriz transposta = matriz (simetria)
    for(int i = 0; i<4; i++){
        matrixaux[i] = (matrixaux2[0]*m[0][i]) + (matrixaux2[1]*m[1][i]) + (matrixaux2[2]*m[2][i]) + (matrixaux2[3]*m[3][i]);
    }

    //  multiplicar por [v?? v?? v 1]
    result = matrixaux[0] * powf(v,3.0);
    result += matrixaux[1] * powf(v,2.0);
    result += matrixaux[2] * v;
    result += matrixaux[3];

    return result;

}

float BezierWithDerivadasForV(float u, float v, float p[4][4]) {
    float result= 0;
    float matrixaux[4], matrixaux2[4];
    //matriz de bezier
    float m[4][4] =  {{ -1.0f, 3.0f, -3.0f, 1.0f },
                            { 3.0f, -6.0f, 3.0f, 0.0f },
                            { -3.0f, 3.0f, 0.0f, 0.0f },
                            { 1.0f,  0.0f, 0.0f, 0.0f }};
    //u * m * pontos * m * derivada u
    for(int i = 0; i<4; i++){
        matrixaux[i] = (powf(u,3.0)*m[0][i]) + (powf(u,2.0)*m[1][i]) + (u*m[2][i]) + m[3][i];
    }
    for(int i = 0; i<4; i++){
        matrixaux2[i] = (matrixaux[0]*p[0][i]) + (matrixaux[1]*p[1][i]) + (matrixaux[2]*p[2][i]) + (matrixaux[3]*p[3][i]);
    }
    for(int i = 0; i<4; i++){
        matrixaux[i] = (matrixaux2[0]*m[0][i]) + (matrixaux2[1]*m[1][i]) + (matrixaux2[2]*m[2][i]) + (matrixaux2[3]*m[3][i]);
    }

    // multiplicar por derivada de v = [3v?? 2v 1 0 ] 4*1
    result= matrixaux[0] * (3 * powf(v,2.0));
    result += matrixaux[1] * (2 * v);
    result += matrixaux[2];
    return result;
}

/*
vector<Vertex*> creatBezierNormasVector(int tessellation, vector<Patch*>patches) {
    vector<Vertex*> normas;
    int i, j, aux;
    float  px[4][4], py[4][4], pz[4][4], derivadaU[3], derivadaV[3], norma[3];
    float u1, v1, u2, v2, tess = (float)1.0/(float)tessellation;

    for(int npatches = 0; npatches < patches.size(); npatches++){
        vector<Vertex*> controlP= patches[npatches]->cp;
       float pointaux = 0;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                while(pointaux<4) {
                    //16 pontos P00,P01,P02,P03,P10,P11,P12,P13,P21,P22,P23,P23,P30,P31,P32,P33
                    // 3 pontos de controlo, com 3 coordenadas
                    px[i][j] = controlP[pointaux]->x;
                    py[i][j] = controlP[pointaux]->y;
                    pz[i][j] = controlP[pointaux]->z;
                    pointaux++;
                }
            }
        }

        for(i = 0; i<=tessellation ; i++){
            u1 = i * tess;
            u2 = (i+1) * tess;

            for(j = 0; j<=tessellation ; j++){
                v1 = j * tess;
                v2 = (j+1) * tess;

                //for u and v
                derivadaU[0] = BezierWithDerivadasForU(u1,v1,px);
                derivadaU[1] = BezierWithDerivadasForU(u1,v1,py);
                derivadaU[2] = BezierWithDerivadasForU(u1,v1,pz);

                derivadaV[0] = BezierWithDerivadasForV(u1,v1,px);
                derivadaV[1] = BezierWithDerivadasForV(u1, v1,py);
                derivadaV[2] = BezierWithDerivadasForV(u1, v1, pz);
                normalize(derivadaU);
                normalize(derivadaV);
                multMatVet(derivadaV,derivadaU,norma);
                normas.push_back(new Vertex(norma[0],norma[1],norma[2]));


                // for u2 and v
                derivadaU[0] = BezierWithDerivadasForU(u2,v1,px);
                derivadaU[1] = BezierWithDerivadasForU(u2,v1,py);
                derivadaU[2] = BezierWithDerivadasForU(u2,v1,pz);

                derivadaV[0] = BezierWithDerivadasForV(u2,v1,px);
                derivadaV[1] = BezierWithDerivadasForV(u2, v1,py);
                derivadaV[2] = BezierWithDerivadasForV(u2, v1, pz);
                normalize(derivadaU);
                normalize(derivadaV);
                multMatVet(derivadaV,derivadaU,norma);
                normas.push_back(new Vertex(norma[0],norma[1],norma[2]));

                // for u1 and v2
                derivadaU[0] = BezierWithDerivadasForU(u1,v2,px);
                derivadaU[1] = BezierWithDerivadasForU(u1,v2,py);
                derivadaU[2] = BezierWithDerivadasForU(u1,v2,pz);

                derivadaV[0] = BezierWithDerivadasForV(u1,v2,px);
                derivadaV[1] = BezierWithDerivadasForV(u1, v2,py);
                derivadaV[2] = BezierWithDerivadasForV(u1, v2, pz);
                normalize(derivadaU);
                normalize(derivadaV);
                multMatVet(derivadaV,derivadaU,norma);
                normas.push_back(new Vertex(norma[0],norma[1],norma[2]));

                // for u2 and v2
                derivadaU[0] = BezierWithDerivadasForU(u2,v2,px);
                derivadaU[1] = BezierWithDerivadasForU(u2,v2,py);
                derivadaU[2] = BezierWithDerivadasForU(u2,v2,pz);

                derivadaV[0] = BezierWithDerivadasForV(u2,v2,px);
                derivadaV[1] = BezierWithDerivadasForV(u2, v2,py);
                derivadaV[2] = BezierWithDerivadasForV(u2, v2, pz);
                normalize(derivadaU);
                normalize(derivadaV);
                multMatVet(derivadaV,derivadaU,norma);
                normas.push_back(new Vertex(norma[0],norma[1],norma[2]));


            }
        }
    }
    return normas;
}
*/


string getLine(string filename, int nline){
    string line;
    ifstream file;
    file.open(filename);

    if(file.is_open()){
        for(int j=0; j < nline; j++)
            getline(file,line);
        file.close();
    }
    else cout << "error: " << filename<< endl;
    return line;
}

void createBezier(int t, string filename, string output){
    string line, token, line2, nline;
    int nPatches, i;
    int index;
    float value;
    float vertex[3];

    vector<Patch*> patches;

    ifstream file;
    file.open(filename);

    if(file.is_open()){


        getline(file,line);
        stringstream ss(line);
        ss >> nPatches;
        for(int k=0; k<nPatches; k++){

            getline(file,line);
            Patch* patch = new Patch();


            for(int j=0; j<16; j++){
                i = line.find(",");
                token = line.substr(0, i);
                index = atoi(token.c_str());
                line.erase(0, i + 1);

                nline = getLine(filename, nPatches + 3 + index);
                line2 = nline;

                for(int j=0; j<3; j++){
                    i = nline.find(",");
                    token = nline.substr(0, i);
                    vertex[j] = atof(token.c_str());
                    nline.erase(0, i + 1);
                }

                nline = line2;
                patch->addVertex(new Vertex(vertex[0],vertex[1],vertex[2]));
            }
            patches.push_back(patch);
        }
            renderPatches(t,patches,output);

        file.close();
    }

    else cout << "error: " << filename <<  endl;

}

