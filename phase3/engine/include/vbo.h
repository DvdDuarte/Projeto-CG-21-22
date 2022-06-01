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
        index=0;

    }
    vbo (vbo *v) {
        vertices = v->vertices;
        index = v->index;
    }


    vbo (GLuint v,unsigned int z){
        vertices=v;
        index = (GLint)z;

    }


    GLuint vertices;
    GLuint index;

    void set(GLint v){
        vertices=v;
        cout << "vertices " << vertices << endl;
    }


};



