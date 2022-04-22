/**
 * @file generator_aux.h
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File with the auxiliar functions for the generator
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

using namespace std;
/**
 * @brief Create a read a patch file
 * 
 * @param filename The name of the file where the control points are.
 */
//void read_patch(string filename,Patch* p);

/**
 * @brief Create an Object
 * 
 * @param patch name of the file cointaing the Bezier control points
 * @param t int representing the tesselation level
 * @param filename The name of the file where the data is going to be stored (Preferably ring.3d)
 */
void generate_triangles(std::string patch,int t,std::string filename);

void createRing(std::string filename);

/**
 * @brief Create a Sphere object
 * 
 * @param radius The radius of the Sphere
 * @param slices The number of
 * @param stacks The number of
 * @param filename The name of the file where the data is going to be stored (Preferably sphere.3d)
 */
void createSphere(float radius, int slices, int stacks, std::string filename);


/**
 * @brief Create a Box object
 * 
 * @param units The size for the edge of the Box
 * @param grid The number of divisons each side of the Box is going to have
 * @param filename The name of the file where the data is going to be stored (Preferably box.3d)
 */
void createBox(float units, float grid, std::string filename);

/**
 * @brief Create a Cone object
 * 
 * @param radius The radius for the base of the cone
 * @param height The height of the cone
 * @param slices The number of
 * @param stacks The number of
 * @param filename The name of the file where the data is going to be stored (Preferably cone.3d)
 */
void createCone(float radius, float height, float slices, float stacks, std::string filename);

/**
 * @brief Create a Plane object
 * 
 * @param units The size for the edge of the Plane
 * @param divisions The number of divisions the Plane is going to have
 * @param filename The name of the file where the data is going to be stored (Preferably plane.3d)
 */
void createPlane(float units, int divisions, std::string filename);

/**
 * @brief Transforms the Vertex Object in a String
 * 
 * @param v The Vertex to transform into a String
 * @return std::string The String with the Vertex information
 */
std::string vertexToString(Vertex v);

/**
 * @brief Transforms the Triangle Object in a String
 * 
 * @param t The Triangle to transform into a String
 * @return std::string The String with the Triangle information
 */
std::string triangleToString(Triangle t);

#endif //PHASE1_GENERATOR_AUX_H
