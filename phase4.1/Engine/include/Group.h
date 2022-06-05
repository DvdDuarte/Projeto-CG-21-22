/**
 * @file Group.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe Group
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstdlib>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Transformations/Transform.h"
#include "Transformations/Translation.h"
#include "Transformations/Rotation.h"
#include "Transformations/Scale.h"
#include "Figure.h"
#include <math.h>

using namespace std;

/**
 * @brief Classe que representa um  grupo
 * 
 */
class Group {
public:
    vector<std::shared_ptr<Transform>> transformations;
    unordered_map<string,Figure> models;
    vector<Group> nestedGroups;
    bool isDrawn = false;
    float actualMatrix[16];

    /**
     * @brief Constroi um novo objeto Grupo
     * 
     */
    Group();
    /**
     * @brief Constroi um novo objeto Grupo
     * 
     * @param g Um objeto Grupo
     */
    Group(const Group& g);

    /**
     * @brief Funcao que adiciona uma transformacao ao grupo
     * 
     * @param t Transformacao a ser aplicada ao grupo
     */
    void addTransform(shared_ptr<Transform> t);

    /**
     * @brief Funcao que adiciona um ficheiro ao grupo
     * 
     * @param filename O nome do ficheiro
     * @param colors Os pontos coloridos
     * @param shininess O brilho 
     * @param texture A textura
     */
    void addFile(string filename,Point3D * colors, float shininess, int texture);

    /**
     * @brief Funcao que adiciona um Grupo ao Grupo
     * 
     * @param group Grupo a adicionar
     */
    void addGroup(Group group);

    /**
     * @brief Funcao que retorna os objetos Models
     * 
     * @return unordered_set<string> 
     */
    unordered_set<string> getModels();
    
    /**
     * @brief Funcao que atualiza as figuras
     * 
     * @param trans A transformacao realizada as figuras
     */
    void updateFigures(vector<float> trans);
};