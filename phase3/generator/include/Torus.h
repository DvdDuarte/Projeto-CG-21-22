/**
 * @file Torus.h
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File with the class Triangle and it's constructors
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHASE1_TORUS_H
#define PHASE1_TORUS_H
#include "Vertex.h"
/**
 * @brief class Torus used to generate all kinds of Rings
 * 
 */
class Torus {
public:
    /**
     * @brief Construct a new Triangle object
     * 
     * @param vertex1 The first Vertex of the Triangle
     * @param vertex2 The second Vertex of the Triangle
     * @param vertex3 The third Vertex of the Triangle
     */
    Torus() {
        widenessRadius=1;
        thicknessRadius=1;
        nSides=10;
        nRings=10;
    };
    Torus(int widenessRadiusG,int thicknessRadiusG,int ringsG,int sidesG) {
    widenessRadius=widenessRadiusG;
    thicknessRadius=thicknessRadiusG;
    nSides=sidesG;
    nRings=ringsG;
    };
    
    int widenessRadius;
    int thicknessRadius;
    int nSides;
    int nRings;
};


#endif //PHASE2_TORUS_H

