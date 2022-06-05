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
#include "Triangle.h"
#include <vector>
#include "../../Utils/Point3D.h"
#include <string>
#include <map>
#include <memory>

/**
 * @brief Classe do Modelo
 * 
 */
class Model{
public:
    /**
     * @brief Construct a new Model object
     * 
     * @param vertixesG 
     * @param faces 
     * @param normals 
     * @param texCoords 
     * @param radius 
     */
    Model(std::vector<Point3D> vertixesG,std::vector<Triangle> faces,std::vector<Point3D> normals,std::vector<std::pair<float,float>> texCoords,float radius);
    /**
     * @brief 
     * 
     * @param filename 
     */
    void saveToFile(std::string filename);
private:
    int nVertices,nTriangulos;
    std::vector<Triangle> facesT;
    std::vector<Point3D> vertixesT;
    std::vector<Point3D> normalsT;
    std::vector<std::pair<float,float>> texCoordsT;
    float radius;
};