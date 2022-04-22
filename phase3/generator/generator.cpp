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

int main(int argc, char *argv[]) {

    string filename = "build/";
    
    if(argc==3){
        filename += argv[3];
        generate_triangles(argv[1],atoi(argv[2]),filename);        
    
    }
    else perror("No Valid Input!");


    return 0;
}