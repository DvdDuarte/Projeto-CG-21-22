#pragma once

#include <iostream>
#include "tinyxml2.h"
#include "../Group.h"
#include "../Figure.h"
#include "../Lights/Light.h"
#include <string>
#include <vector>
#include <memory>

using namespace tinyxml2;
using namespace std;

class xmlContent {
    public:
        xmlContent();
        xmlContent(char* st);
        xmlContent(string st);
        Group parseGroup(XMLElement * group);
        vector<Group> parse();
        unordered_set<std::string> getModels();
        void parseLight(XMLElement * light);
        vector<shared_ptr<Light>> getLights();
        void parseColor(Point3D colors[],float& shininess,XMLElement * model);
        void loadTexture(std::string s);
    private:
        string filename;
        vector<Group> groups;
        vector<shared_ptr<Light>> lights;
        unordered_map<string,int> textures;

};