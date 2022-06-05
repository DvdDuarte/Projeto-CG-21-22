/**
 * @file Cone.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do modelo Cone
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Triangle.h"
#include <vector>
#include "../../Utils/Point3D.h"
#include "Model.h"
#include <string>
#include <map>
#include <memory>

using namespace std;

/**
 * @brief Classe do modelo Cone
 * 
 */
class Cone{
public:
    /**
     * @brief Construct a new Cone object
     * 
     */
    Cone();
    /**
     * @brief Construct a new Cone object
     * 
     * @param radius 
     * @param heightG 
     * @param nSlicesG 
     * @param nStacksG 
     */
    Cone(int radius,int heightG,int nSlicesG,int nStacksG);
    /**
     * @brief 
     * 
     * @return shared_ptr<Model> 
     */
    shared_ptr<Model> generate();
private:
    int radiusBase,height,nStacks,nSlices;
    vector<Triangle> faces;
    map<pair<int,int>,Point3D> points;
    vector<Point3D> vertexes;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
    /**
     * @brief 
     * 
     * @param stack 
     */
    void computeNormals(int stack);
    /**
     * @brief 
     * 
     * @param index 
     */
    void addBase(int index);
    /**
     * @brief 
     * 
     * @param slice 
     * @param stack 
     * @param not_last 
     */
    void addTopSlice(int slice,int stack,int not_last);
    /**
     * @brief 
     * 
     * @param slice 
     * @param stack 
     * @param not_last 
     */
    void addCircleSlice(int slice,int stack,int not_last);
    /**
     * @brief 
     * 
     * @param slice 
     * @param stack 
     */
    void addSquareSlice(int slice,int stack);
};