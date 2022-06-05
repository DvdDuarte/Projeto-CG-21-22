/**
 * @file xmlParser.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a classe xmlContent
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include "tinyxml2.h"
#include "../Group.h"
#include "../Figure.h"
#include "../Lights/Light.h"
#include <string>
#include <vector>
#include <memory>
#include "../../../Utils/Point3D.h"
//./../../Utils/Point3D.h"
using namespace tinyxml2;
using namespace std;

/**
 * @brief Classe xmlContent, esta classe realiza o parsing dos ficherios XML
 * 
 */
class xmlContent {
    public:
        /**
         * @brief Constroi um novo objeto xmlContent 
         * 
         */
        xmlContent();
        /**
         * @brief Constroi um novo objeto xmlContent
         * 
         * @param st 
         */
        xmlContent(char* st);
        /**
         * @brief Constroi um novo objeto xmlContent
         * 
         * @param st 
         */
        xmlContent(string st);
        /**
         * @brief Realiza o parsing de um grupo do ficheiro xml
         * 
         * @param group 
         * @return Group 
         */
        Group parseGroup(XMLElement * group);
        /**
         * @brief Realiza o parsing de um ficheiro xml
         * 
         * @return vector<Group> Os grupos que se encontram no ficheiro xml
         */
        vector<Group> parse();
        /**
         * @brief Retorna os Modelos que se encontram mencionados no ficheiro xml
         * 
         * @return unordered_set<string> Os nomes dos modelos mencionados no ficheiro xml
         */
        unordered_set<string> getModels();
        /**
         * @brief Realiza o parsing da iluminacao
         * 
         * @param light O parametro light do ficheiro xml a realizar o parsing
         */
        void parseLight(XMLElement * light);
        /**
         * @brief Retorna os objetos de iluminacao que se encontram menciondados no fichiero xml
         * 
         * @return vector<shared_ptr<Light>> Um array que contem a iluminacao
         */
        vector<shared_ptr<Light>> getLights();
        //rever ordem
        /**
         * @brief Retorna a configuracao da camara que se encontra no ficheiro xml
         * 
         * @return vector<Point3D>  Um array de pontos da configuração da camara
         */
        vector<Point3D> getCamera();
        /**
         * @brief Reliza o parsing das cores
         * 
         * @param colors Um array de pontos de um modelo a colorir
         * @param shininess O brilho de um modelo
         * @param model O parametro model do ficheiro xml para realizar o parsing da cor
         */
        void parseColor(Point3D colors[],float& shininess,XMLElement * model);
        /**
         * @brief Realiza o loading de uma textura
         * 
         * @param s O nome da textura para realizar o loading
         */
        void loadTexture(string s);
        /**
         * @brief Realiza o parsing do parametro camara do ficheiro xml
         * 
         * @param camera O parametro camara do ficheiro xml
         */
        void parseCamera(XMLElement * camera);
    private:
        string filename;
        vector<Group> groups;
        vector<shared_ptr<Light>> lights;
        vector<Point3D>camera;
        unordered_map<string,int> textures;


};