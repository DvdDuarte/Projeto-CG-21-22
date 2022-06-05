/**
 * @file Transform.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe de transformacao
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <memory>
#include <vector>

/**
 * @brief Classe de Transformacao
 * 
 */
class Transform {
public:
     
     static float time_multiplier; // valor pelo qual será multiplicado o tempo de modo a dar fast-forward ou slow-forward (default=1)
     static bool paused; //true quando pausado e false quando não está pausado
     static int retroceder; //1 se for para progredir, -1 se for pra retroceder
     /**
      * @brief Funcao que aplica a transformacao
      * 
      * @return std::vector<float> Um vetor de coordenadas dos pontos apos a transformacao
      */
     virtual std::vector<float> applyTransform()=0;
};