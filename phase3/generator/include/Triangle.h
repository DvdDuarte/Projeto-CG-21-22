/**
 * @file Triangle.h
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File with the class Triangle and it's constructors
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHASE3_TRIANGLE_H
#define PHASE3_TRIANGLE_H

#include "Vertex.h"
/**
 * @brief class Triangle used to generate all kinds of Solid Objects
 * 
 */
class Triangle {
public:
    /**
     * @brief Construct a new Triangle object
     * 
     * @param vertex1 The first Vertex of the Triangle
     * @param vertex2 The second Vertex of the Triangle
     * @param vertex3 The third Vertex of the Triangle
     */
    Triangle(Vertex *vertex1, Vertex *vertex2, Vertex *vertex3) {
        v1 = new Vertex(vertex1);
        v2 = new Vertex(vertex2);
        v3 = new Vertex(vertex3);
    };

    /**
     * @brief Construct a new Triangle object
     * 
     * @param triangle The Triangle Object to clone
     */
    Triangle(Triangle *triangle){
        v1 = triangle->v1;
        v2 = triangle->v2;
        v3 = triangle->v3;
    }
    /**
     * @brief Construct a new Triangle object
     * 
     */
    Triangle(){
        v1 = new Vertex();
        v2 = new Vertex();
        v3 = new Vertex();
    }
    
    Vertex v1;
    Vertex v2;
    Vertex v3;
};


#endif //PHASE3_TRIANGLE_H
