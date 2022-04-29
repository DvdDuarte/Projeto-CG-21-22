//
// Created by ema on 29/04/22.
//

#ifndef PROJETO_CG_21_22_POINT_H
#define PROJETO_CG_21_22_POINT_H

#endif //PROJETO_CG_21_22_POINT_H
#include <string>
using namespace std;
#include <iostream>

class Point{
public:
    Point(float x1,float y1, float z1){
        x = x1;
        y = y1;
        z = z1;
        cout << " point x: " << x1 << " y: " << y1 << " z: " << z1 << endl;
    }
    Point(Point *p){
        x = p->x;
        y = p->y;
        z = p->z;
    }
    Point(){
        x=0;
        y=0;
        z=0;
    }
    float x;
    float y;
    float z;

};