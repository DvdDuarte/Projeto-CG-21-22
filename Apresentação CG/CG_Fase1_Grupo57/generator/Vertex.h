/**
 * @file Vertex.h
 * @author David Duarte (A93253) & Ema Dias (A89518)
 * @brief File with the class Vertex and it's constructors
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHASE1_VERTEX_H
#define PHASE1_VERTEX_H

/**
 * @brief class Vertex used to define the Triangle Object
 * 
 */
class Vertex {
public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param x_axis The xx coordinate
     * @param y_axis The yy coordinate
     * @param z_axis The zz coordinate
     */
    Vertex(float x_axis, float y_axis, float z_axis){
        x = x_axis;
        y = y_axis;
        z = z_axis;
    }

    /**
     * @brief Construct a new Vertex object
     * 
     * @param v The Vertex Object to clone
     */
    Vertex(Vertex *v){
        x = v->x;
        y = v->y;
        z = v->z;
    }
    /**
     * @brief Construct a new Vertex object
     * 
     */
    Vertex(){
        x = 0; y = 0; z = 0;
    }
    float x;
    float y;
    float z;
};

#endif //PHASE1_VERTEX_H
