/**
 * @file Scale.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe de transformacao Escala
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Transform.h"
#include <vector>

/**
 * @brief Classe que representa a transformacao de escala
 * 
 */
class Scale : public Transform {
public:
    float xScale;
    float yScale;
    float zScale;

    /**
     * @brief Constroi um novo objeto de Escala
     * 
     * @param s Um objeto escala
     */
    Scale(const Scale& s);

    /**
     * @brief Constroi um novo objeto de Escala
     * 
     * @param xG O valor a ser escalado no x
     * @param yG O valor a ser escalado no y
     * @param zG O valor a ser escalado no z
     */
    Scale(float xG, float yG, float zG);

    /**
     * @brief Funcao que aplica a transformacao a um vetor de coordenadas
     * 
     * @return std::vector<float> Um vetor com as coordenadas dos pontos apos a escala
     */
    std::vector<float> applyTransform();

};