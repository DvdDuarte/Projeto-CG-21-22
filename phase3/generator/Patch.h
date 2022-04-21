/**
 * @file Patch.h
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File with the class Patch and its constructors
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHASE3_PATCH_H
#define PHASE3_PATCH_H
#include "Vertex.h"
/**
 * @brief class Patch used to generate all kinds of Objects
 * 
 */
class Patch {
public:
    /**
     * @brief Construct a new Patch object
     * 
     * @param num_patches Number of patches in the file.   Triangle
     * @param indices Matrix of indices of the control points (columns) related to each patch (rows).    of the Triangle
     * @param num_control_points Number of patches in the file.       Vertex of the Triangle
     * @param control_points Array of the control points.
     */
    Patch(int nPatches,int **ind,int nControlPoints,float **controlPoints) {
        num_patches=nPatches;
        indices=ind;//por referencia?
        num_control_points=nControlPoints;
        control_points=controlPoints;
    };
    Patch(Patch* p){
        num_patches= p->num_patches;
        indices=p->indices;//por referencia?
        num_control_points=p->num_control_points;
        control_points=p->control_points;
    };
    
    int num_patches;
    int **indices;//inidces of control points by patch
    int num_control_points;
    float **control_points;
    
};


#endif //PHASE3_PATCH_H

