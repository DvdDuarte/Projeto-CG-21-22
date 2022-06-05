/**
 * @file Patch.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe Patch
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
#include "iostream"
/**
 * @brief Classe do Patch
 * 
 */
class Patch {
public:
    /**
     * @brief Construct a new Patch object
     * 
     */
    Patch()=default;
    std::vector<std::vector<Point3D>> points; 
};