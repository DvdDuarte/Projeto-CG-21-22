#include "../include/Triangle.h"
#include "../include/Model.h"
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

Model::Model(vector<Point3D> vertixesG,vector<Triangle> facesG,vector<Point3D> normals,vector<pair<float,float>> texCoords, float rad) {
    
    nVertices=vertixesG.size();
    nTriangulos=facesG.size();
    vertixesT=vertixesG;
    facesT=facesG;
    normalsT=normals;
    texCoordsT=texCoords;
    radius = rad;
}

void Model::saveToFile(string filename) {
    ofstream fout("../Engine/models/" + filename, ios::out); 
    cout << filename<<endl;

   // cout<<to_string(nVertices) << " " << to_string(nTriangulos) << " " << to_string(radius) <<endl;

    fout<< to_string(nVertices) << " " << to_string(nTriangulos) << " " << to_string(radius) << "\n";
    for (int i=0;i<nVertices;i++) {
        fout << to_string(vertixesT[i].x) << " " << to_string(vertixesT[i].y) << " " << to_string(vertixesT[i].z) << "\n"; 

     //   cout <<to_string(vertixesT[i].x) << " " << to_string(vertixesT[i].y) << " " << to_string(vertixesT[i].z) << endl;
    }
    for (int j=0;j<nTriangulos;j++) {
        fout << to_string(facesT[j].indexP1) << " " << to_string(facesT[j].indexP2) << " " << to_string(facesT[j].indexP3) << "\n"; 

       // cout <<to_string(facesT[j].indexP1) << " " << to_string(facesT[j].indexP2) << " " << to_string(facesT[j].indexP3) << endl;
    }
    for (int i=0;i<nVertices;i++) {
        fout << to_string(normalsT[i].x) << " " << to_string(normalsT[i].y) << " " << to_string(normalsT[i].z) << "\n"; 

       // cout <<  to_string(normalsT[i].x) << " " << to_string(normalsT[i].y) << " " << to_string(normalsT[i].z) << endl;
    }
    for (int i=0;i<nVertices;i++) {
        fout << to_string(texCoordsT[i].first) << " " << to_string(texCoordsT[i].second) << "\n";

    //    cout << to_string(texCoordsT[i].first) << " " << to_string(texCoordsT[i].second) << endl;
    }
}

