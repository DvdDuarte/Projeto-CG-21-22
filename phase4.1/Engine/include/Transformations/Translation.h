/**
 * @file Translation.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe de transformacao Translacao
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Transform.h"
#include "../../../Utils/Point3D.h"
#include <vector>

/**
 * @brief Classe que representa a transformacao de Translacao
 * 
 */
class Translation : public Transform {
public:
    float x;
    float y;
    float z;
    double time;
    float currentPos=0;
    int t_before=0;
    static bool showCurves;
    std::vector<Point3D> curve_points;
    int type;
    /**
     * @brief Constroi um novo objeto de Translacao
     * 
     */
    Translation();
    /**
     * @brief Constroi um novo objeto de Translacao
     * 
     * @param t 
     */
    Translation(const Translation& t);
    /**
     * @brief Constroi um novo objeto de Translacao
     * 
     * @param xG O valor a ser translacionado no x
     * @param yG O valor a ser translacionado no y
     * @param zG O valor a ser translacionado no z
     */
    Translation(float xG, float yG, float zG);
    /**
     * @brief Constroi um novo objeto de Translacao
     * 
     * @param timeG O tempo que demora a realizar a translacao
     * @param curve_pointsG Um vetor com os pontos de uma curva pela qual deve realizar a translacao
     */
    Translation(double timeG,std::vector<Point3D> curve_pointsG);
    /**
     * @brief Funcao que aplica a transformacao a um vetor de coordenadas
     * 
     * @return std::vector<float> Um vetor com as coordenadas dos pontos apos a translacao
     */
    std::vector<float> applyTransform();
private:
    /**
     * @brief 
     * 
     * @param m 
     * @param v 
     * @param res 
     */
    void multMatrixVector(float *m, Point3D *v, Point3D *res);
    /**
     * @brief Funcao que retorna o objeto da curva de CatmullRom
     * 
     * @param t 
     * @param p0 
     * @param p1 
     * @param p2 
     * @param p3 
     * @param pos 
     * @param deriv 
     */
    void getCatmullRomPoint(float t, Point3D p0, Point3D p1, Point3D p2, Point3D p3, Point3D& pos, Point3D& deriv);
    /**
     * @brief Funcao que retorna o objeto da curva de CatmullRom
     * 
     * @param gt 
     * @param pos 
     * @param deriv 
     */
    void getGlobalCatmullRomPoint(float gt, Point3D& pos, Point3D& deriv);
    /**
     * @brief Funcao que desenha a curva de CatmullRom
     * 
     */
    void drawCatmullRomCurve();
};