#ifndef PHASE4_ENGINE_COLOR_H
#define PHASE4_ENGINE_COLOR_H

#endif 
#include <string>
using namespace std;
#include <iostream>
#include "Point.h"

class Color{
public:

 Color(Point d_1,Point a_1,Point s_1, Point e_1, float sh_1){
        d = Point(d_1.getX(),d_1.getY(),d_1.getZ());
        a = Point(a_1.getX(),a_1.getY(),a_1.getZ());
        s = Point(s_1.getX(),s_1.getY(),s_1.getZ());
        e = Point(e_1.getX(),e_1.getY(),e_1.getZ());
        sh = sh_1;

        cout << "Color shininess:"<< sh << endl;
        //cout << " Color : " << x1 << " y: " << y1 << " z: " << z1 << endl;
    }
    Color(Color *c){
        d = c->d;
        a = c->a;
        s = c->s;
        e = c->e;
        sh = c->sh;

    }
    Color(){
        d = Point();
        a = Point();
        s = Point();
        e = Point();
        sh = 0;
    }
    Point d;
    Point a;
    Point s;
    Point e;
    float sh;
    //float x;
    //float y;
    //float z;

};