/**
 * @file Rotation.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe de transformacao Rotacao
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
 * @brief Esta classe representa a transformacao de rotacao
 * 
 */
class Rotation : public Transform {
public:    
    double degrees;
    float axisX;
    float axisY;
    float axisZ;
    float time;
    int t_before;
    int cc;
    int type;

    /**
     * @brief Constroi um novo objeto de rotacao
     * 
     * @param r Um objeto Rotacao
     */
    Rotation(const Rotation& r);

    /**
     * @brief Constroi um novo objeto de rotacao
     * 
     * @param degreesG Os graus do angulo no qual seve ser efetuada a rotação
     * @param axisXG O quanto deve rodar segundo o eixo do x
     * @param axisYG O quanto deve rodar segundo o eixo do y
     * @param axisZG O quanto deve rodar segundo o eixo do z
     */
    Rotation(double degreesG, float axisXG, float axisYG, float axisZG);

    /**
     * @brief Constroi um novo objeto de rotacao
     * 
     * @param timeG O tempo que demora a realizar a rotacao
     * @param ccG 
     * @param axisXG O quanto deve rodar segundo o eixo do x
     * @param axisYG O quanto deve rodar segundo o eixo do y
     * @param axisZG O quanto deve rodar segundo o eixo do z
     */
    Rotation(double timeG, int ccG ,float axisXG, float axisYG, float axisZG);
    /**
     * @brief Funcao que aplica a transformacao a um vetor de coordenadas
     * 
     * @return std::vector<float> Um vetor com as coordenadas dos pontos apos a rotacao
     */
    std::vector<float> applyTransform();

};