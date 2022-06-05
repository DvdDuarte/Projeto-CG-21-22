/**
 * @file DirectionalLight.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do tipo de iluminacao DirectionalLight
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Light.h"

/**
 * @brief Classe do tipo de iluminacao DirectionalLight
 * 
 */
class DirectionalLight : public Light {
public:
    float directionX, directionY, directionZ;
    /**
     * @brief Constroi um novo objeto DirectionalLight
     * 
     */
    DirectionalLight();
    /**
     * @brief Constroi um novo objeto DirectionalLight
     * 
     * @param x O quanto a iluminacao se vai propagar no eixo do x
     * @param y O quanto a iluminacao se vai propagar no eixo do y
     * @param z O quanto a iluminacao se vai propagar no eixo do x
     */
    DirectionalLight(float x, float y, float z);
    /**
     * @brief Aplica a iluminao à cena da janela do programa
     * 
     */
    void applyLight();
};