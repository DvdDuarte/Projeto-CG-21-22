#ifndef PHASE1_GENERATOR_AUX_H
#define PHASE1_GENERATOR_AUX_H

#include <GL/glut.h>
#include <math.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <ccomplex>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Triangle.h"

void createSphere(float radius, float slices, float stacks, std::string filename);

void createBox(float units, float grid, std::string filename);

void createCone(float radius, float height, float slices, float stacks, std::string filename);

void createPlane(float units, int divisions, std::string filename);

std::string vertexToString(Vertex v);

std::string triangleToString(Triangle t);

#endif //PHASE1_GENERATOR_AUX_H
