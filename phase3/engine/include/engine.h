
#ifndef PHASE1_GENERATOR_H
#define PHASE1_GENERATOR_H

#include <GL/glut.h>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
#include <iostream>
#include "../src/XMLParser/tinyxml2.h"
#include "engine_aux.h"
#include "colors.h"
#include "translate.h"
#include "rotate.h"
#include "vbo.h"


int engine (int argc, char **argv);
void readXML(string filename);

/**
 * @brief Function that read the .3d files
 * 
 * @param files The files to read
 */
float* read3dFiles (vector<string >files, int nmr_files, float* tr_arr);

/**
 * @brief 
 * 
 * @param line 
 * @param delim 
 * @param out 
 */
void readTri(int index, string file);
#endif //PHASE1_GENERATOR_H

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
    Group(vector<Translate> x, vector<Rotate> y, vector <Scale> z,vector<Point>p1, vbo filesAux, int numberV, vector<Group>groupchildsAux, int nrchildsAux,vector<string> transforms){
        t = x;
        r = y;
        s = z;
        p= p1;
        files = filesAux;
        groupchilds = groupchildsAux;
        nrchilds = nrchildsAux;
        orderTransform = transforms;
        numberOfVertices = numberV;
    }

    Group(Group *group) {
        files = group->files;
        t = group->t;
        r = group->r;
        s = group->s;
        p = group->p;
        numberOfVertices = group->numberOfVertices;
        groupchilds = group->groupchilds;
        nrchilds = group->nrchilds;
        orderTransform= group->orderTransform;


    }
    vbo files;
    vector<Group>groupchilds;
    vector<Translate> t;
    vector<Rotate> r;
    vector<Scale> s;
    vector<Point> p;
    int nrchilds;
    vector<string> orderTransform;
    int numberOfVertices;
};

void readCamera(tinyxml2::XMLElement *world);
Group readGroup (tinyxml2::XMLElement *group, int x, bool child);
void draw (Group g, int x, bool t);