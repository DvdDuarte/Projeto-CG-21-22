//
// Created by sleiman on 23/02/22.
//

#ifndef PHASE1_GENERATOR_H
#define PHASE1_GENERATOR_H

#include <GL/glut.h>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

#include <iostream>


#include "engine_aux.h"
#include "colors.h"

int engine (int argc, char **argv);
void readXML(string filename);

/**
 * @brief Function that read the .3d files
 * 
 * @param files The files to read
 */
void read3dFiles (string *files, int nmr_files);

/**
 * @brief 
 * 
 * @param line 
 * @param delim 
 * @param out 
 */
void readTri(int index, string file);
#endif //PHASE1_GENERATOR_H


class Translate {
public:
    Translate(float x1, float y1, float z1){

        x = x1;
        y = y1;
        z = z1;
        cout << " translate x: " << x1 << " y: " << y1 << " z: " << z1 << endl;
    }
    Translate(Translate *t) {
        x = t->x;
        y = t->y;
        z = t->z;
    }
    Translate() {
        x=0;
        y=0;
        z=0;
    }
    float x;
    float y;
    float z;
};

class Rotate {
public:
    Rotate (float angle1, float axisX, float axisY, float axisZ) {

        angle = angle1;

        x = axisX;

        y = axisY;

        z = axisZ;
        cout << " rotate: angle: " << angle << " x: " << x <<" y: " << y << " z: " << z << endl;


    }
    Rotate (Rotate *r) {
        x = r->x;
        y= r-> y;
        z = r->z;
        angle = r->angle;
    }
    Rotate () {
        x= 0;
        y= 0;
        z = 0;
        angle = 0;
    }
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
        cout << " scale x: " << x << " y: " << y  << " z: "<< z << endl;


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
    Group(Translate* x, Rotate* y, Scale* z, vector<string>filesAux, Group *groupchildsAux, int nrchildsAux, vector<string> transferencias, int nrFilesAux){
        t = x;
        r = y;
        s = z;
        files = filesAux;
        groupchilds = groupchildsAux;
        nrchilds = nrchildsAux;
        orderTransferencia = transferencias;
        nrFiles = nrFilesAux;
    }

    Group(Group *group) {
        files = group->files;
        t = group->t;
        r = group->r;
        s = group->s;
        groupchilds = group->groupchilds;
        nrchilds = group->nrchilds;
        orderTransferencia = group->orderTransferencia;
        nrFiles = group ->nrFiles;

    }
    vector<string> files;
    Group *groupchilds;
    Translate* t;
    Rotate* r;
    Scale* s;
    Color c;
    int nrchilds;
    vector<string> orderTransferencia;
    int nrFiles;
};


