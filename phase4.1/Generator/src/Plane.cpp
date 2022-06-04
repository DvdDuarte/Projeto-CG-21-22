#include "../include/Plane.h"
#include "../../Utils/Point3D.h"
#include "../include/Model.h"
#include "../include/colors.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Plane::Plane() {
    side=5;
    divisions = 3;
}
Plane::Plane(int sideG) {
    side=sideG;
    divisions = 3;
}
Plane::Plane(int sideG,int divs) {
    side=sideG;
    divisions=divs;
}
shared_ptr<Model> Plane::generate() {
    vector<Point3D> vertixes;
    vector<Triangle> faces;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
    float side_f=(float)side,div_f=(float)divisions;
    float delta =side_f/div_f;
    float half = side_f / 2;
    float x=side/2.0;
    float z=side/2.0;
    float aux_x1 = 0, aux_z1 = 0, aux_x2 = 0, aux_z2 = 0;
    int i, j, index_counter = 0;

    // cout << BOLD_BLUE << "Divisions: " << RESET << divisions << endl;
    cout << "Antes Ciclo" << endl;
    cout << "Side = " << side << " Divisions = " << divisions << endl;
    cout << "Half = " << half << " Delta = " << delta << endl;
    for(i = 0; -half + (i * delta) < half; i++){
        //cout << "I = " << i << endl;
        for (j = 0; -half + (j * delta) < half; j++){
            //cout << "J = " << j << endl;
            aux_x1 = -half + (i * delta);
            aux_z1 = -half + (j * delta);
            aux_x2 = -half + ((i + 1) * delta);
            aux_z2 = -half + ((j + 1) * delta);

            topRight=Point3D(aux_x1,0,aux_z1,0 + index_counter);vertixes.push_back(topRight);
            texCoords.push_back(make_pair<float,float>(1,1));

            topLeft=Point3D(aux_x1,0,aux_z2,1 + index_counter);vertixes.push_back(topLeft);
            texCoords.push_back(make_pair<float,float>(0,1));
            
            bottomLeft=Point3D(aux_x2,0,aux_z2,2 + index_counter);vertixes.push_back(bottomLeft);
            texCoords.push_back(make_pair<float,float>(0,0));
            
            bottomRight=Point3D(aux_x2,0,aux_z1,3 + index_counter);vertixes.push_back(bottomRight);
            texCoords.push_back(make_pair<float,float>(1,0));
            
            t1=Triangle(topRight.index,topLeft.index,bottomLeft.index);faces.push_back(t1);
            t2=Triangle(topRight.index,bottomLeft.index,bottomRight.index);faces.push_back(t2);
            for(int i = 0; i < 4; i++) {
                auto normal=Point3D(0,1,0);
                normals.push_back(normal);
            } 
            index_counter = index_counter + 4;
            /** Visualizar coordenadas geradas */
            /*
            cout << BOLD_CYAN << "TR: " << RESET << topRight.getCoords() << endl;
            cout << BOLD_CYAN << "TL: " << RESET << topLeft.getCoords() << endl;
            cout << BOLD_CYAN << "BL: " << RESET << bottomLeft.getCoords() << endl;
            cout << BOLD_CYAN << "BR: " << RESET << bottomRight.getCoords() << endl;
            */
            
        }
    }

    float radius = sqrt(x*x + z*z);
    
    return std::make_shared<Model>(vertixes,faces,normals,texCoords,radius);
}

