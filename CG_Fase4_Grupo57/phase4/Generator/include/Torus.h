/**
 * @file Torus.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do modelo Torus
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector>
#include <map>
#include <memory>
#include "../../Utils/Point3D.h"
#include <string>
#include "Triangle.h"
#include "Model.h"

using namespace std;

/**
 * @brief Classe do modelo Torus
 * 
 */
class Torus {
private:
    int widenessRadius,thicknessRadius,nRings,nSides,index;
    vector<Point3D> vertexes;
    vector<Triangle> faces;
    map<pair<int,int>,Point3D> points;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
public:
    /**
     * @brief Construct a new Torus object
     * 
     */
    Torus();
    /**
     * @brief Construct a new Torus object
     * 
     * @param widenessRadiusG 
     * @param thicknessRadiusG 
     * @param ringsG 
     * @param sidesG 
     */
    Torus(int widenessRadiusG,int thicknessRadiusG,int ringsG,int sidesG);
    /**
     * @brief 
     * 
     * @param ring 
     * @param side 
     * @param not_last_ring 
     * @param not_last_side 
     */
    void addSquare(int ring,int side,int not_last_ring,int not_last_side);
    /**
     * @brief 
     * 
     * @param ring 
     * @param ring_angle 
     */
    void constructRing(int ring, float ring_angle);
    /**
     * @brief 
     * 
     * @return shared_ptr<Model> 
     */
    shared_ptr<Model> generate();
};