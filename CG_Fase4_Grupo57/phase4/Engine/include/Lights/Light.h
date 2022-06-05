/**
 * @file Light.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe luz
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

/**
 * @brief Classe Light
 * 
 */
class Light {
public:
    /**
     * @brief Aplica a iluminacao a cena da janela do programa
     * 
     */
    virtual void applyLight()=0;
};