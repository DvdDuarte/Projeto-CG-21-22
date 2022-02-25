/**
 * @file generator.cpp
 * @author David Duarte (A93253) & Ema Dias (A89518)
 * @brief File where the generator function is defined
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "generator.h"

int main(int argc, char *argv[]) {

    std::string model = argv[1];
    //std::string filename = "build/";
    std::string filename;
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
    }
    else perror("No Valid Input!");


    return 0;
}