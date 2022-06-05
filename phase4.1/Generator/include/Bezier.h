/**
 * @file Bezier.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a class do modelo Bezier
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Triangle.h"
#include "../../Utils/Point3D.h"
#include "Model.h"
#include "Patch.h"
#include <memory>
#include <tuple>
#include <vector>
#include <string>
#include <map>

/**
 * @brief Classe do modelo Bezier
 * 
 */
class Bezier{
public:
    /**
     * @brief Constroi um novo objeto Bezier
     * 
     */
    Bezier();
    /**
     * @brief Constroi um novo objeto Bezier
     * 
     * @param patch_file O ficheiro com o patch de bezier
     * @param tesselation_level O nivel de tesselacao
     */
    Bezier(std::string patch_file,int tesselation_level);
    /**
     * @brief Funcao que le o patch de bezier
     * 
     */
    void read_patches();
    /**
     * @brief Fucnao que gera os pontos de bezier
     * 
     * @return std::shared_ptr<Model> O modelo gerado
     */
    std::shared_ptr<Model> generate();
    float maxDistance;
private:
    int vertical_tesselation;
    float vertical_tesselation_inc;
    int horizontal_tesselation;
    float horizontal_tesselation_inc;
    std::vector<std::vector<Point3D>> bezier_matrix;
    std::string patch_file;
    std::vector<Patch> patches;
    std::vector<Point3D> normals;
    std::vector<std::pair<float,float>> texCoords;
    int numPatches;
    
    /**
     * @brief 
     * 
     * @param preCalculatedMatrix 
     * @param u 
     * @param v 
     * @param u_matrix 
     * @param v_matrix 
     */
    void computeNormal(std::vector<std::vector<Point3D>> preCalculatedMatrix, float u, float v, std::vector<std::vector<Point3D>> u_matrix, std::vector<std::vector<Point3D>> v_matrix);
    /**
     * @brief 
     * 
     * @param preCalculatedMatrix 
     * @param indexPoint 
     * @param vertixes 
     * @param triangs 
     */
    void calculatePoints(std::vector<std::vector<Point3D>> preCalculatedMatrix,int& indexPoint,std::vector<Point3D>& vertixes,std::vector<Triangle>& triangs);
    /**
     * @brief 
     * 
     * @param preCalculatedMatrix 
     * @param vertical_level 
     * @param horizontal_level 
     * @return Point3D 
     */
    Point3D calculatePoint(std::vector<std::vector<Point3D>> preCalculatedMatrix,int vertical_level,int horizontal_level);
    /**
     * @brief 
     * 
     * @param m1 
     * @param m2 
     * @return std::vector<std::vector<Point3D>> 
     */
    std::vector<std::vector<Point3D>> multiplyMatrix(std::vector<std::vector<Point3D>> m1, std::vector<std::vector<Point3D>> m2);
    /**
     * @brief 
     * 
     * @param x 
     * @param y 
     * @param z 
     * @return float 
     */
    float distance(float x,float y,float z);
};