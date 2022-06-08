/**
 * @file VBO.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief Ficheiro que contem a class VBO
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <cstdlib>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#endif

/**
 * @brief Classe VBO é usada para armazenar e ser usada de forma a apresentar os objetos do programa atraves de VBOs
 * 
 */
class VBO {
public:
	GLuint vertixes;
	int vertixCount;
	GLuint indexes;
	int indexCount;
	GLuint normals;
	GLuint texCoords;
	/**
	 * @brief Constroi um novo objeto VBO
	 * 
	 */
    VBO();

	/**
	 * @brief Constroi um novo objeto VBO
	 * 
	 * @param vbo Um objeto VBO
	 */
	VBO(const VBO& vbo);
};