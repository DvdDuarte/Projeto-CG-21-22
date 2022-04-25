/**
 * @file generator.cpp
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File where the generator function is defined
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "generator.h"
#include "Patch.h"
int main(int argc, char *argv[]) {

    string model = argv[1];
    string filename = "build/";

    if(model == "sphere") {
        filename += argv[5];
        createSphere(atof(argv[2]), atof(argv[3]), atof(argv[4]), filename);
    }
    else if(model == "box"){
        filename += argv[4];
        createBox(atof(argv[2]), atof(argv[3]), filename);
    }
    else if(model == "cone"){
        filename += argv[6];
        createCone(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), filename);
    }
    else if(model == "plane"){
        filename += argv[4];
        createPlane(atof(argv[2]), atoi(argv[3]), filename);
    } else if(model == "ring"){
        //filename += argv[4];
    }
    else if (model=="bezier"){
        createBezier(atoi(argv[2]),argv[3],argv[4]); //nivel de tesselacao,ficheiro dos control points, filename do ficheiro para triangulos
    }
    else perror("No Valid Input!");


    return 0;
}