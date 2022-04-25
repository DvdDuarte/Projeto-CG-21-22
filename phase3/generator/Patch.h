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
#include <vector>
/**
 * @brief class Patch used to generate all kinds of Objects
 * 
 */
class Patch {
public:
    /**
     * @brief Construct a new Patch object
     * 
     * @param num_patches Number of patches in the file.
     * @param indices Array of indices of the control points ,every 16 indices relate to each patch.
     * @param num_control_points Number of patches in the file.
     * @param control_points Array of the control points.
     */
    Patch(std::vector<Vertex*> controlPoints) {
        cp = controlPoints;
    };

    Patch(Patch* p){
        cp = p->cp;
    };


    std::vector<Vertex*> cp;
    
};


#endif //PHASE3_PATCH_H

