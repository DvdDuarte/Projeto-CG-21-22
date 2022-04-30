//
// Created by ema on 30/04/22.
//
#include <GL/glew.h>
#ifndef PROJETO_CG_21_22_VBO_H
#define PROJETO_CG_21_22_VBO_H
#endif
class vbo {
public:
    /*vbo(GLuint vertices2) {
        vertices = vertice2;
    }*/
    vbo () {
        vertices=0;
        indexB=0;
        indexC=0;
    }
    vbo (vbo *v) {
        vertices = v->vertices;
        indexB = v->indexB;
        indexC = v->indexC;
    }


    vbo (GLuint v,unsigned int z, unsigned int z2){
        vertices=v;
        indexB = (GLint)z;
        indexC= (GLint) z2;

    }


    GLuint vertices;
    unsigned int indexB;
    unsigned int indexC;

};



