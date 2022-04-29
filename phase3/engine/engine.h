
#ifndef PHASE1_GENERATOR_H
#define PHASE1_GENERATOR_H

#include <GL/glut.h>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
#include <iostream>
#include "tinyxml2.h"
#include "engine_aux.h"
#include "colors.h"
#include "translate.h"

int engine (int argc, char **argv);
void readXML(string filename);

/**
 * @brief Function that read the .3d files
 * 
 * @param files The files to read
 */
vector<Triangle> read3dFiles (vector<string >files, int nmr_files, vector<Triangle> tr_arr);

/**
 * @brief 
 * 
 * @param line 
 * @param delim 
 * @param out 
 */
void readTri(int index, string file);
#endif //PHASE1_GENERATOR_H


class Rotate {
public:
    Rotate (bool rtime1,float angle1, float axisX, float axisY, float axisZ) {
        rtime=rtime1;

        angle = angle1;

        x = axisX;

        y = axisY;

        z = axisZ;
        if(rtime)
        cout << " rotate: time: " << angle << " x: " << x <<" y: " << y << " z: " << z << endl;
        else
        cout << " rotate: angle: " << angle << " x: " << x <<" y: " << y << " z: " << z << endl;

    }
    Rotate (Rotate *r) {
        rtime=r->rtime;
        x = r->x;
        y= r-> y;
        z = r->z;
        angle = r->angle;
    }
    Rotate () {
        rtime=false;
        x= 0;
        y= 0;
        z = 0;
        angle = 0;
    }
    bool rtime;
    float x;
    float y;
    float z;
    float angle;
};

class Scale {
public:
    Scale (float x1, float y1, float z1) {

        x = x1;
        y = y1;
        z = z1;
        cout << " scale x: " << x1 << " y: " << y1  << " z: "<< z1 << endl;
    }
    Scale (Scale *s) {
        x = s->x;
        y = s-> y;
        z = s->z;
    }
    Scale () {
        x= 1;
        y= 1;
        z = 1;
    }
    float x;
    float y;
    float z;
};


class Group{
public:
    Group(vector<Translate> x, vector<Rotate> y, vector <Scale> z,vector<Point>p1, vector<Triangle> filesAux, vector<Group>groupchildsAux, int nrchildsAux,vector<string> transforms){
        t = x;
        r = y;
        s = z;
        p= p1;
        files = filesAux;
        groupchilds = groupchildsAux;
        nrchilds = nrchildsAux;
        orderTransform = transforms;
    }

    Group(Group *group) {
        files = group->files;
        t = group->t;
        r = group->r;
        s = group->s;
        p = group->p;
        groupchilds = group->groupchilds;
        nrchilds = group->nrchilds;
        orderTransform= group->orderTransform;


    }
    vector<Triangle> files;
    vector<Group>groupchilds;
    vector<Translate> t;
    vector<Rotate> r;
    vector<Scale> s;
    vector<Point> p;
    int nrchilds;
    vector<string> orderTransform;

};

void readCamera(tinyxml2::XMLElement *world);
Group readGroup(tinyxml2::XMLElement *group);
void draw (Group g);