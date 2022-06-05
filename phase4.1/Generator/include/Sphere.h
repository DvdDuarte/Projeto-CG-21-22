/**
 * @file Sphere.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do modelo Esfera
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
#include <memory>
#include <map>
#include "../../Utils/Point3D.h"
#include <string>
#include "Triangle.h"
#include "Model.h"

using namespace std;

/**
 * @brief Classe do modelo Esfera
 * 
 */
class Sphere {
private:
    int radius,nStacks,nSlices;
    vector<Point3D> vertexes;
    vector<Triangle> faces;
    map<pair<int,int>,Point3D> points;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
    /**
     * @brief 
     * 
     * @param top 
     * @param slice 
     * @param stack 
     */
    void addTopOrBottomSlice(bool top,int slice,int stack);
    /**
     * @brief 
     * 
     * @param slice 
     * @param stack 
     */
    void addSquareSlice(int slice,int stack);
public:
    /**
     * @brief Construct a new Sphere object
     * 
     */
    Sphere();
    /**
     * @brief Construct a new Sphere object
     * 
     * @param radiusG 
     * @param slicesG 
     * @param stacksG 
     */
    Sphere(int radiusG,int slicesG,int stacksG);
    /**
     * @brief 
     * 
     * @return shared_ptr<Model> 
     */
    shared_ptr<Model> generate();
};