/**
 * @file Model.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe Model
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
#include <string>
#include <map>
#include <memory>

using namespace std;
/**
 * @brief Classe do Modelo
 * 
 */
class Model{
public:
    /**
     * @brief Construct a new Model object
     * 
     * @param verticesG 
     * @param faces 
     * @param normals 
     * @param texCoords 
     * @param radius 
     */
    Model(vector<Point3D> verticesG,vector<Triangle> faces,vector<Point3D> normals,vector<pair<float,float>> texCoords,float radius);
    /**
     * @brief 
     * 
     * @param filename 
     */
    void saveToFile(string filename);
private:
    int nVertices,nTriangulos;
    vector<Triangle> facesT;
    vector<Point3D> verticesT;
    vector<Point3D> normalsT;
    vector<pair<float,float>> texCoordsT;
    float radius;
};