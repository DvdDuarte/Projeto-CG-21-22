/**
 * @file Plane.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do modelo Plano
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Triangle.h"
#include "../../Utils/Point3D.h"
#include "Model.h"
#include <memory>
#include <tuple>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * @brief Classe do modelo Plano
 * 
 */
class Plane{
public:
    /**
     * @brief Construct a new Plane object
     * 
     */
    Plane();
    /**
     * @brief Construct a new Plane object
     * 
     * @param sideG 
     */
    Plane(int sideG);
    /**
     * @brief Construct a new Plane object
     * 
     * @param sideG 
     * @param divs 
     */
    Plane(int sideG,int divs);
    /**
     * @brief 
     * 
     * @return shared_ptr<Model> 
     */
    shared_ptr<Model> generate();
private:
    int divisions;
    int side;
    Triangle t1,t2;
    Point3D topRight,topLeft,bottomLeft,bottomRight;
};