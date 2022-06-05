/**
 * @file Triangle.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do Triangulo
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../Utils/Point3D.h"
#include <memory>

/**
 * @brief Classe do Triangulo
 * 
 */
class Triangle{
public:
    int indexP1,indexP2,indexP3;
    /**
     * @brief Constroi um novo objeto Triangulo
     * 
     */
    Triangle();
    /**
     * @brief Constroi um novo objeto Triangulo
     * 
     * @param indexP1 Indice do primeiro ponto do triangulo
     * @param indexP2 Indice do segundo ponto do triangulo
     * @param indexP3 Indice do terceiro ponto do triangulo
     */
    Triangle(int indexP1, int indexP2, int indexP3);
};