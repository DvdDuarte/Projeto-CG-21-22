/**
 * @file Figure.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe Figura
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include "../../Utils/Point3D.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/**
 * @brief Classe que representa uma Figura
 * 
 */
class Figure {
public:
    float diffR, diffG, diffB;
    float specR, specG, specB;
    float emissR, emissG, emissB;
    float ambR, ambG, ambB;
    float shininess;
    float radius;
    Point3D centerPoint;
    GLuint texID;
    std::string filename;
    /**
     * @brief Constroi um novo objeto Figura
     * 
     */
    Figure();
    /**
     * @brief Constroi um novo objeto Figura
     * 
     * @param fig Um objeto figura
     */
    Figure(const Figure& fig);
    /**
     * @brief Constroi um novo objeto Figura
     * 
     * @param textureG A textura da figura
     * @param diff A luz difusa da figura
     * @param spec A luz especular da figura
     * @param shin O brilho da figura
     * @param amb A luz ambiente da figura
     * @param emiss A luz emissiva da figura
     * @param filenameG O nome do ficheiro da figura
     * @param radiusG O raio da figura
     */
    Figure(int textureG, Point3D diff,Point3D spec,float shin,Point3D amb,Point3D emiss,std::string filenameG,float radiusG);
    /**
     * @brief Funcao que aplica todos os parametros de uma figura
     * 
     */
    void apply();
    /**
     * @brief Funcao que realiza o reset dos parametros de uma figura
     * 
     */
    void reset();
};