#include "generator.h"

int main(int argc, char *argv[]) {

    std::string model = argv[1];

    if(model == "sphere") createSphere(atof(argv[2]), atof(argv[3]), atof(argv[4]), argv[5]);
    else if(model == "box") createBox(atof(argv[2]), atof(argv[3]), argv[4]);
    else if(model == "cone") createCone(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), argv[6]);
    else if(model == "plane") createPlane(atof(argv[2]), atoi(argv[3]), argv[4]);
    else perror("No Valid Input!");


    return 1;
}
