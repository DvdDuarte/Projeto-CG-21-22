#include "../include/Triangle.h"
#include "../include/Model.h"
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

Model::Model(vector<Point3D> verticesG,vector<Triangle> facesG,vector<Point3D> normals,vector<pair<float,float>> texCoords, float rad) {
    
    nVertices=verticesG.size();
    nTriangulos=facesG.size();
    verticesT=verticesG;
    facesT=facesG;
    normalsT=normals;
    texCoordsT=texCoords;
    radius = rad;
}

void Model::saveToFile(string filename) {
    ofstream fout("../Engine/models/" + filename, ios::out); 


    fout<< to_string(nVertices) << " " << to_string(nTriangulos) << " " << to_string(radius) << "\n";
    for (int i=0;i<nVertices;i++) {
        fout << to_string(verticesT[i].x) << " " << to_string(verticesT[i].y) << " " << to_string(verticesT[i].z) << "\n"; 

    }
    for (int j=0;j<nTriangulos;j++) {
        fout << to_string(facesT[j].indexP1) << " " << to_string(facesT[j].indexP2) << " " << to_string(facesT[j].indexP3) << "\n"; 

    }
    for (int i=0;i<nVertices;i++) {
        fout << to_string(normalsT[i].x) << " " << to_string(normalsT[i].y) << " " << to_string(normalsT[i].z) << "\n"; 

    }
    for (int i=0;i<nVertices;i++) {
        fout << to_string(texCoordsT[i].first) << " " << to_string(texCoordsT[i].second) << "\n";

    }
}

