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

/**
 * @brief Classe do modelo Esfera
 * 
 */
class Sphere {
private:
    int radius,nStacks,nSlices;
    std::vector<Point3D> vertexes;
    std::vector<Triangle> faces;
    std::map<std::pair<int,int>,Point3D> points;
    std::vector<Point3D> normals;
    std::vector<std::pair<float,float>> texCoords;
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
     * @return std::shared_ptr<Model> 
     */
    std::shared_ptr<Model> generate();
};