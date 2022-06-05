/**
 * @file Box.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do modelo Box
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Triangle.h"
#include "../../Utils/Point3D.h"
#include "Model.h"
#include <vector>
#include <string>
#include <tuple>
#include <map>

using namespace std;
/**
 * @brief Classe do modelo Box
 * 
 */
class Box{
public:
    /**
     * @brief Construct a new Box object
     * 
     */
    Box();
    /**
     * @brief Construct a new Box object
     * 
     * @param widthG 
     * @param depthG 
     * @param heightG 
     * @param nDivisionsG 
     */
    Box(int widthG,int depthG,int heightG,int nDivisionsG);
    /**
     * @brief 
     * 
     * @return shared_ptr<Model> 
     */
    shared_ptr<Model> generate();
private:
    int width,depth,height,nDivisions;
    vector<Triangle> faces;
    vector<Point3D> points;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
    int index;
    /**
     * @brief 
     * 
     * @param top 
     */
    void addYLayer(bool top);
    /**
     * @brief 
     * 
     * @param top 
     */
    void addXLayer(bool top);
    /**
     * @brief 
     * 
     * @param top 
     */
    void addZLayer(bool top);
    /**
     * @brief 
     * 
     * @param top 
     * @param topRight 
     * @param topLeft 
     * @param bellowLeft 
     * @param bellowRight 
     */
    void addSquare(bool top,Point3D topRight,Point3D topLeft,Point3D bellowLeft,Point3D bellowRight);
};