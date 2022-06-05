/**
 * @file SpotLight.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe do tipo de iluminacao SpotLight
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Light.h"

/**
 * @brief Classe do tipo de iluminacao SpotLight
 * 
 */
class SpotLight : public Light {
public:
    float pointX, pointY, pointZ;
    float dirX, dirY, dirZ;
    float angle;
    /**
     * @brief Constroi um novo objeto SpotLight
     * 
     */
    SpotLight();
    /**
     * @brief Constroi um novo objeto SpotLight
     * 
     * @param px 
     * @param py 
     * @param pz 
     * @param dx 
     * @param dy 
     * @param dz 
     * @param ang 
     */
    SpotLight(float px, float py, float pz, float dx, float dy, float dz, float ang);
    /**
     * @brief Aplica a iluminao à cena da janela do programa
     * 
     */
    void applyLight();
};