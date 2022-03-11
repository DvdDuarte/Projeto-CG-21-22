/**
 * @file generator_aux.cpp
 * @author David Duarte (A93253) , Ema Dias (A89518) & Samuel Lira(A94166)
 * @brief File where the auxiliar functions for the generator are defined
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "generator_aux.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
int sizeArray = 100;
Triangle *triangles;
//Vertex * vertices;

void createSphere(float radius, int slices, int stacks, std::string filename) {
    //not sure yet
    int triangle_nmr = 0;
    ofstream file_handler;
    file_handler.open(filename);
    Vertex *v1,*v2,*v3,*v4;
    Triangle *t1,*t2;
    float delta_alfa=M_PI/stacks;
    float delta_beta=M_PI/slices;
    for(int i=0;i<=stacks;i++){
        float beta=(-M_PI/2.0) + i*delta_beta;
        float aux=radius*cos((-M_PI/2.0) + i*delta_beta);
        float y=radius*sin((-M_PI/2.0) + i*delta_beta);
        //vector<int> pt;
        for(int j=0;j<slices;j++){
            triangles = (Triangle *) malloc(2* sizeof(Triangle));
            float x1=radius*cos((-M_PI/2.0) + i*delta_beta)*sin(j*delta_alfa);
            float z1=radius*cos((-M_PI/2.0) + i*delta_beta)*cos(j*delta_alfa);
            float y1=radius*sin((-M_PI/2.0) + i*delta_beta);
            //Vertex *v1,*v2,*v3,*v4;
            v1=new Vertex(x1,y1,z1);
            
            v2=new Vertex(radius*cos((-M_PI/2.0) + (i+1)*delta_beta)*sin(j*delta_alfa),
            radius*sin((-M_PI/2.0) + (i+1)*delta_beta),
            radius*cos((-M_PI/2.0) + (i+1)*delta_beta)*cos(j*delta_alfa));
            
            v3=new Vertex(radius*cos((-M_PI/2.0) + (i+1)*delta_beta)*sin((j+1)*delta_alfa),
            radius*sin((-M_PI/2.0) + (i+1)*delta_beta),
            radius*cos((-M_PI/2.0) + (i+1)*delta_beta)*cos((j+1)*delta_alfa));

            v4=new Vertex(radius*cos((-M_PI/2.0) + i*delta_beta)*sin((j+1)*delta_alfa),
            radius*sin((-M_PI/2.0) + i*delta_beta),
            radius*cos((-M_PI/2.0) + i*delta_beta)*cos((j+1)*delta_alfa));
            //primeiro triang = v1,v2,v3
            t1 = new Triangle(v1,v2,v3);
            //segundo triang= v1,v3,v4
            t2 = new Triangle(v1,v3,v4);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            for(triangle_nmr = 0; triangle_nmr < 2; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
        }
    
    }

    
}

void createBox(float units, float grid, string filename) {
    int triangle_nmr_max = 12 * grid * grid;

    int triangle_nmr = 0;

    float halfx = 0, halfz = 0, halfy = 0, halfx_temp = 0, halfy_temp = 0, halfz_temp = 0;
    float aux_x1=0 ,aux_x2=0, aux_y1=0, aux_y2=0, aux_z1=0, aux_z2=0;

    halfx = halfz = halfy = units / 2;

    Triangle *t1, *t2, *t3, *t4;
    Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8;

    halfx_temp = halfz_temp = halfy_temp =  units / grid;
    //triangles = (Triangle *) malloc(sizeArray * sizeof(Triangle));
    ofstream file_handler;
    file_handler.open(filename);
  //  file_handler << "Number of triangles in the grid: " << triangle_nmr_max << endl;
    cout << "max " << triangle_nmr_max << endl;

    // Faces: Front e Back for x and y
   // aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
       for (int i = 0; -halfx + i * halfx_temp < halfx; i++) {
            for (int j=0; -halfy + j*halfy_temp < halfy; j++) {
                triangles = (Triangle *) malloc(4* sizeof(Triangle));

            aux_x1 = -halfx + ((i) * halfx_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_y1 = -halfy + (j) * halfy_temp;
            aux_y2 = -halfy + (j + 1) * halfy_temp;
            aux_z1 = -halfz; // fixo
            aux_z2 = halfz;  // fixo

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);

            //FRONT
            t1 = new Triangle(v1,v2,v3);
            t2 = new Triangle(v1,v3,v4);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            //BACK
            t3 = new Triangle(v5,v6,v7);
            t4 = new Triangle(v5,v7,v8);
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;

            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
        }
    }

    //Faces : top and bottom x e z
  //  aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
    for (int k=0; -halfz + k* halfz_temp < halfz; k++) {
        for (int i=0; -halfx + i*halfx_temp < halfx; i++) {

            triangles = (Triangle *) malloc(4* sizeof(Triangle));

            aux_x1 = -halfx + ((i) * halfx_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_z1 = -halfz + (k) * halfz_temp;
            aux_z2 = -halfz + (k+ 1) * halfz_temp;
            aux_y1 = -halfy; //y fixo
            aux_y2 = halfy;  //y fixo

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);

            //TOP
            t1 = new Triangle(v4,v3,v7);
            t2 = new Triangle(v3,v8,v7);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            //BOTTOM
            t3 = new Triangle(v2,v1,v6);
            t4 = new Triangle(v5,v2,v6);
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;

            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
        }
    }

    // Faces: right and left for z and y
  //  aux_x1 = 0, aux_x2= 0, aux_y1 = 0, aux_y2 = 0, aux_z1 = 0, aux_z2=0;
    for (int k=0; -halfz + k* halfz_temp < halfz; k++) {
        for (int j = 0; -halfy + j*halfy_temp < halfy; j++) {

            triangles = (Triangle *) malloc(4* sizeof(Triangle));

            aux_z1 = -halfz + ((k) * halfz_temp);
            aux_z2 = -halfz + ((k+ 1) * halfz_temp);
            aux_y1 = -halfy + ((j) * halfy_temp);
            aux_y2 = -halfy + ((j + 1) * halfy_temp);
            aux_x1= -halfx;
            aux_x2 = halfx;

            v1 = new Vertex(aux_x1, aux_y1, aux_z2);
            v2 = new Vertex(aux_x2, aux_y1, aux_z2);
            v3 = new Vertex(aux_x2, aux_y2, aux_z2);
            v4 = new Vertex(aux_x1, aux_y2, aux_z2);
            v5 = new Vertex(aux_x2, aux_y1, aux_z1);
            v6 = new Vertex(aux_x1, aux_y1, aux_z1);
            v7 = new Vertex(aux_x1, aux_y2, aux_z1);
            v8 = new Vertex(aux_x2, aux_y2, aux_z1);

            //RIGHT
            t1 = new Triangle(v2,v5,v3);
            t2 = new Triangle(v5,v8,v3);
            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr+1] = t2;

            //LEFT
            t3= new Triangle(v6,v1,v4);
            t4= new Triangle(v6,v4,v7);
            triangles[triangle_nmr+2] = t3;
            triangles[triangle_nmr+3] = t4;

            triangle_nmr+=4;
            for(triangle_nmr = 0; triangle_nmr < 4; triangle_nmr++) {
                string info = triangleToString(triangles[triangle_nmr]);
                file_handler << info;
            }
            triangle_nmr = 0;
            free(triangles);
        }
    }

   //  free(triangles);
    file_handler.close();
}

void createCone(float radius, float height, float slices, float stacks, string filename){

}

void createPlane(float units, int divisions, std::string filename){

    int triangle_nmr_max = divisions * divisions * 2; // For each slice in the grid generated by the number of divisions we have 2 slices;

   // int sizeArray = 100;
    int triangle_nmr = 0;
    Triangle *t1, *t2;
    float halfx = 0, halfz = 0, halfx_temp = 0, halfz_temp = 0, aux_x1 = 0, aux_z1 = 0, aux_x2 = 0, aux_z2 = 0;
    halfx = halfz = units / 2;
    halfx_temp = halfz_temp = units / divisions;

    Vertex *v1, *v2, *v3, *v4;
    triangles = (Triangle *) malloc(sizeArray * sizeof(Triangle));

    ofstream file_handler;
    file_handler.open(filename);
    //file_handler << "Number of triangles in the grid: " << triangle_nmr_max << endl;

    for (int i = 0; -halfx + i * halfx_temp < halfx; i++) {
        for (int j = 0; -halfz + j * halfz_temp < halfz; j++) {
            aux_x1 = -halfx + (i * halfx_temp);
            aux_z1 = -halfz + (j * halfz_temp);
            aux_x2 = -halfx + ((i + 1) * halfx_temp);
            aux_z2 = -halfz + ((j + 1) * halfz_temp);

            v1 = new Vertex(aux_x1, 0 , aux_z1);
            v2 = new Vertex(aux_x1, 0, aux_z2);
            v3 = new Vertex(aux_x2, 0 , aux_z2);
            v4 = new Vertex(aux_x2, 0 ,aux_z1);

            if(triangle_nmr >= sizeArray) {
                cout << "entrou " << triangle_nmr << endl;
                sizeArray *=2;
                triangles = (Triangle *) realloc(triangles, sizeArray * sizeof(Triangle));     }


            t1 = new Triangle(v1, v2, v3);
            t2 = new Triangle(v3, v4, v1);

            triangles[triangle_nmr] = t1;
            triangles[triangle_nmr + 1] = t2;
            triangle_nmr += 2;
        }
    }

   for(triangle_nmr = 0; triangle_nmr < triangle_nmr_max; triangle_nmr++) {
        string info = triangleToString(triangles[triangle_nmr]);
        file_handler << info;
    }

   // free(triangles);
    file_handler.close();
}

string vertexToString(Vertex v){
    string vertex_info = to_string(v.x) + ";" + to_string(v.y) + ";" + to_string(v.z);
    return vertex_info;
}

string triangleToString(Triangle t){
    Vertex v1 = t.v1;
    Vertex v2 = t.v2;
    Vertex v3 = t.v3;

    string triangle_info = vertexToString(v1) + "," +vertexToString(v2) + "," +vertexToString(v3) + "\n"; // EOT == End Of Triangle
    return triangle_info;
}