#include "../include/Box.h"
#include "../../Utils/Point3D.h"
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;

Box::Box() {
    nDivisions=1;
    width=10;
    depth=10;
    height=10;
    index=0;
}

Box::Box(int widthG,int depthG,int heightG,int nDivisionsG) {
    width=widthG;
    depth=depthG;
    height=heightG;
    nDivisions=nDivisionsG;
    index=0;
}

void Box::addSquare(bool top,Point3D topRight,Point3D topLeft,Point3D bellowLeft,Point3D bellowRight) {
    
    Triangle t1,t2;
    if (top) {
        t1=Triangle(topRight.index,topLeft.index,bellowLeft.index);
        t2=Triangle(topRight.index,bellowLeft.index,bellowRight.index);
    }
    else {
        t1=Triangle(topRight.index,bellowLeft.index,topLeft.index);
        t2=Triangle(topRight.index,bellowRight.index,bellowLeft.index);
    }
    faces.push_back(t1);
    faces.push_back(t2);
}



void Box::addXLayer(bool top) {
    
    float y_inc=1.0*height/(1.0*nDivisions);
    float z_inc=1.0*depth/(1.0*nDivisions);
    float tex_inc = 1.0/(1.0*nDivisions);
    float half_width=((float)width)/2.0; // X
    float half_height = ((float)height)/2.0; // Y
    float half_depth=((float)depth)/2.0; // Z
    int x=top?1:0;
    
    vector<Point3D> layer;
    // Cálculo dos pontos 
    for(int y=0;y<=nDivisions;y++) {
        for(int z=0;z<=nDivisions;z++) {
            layer.push_back(Point3D((x*width)-half_width,(y*y_inc)-half_height,(z*z_inc)-half_depth,index++));
            texCoords.push_back(make_pair<float,float>(z*tex_inc,y*tex_inc));
        }
    }
    // Cálculo dos triângulos a desenhar
    for(int y=0;y<nDivisions;y++) {
        for(int z=0;z<nDivisions;z++) {
            Point3D topLeft=layer[((nDivisions+1)*y)+z];
            Point3D topRight=layer[((nDivisions+1)*y)+z+1];
            Point3D bellowLeft=layer[((nDivisions+1)*(y+1))+z];
            Point3D bellowRight=layer[((nDivisions+1)*(y+1))+z+1];
            addSquare(top,topRight,topLeft,bellowLeft,bellowRight);
        }
    }
    for(int i = 0; i < layer.size(); i++)
        normals.push_back(Point3D(top?1:-1,0,0));
    // Adição dos pontos calculados da face ao array de todos pontos que formam o cubo
    points.insert(points.end(),layer.begin(),layer.end());
}

void Box::addYLayer(bool top) { 
    
    float x_inc=1.0*width/(1.0*nDivisions);
    float z_inc=1.0*depth/(1.0*nDivisions);
    float tex_inc = 1.0/(1.0*nDivisions);
    float half_width=((float)width)/2.0; // X
    float half_height = ((float)height)/2.0; // Y
    float half_depth=((float)depth)/2.0; // Z

    int y=top?1:0;

    vector<Point3D> layer;
    // Cálculo dos pontos 
    for(int x=0;x<=nDivisions;x++) {
        for(int z=0;z<=nDivisions;z++) {
            layer.push_back(Point3D((x*x_inc)-half_width,(y*height)-half_height,(z*z_inc)-half_depth,index++));
            texCoords.push_back(make_pair<float,float>(x*tex_inc,z*tex_inc));
        }
    }
    // Cálculo dos triângulos a desenhar
    for(int x=0;x<nDivisions;x++) {
        for(int z=0;z<nDivisions;z++) {
            Point3D topLeft=layer[((nDivisions+1)*x)+z];
            Point3D topRight=layer[((nDivisions+1)*(x+1))+z];
            Point3D bellowLeft=layer[((nDivisions+1)*x)+z+1];
            Point3D bellowRight=layer[((nDivisions+1)*(x+1))+z+1];
            addSquare(top,topRight,topLeft,bellowLeft,bellowRight);
        }
    }
    for(int i = 0; i < layer.size(); i++)
        normals.push_back(Point3D(0,top?1:-1,0));
    // Adição dos pontos calculados da face ao array de todos pontos que formam o cubo
    points.insert(points.end(),layer.begin(),layer.end());
}

void Box::addZLayer(bool top) {
    float y_inc=1.0*height/(1.0*nDivisions);
    float x_inc=1.0*width/(1.0*nDivisions);
    float tex_inc = 1.0/(1.0*nDivisions);
    float half_width=((float)width)/2.0; // X
    float half_height = ((float)height)/2.0; // Y
    float half_depth=((float)depth)/2.0; // Z
    int z=top?1:0;

    vector<Point3D> layer;
    // Cálculo dos pontos
    for(int y=0;y<=nDivisions;y++) {
        for(int x=0;x<=nDivisions;x++) {
            layer.push_back(Point3D((x*x_inc)-half_width,(y*y_inc)-half_height,(z*depth)-half_depth,index++));
            texCoords.push_back(make_pair<float,float>(x*tex_inc,y*tex_inc));
        }
    }
    // Cálculo dos triângulos a desenhar 
    for(int y=0;y<nDivisions;y++) {
        for(int x=0;x<nDivisions;x++) {
            Point3D bellowLeft=layer[((nDivisions+1)*y)+x];
            Point3D bellowRight=layer[((nDivisions+1)*y)+x+1];
            Point3D topLeft=layer[((nDivisions+1)*(y+1))+x];
            Point3D topRight=layer[((nDivisions+1)*(y+1))+x+1];
            addSquare(top,topRight,topLeft,bellowLeft,bellowRight);
        }
    }
    // Cálculo das normais
    for(int i = 0; i < layer.size(); i++)
        normals.push_back(Point3D(0,0,top?1:-1));
    // Adição dos pontos calculados da face ao array de todos pontos que formam o cubo
    points.insert(points.end(),layer.begin(),layer.end());
}

shared_ptr<Model> Box::generate() {
    // Os argumentos false e true retratam a face da caixa (true - direção positiva do eixo; false - direção negativa do eixo)
    addYLayer(false);
    addYLayer(true);
    addXLayer(false);
    addXLayer(true);
    addZLayer(false);
    addZLayer(true);
    float radius = sqrt(width*width + height*height + depth*depth);
    return make_shared<Model>(points,faces,normals,texCoords,radius);
}
