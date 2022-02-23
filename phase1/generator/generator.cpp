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