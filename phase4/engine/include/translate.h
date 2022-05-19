//
// Created by ema on 29/04/22.
//

#ifndef PROJETO_CG_21_22_TRANSLATE_H
#define PROJETO_CG_21_22_TRANSLATE_H
#include "color.h"
#include <vector>
#include <math.h>
class Translate {
public:
    Translate(float time1,bool align1, vector<Point> p1){

        time=time1;
        align=align1;
        cout << " translate time: " <<time1 << " align: " << align1 << endl;
        for (int i=0; i<p1.size(); i++){
            p.push_back(p1[i]);
        }

    }
    Translate(Translate *t) {
        time = t->time;
        align = t->align;
        for (int i=0; i<t->p.size(); i++){
            p.push_back(t->p[i]);
        }
    }

    Translate() {
        time=0;
        align=false;
        p= vector<Point>();
    }
    float time;
    vector<Point> p;
    bool align;
};
void buildRotMatrix(float *x, float *y, float *z, float *m);
void normalize(float *a);
void curveRotation(float *der, float *up);
void multMatrixVector(float *m, float *v, float *res);
void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv);
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv,vector<Point>t_points);
void renderCatmullRomCurve(vector <Point> pontos);
void cross(float *a, float *b, float *res);
void apply(float time, vector <Point> points, bool talign, int i);
#endif //PROJETO_CG_21_22_TRANSLATE_H
