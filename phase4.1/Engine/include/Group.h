#pragma once
#include <cstdlib>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Transformations/Transform.h"
#include "Transformations/Translation.h"
#include "Transformations/Rotation.h"
#include "Transformations/Scale.h"
#include "Figure.h"
#include <math.h>

using namespace std;

class Group {
public:
    vector<std::shared_ptr<Transform>> transformations;
    unordered_map<string,Figure> models;
    vector<Group> nestedGroups;
    bool isDrawn = false;
    float actualMatrix[16];

    Group();
    Group(const Group& g);

    void addTransform(shared_ptr<Transform> t);

    void addFile(string filename,Point3D * colors, float shininess, int texture);

    void addGroup(Group group);

    std::unordered_set<string> getModels();

    void updateFigures(vector<float> trans);
};