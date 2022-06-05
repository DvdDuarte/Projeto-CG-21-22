/**
 * @file PointLight.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do tipo de iluminacao PointLight
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Light.h"

/**
 * @brief Classe do tipo de iluminacao PointLight
 * 
 */
class PointLight : public Light {
public:
    float pointX, pointY, pointZ;
    /**
     * @brief Constroi um novo objeto PointLight
     * 
     */
    PointLight();
    /**
     * @brief Constroi um novo objeto PointLight
     * 
     * @param x O quanto a iluminacao se vai propagar no eixo do x
     * @param y O quanto a iluminacao se vai propagar no eixo do y
     * @param z O quanto a iluminacao se vai propagar no eixo do x
     */
    PointLight(float x, float y, float z);
    /**
     * @brief Aplica a iluminao à cena da janela do programa
     * 
     */
    void applyLight();
};