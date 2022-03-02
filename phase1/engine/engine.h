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
void read3dFiles (string *files);

/**
 * @brief 
 * 
 * @param line 
 * @param delim 
 * @param out 
 */
void tokengen (string const &line, const char delim, vector<string> &out);
#endif //PHASE1_GENERATOR_H
