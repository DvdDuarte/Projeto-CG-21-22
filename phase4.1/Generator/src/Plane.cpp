#include "../include/Plane.h"
#include "../../Utils/Point3D.h"
#include "../include/Model.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Plane::Plane() {
    side=5;
}
Plane::Plane(int sideG) {
    side=sideG;
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
    float delta=side_f/div_f;
    float x=side/2.0;
    float z=side/2.0;
    //falta verificar textures
    for(int i=0;i<divisions;i++){
        for (int j = 0; j < divisions; j++){

            topRight=Point3D(-x+(delta*(j+1)),0,-z+(delta*i),0);vertixes.push_back(topRight);
            texCoords.push_back(make_pair<float,float>(1,1));

            topLeft=Point3D(-x+(delta*j),0,-z+(delta*i),1);vertixes.push_back(topLeft);
            texCoords.push_back(make_pair<float,float>(0,1));
            
            bottomLeft=Point3D(-x+(delta*j),0,-z+(delta*i+1),2);vertixes.push_back(bottomLeft);
            texCoords.push_back(make_pair<float,float>(0,0));
            
            bottomRight=Point3D(-x+(delta*(j+1)),0,-z+(delta*i+1),3);vertixes.push_back(bottomRight);
            texCoords.push_back(make_pair<float,float>(1,0));
            
            t1=Triangle(topRight.index,topLeft.index,bottomLeft.index);faces.push_back(t1);
            t2=Triangle(topRight.index,bottomLeft.index,bottomRight.index);faces.push_back(t2);
            for(int i = 0; i < 4; i++) {
                auto normal=Point3D(0,1,0);
                normals.push_back(normal);
            }
        }
        
    }








    /*
    float x=side/2.0;
    float z=side/2.0;
    topRight=Point3D(x,0,-z,0);vertixes.push_back(topRight);
    texCoords.push_back(make_pair<float,float>(1,1));
    topLeft=Point3D(-x,0,-z,1);vertixes.push_back(topLeft);
    texCoords.push_back(make_pair<float,float>(0,1));
    bottomLeft=Point3D(-x,0,z,2);vertixes.push_back(bottomLeft);
    texCoords.push_back(make_pair<float,float>(0,0));
    bottomRight=Point3D(x,0,z,3);vertixes.push_back(bottomRight);
    texCoords.push_back(make_pair<float,float>(1,0));
    t1=Triangle(topRight.index,topLeft.index,bottomLeft.index);faces.push_back(t1);
    t2=Triangle(topRight.index,bottomLeft.index,bottomRight.index);faces.push_back(t2);
    for(int i = 0; i < 4; i++) {
        auto normal=Point3D(0,1,0);
        normals.push_back(normal);
    }
*/
    float radius = sqrt(x*x + z*z);
    
    return std::make_shared<Model>(vertixes,faces,normals,texCoords,radius);
}