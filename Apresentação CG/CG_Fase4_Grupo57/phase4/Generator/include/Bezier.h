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

using namespace std;
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
    shared_ptr<Model> generate();
    float maxDistance;
private:
    int vertical_tesselation;
    float vertical_tesselation_inc;
    int horizontal_tesselation;
    float horizontal_tesselation_inc;
    vector<vector<Point3D>> bezier_matrix;
    string patch_file;
    vector<Patch> patches;
    vector<Point3D> normals;
    vector<pair<float,float>> texCoords;
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
    void computeNormal(vector<vector<Point3D>> preCalculatedMatrix, float u, float v, vector<vector<Point3D>> u_matrix, vector<vector<Point3D>> v_matrix);
    /**
     * @brief Funcao que calcula os pontos de Bezier
     * 
     * @param preCalculatedMatrix A matriz pre-calculada
     * @param indexPoint O indice do ponto
     * @param vertixes Os vertices
     * @param triangs Os triangulos
     */
    void calculatePoints(vector<vector<Point3D>> preCalculatedMatrix,int& indexPoint,vector<Point3D>& vertixes,vector<Triangle>& triangs);
    /**
     * @brief Funcao que calcula um ponto de Bezier
     * 
     * @param preCalculatedMatrix A matriz pre-calculada
     * @param vertical_level O nivel vertical
     * @param horizontal_level O nivel horizontal
     * @return Point3D O ponto Calculado
     */
    Point3D calculatePoint(vector<vector<Point3D>> preCalculatedMatrix,int vertical_level,int horizontal_level);
    /**
     * @brief Funcao que multiplica matrizes
     * 
     * @param m1 A primeira matriz a multiplicar
     * @param m2 A segunda matriz a multiplicar
     * @return vector<std::vector<Point3D>> 
     */
    vector<vector<Point3D>> multiplyMatrix(vector<vector<Point3D>> m1, vector<vector<Point3D>> m2);
    /**
     * @brief Funcao que calcula a distancia de um ponto
     * 
     * @param x A coordenada x do ponto
     * @param y A coordenada y do ponto
     * @param z A coordenada z do ponto
     * @return float O valor da distancia
     */
    float distance(float x,float y,float z);
};