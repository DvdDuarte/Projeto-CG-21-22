/**
 * @file Point3D.h
 * @author David Duarte (A93253) & Ema Dias (A89518) & Samuel Lira (A94166)
 * @brief 
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <memory>
#include "colors.h"

class Point3D {
public:
	float x;
	float y;
	float z;
	int index; //serve para identificar que índice o Ponto tem
	Point3D();
	Point3D(float x1,float y1, float z1);
	Point3D(float x1,float y1, float z1,int indexG);
	Point3D(const Point3D& p);
	void zero();
	void normalize();
	Point3D crossProduct(Point3D v2);
	Point3D& operator*(const float& r);
	Point3D& operator+(Point3D& p);
	Point3D& operator*(Point3D& p);
	void operator+=(Point3D& p);
	void operator-=(Point3D& p);
	std::string getCoords();
};
