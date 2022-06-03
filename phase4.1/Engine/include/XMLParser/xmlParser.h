#pragma once

#include <iostream>
#include "tinyxml2.h"
#include "../Group.h"
#include "../Figure.h"
#include "../Lights/Light.h"
#include <string>
#include <vector>
#include <memory>
#include "../../../Utils/Point3D.h"
//./../../Utils/Point3D.h"
using namespace tinyxml2;
using namespace std;

class xmlContent {
    public:
        xmlContent();
        xmlContent(char* st);
        xmlContent(string st);
        Group parseGroup(XMLElement * group);
        vector<Group> parse();
        unordered_set<string> getModels();
        void parseLight(XMLElement * light);
        vector<shared_ptr<Light>> getLights();
        //rever ordem
        vector<Point3D> getCamera();
        void parseColor(Point3D colors[],float& shininess,XMLElement * model);
        void loadTexture(string s);
        void parseCamera(XMLElement * camera);
    private:
        string filename;
        vector<Group> groups;
        vector<shared_ptr<Light>> lights;
        vector<Point3D>camera;
        unordered_map<string,int> textures;


};