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

/**
 * @brief Classe do modelo Torus
 * 
 */
class Torus {
private:
    int widenessRadius,thicknessRadius,nRings,nSides,index;
    std::vector<Point3D> vertexes;
    std::vector<Triangle> faces;
    std::map<std::pair<int,int>,Point3D> points;
    std::vector<Point3D> normals;
    std::vector<std::pair<float,float>> texCoords;
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
     * @return std::shared_ptr<Model> 
     */
    std::shared_ptr<Model> generate();
};