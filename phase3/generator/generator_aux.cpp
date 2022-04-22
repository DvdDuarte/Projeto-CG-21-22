#include "generator_aux.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "Patch.h"

int sizeArray = 100;
Triangle *triangles;
//Vertex * vertices;

//rever 
#define POINT_COUNT 5
// Points that make up the loop for catmull-rom interpolation
float p[POINT_COUNT][3] = {{-1,-1,0},{-1,1,0},{1,1,0},{0,0,0},{1,-1,0}};

void multMatrixVector(float *m, float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j * 4 + k];
		}
	}

}


void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv) {

	// catmull-rom matrix
	float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
						{ 1.0f, -2.5f,  2.0f, -0.5f},
						{-0.5f,  0.0f,  0.5f,  0.0f},
						{ 0.0f,  1.0f,  0.0f,  0.0f}};
    float T[4]={(t*t*t),(t*t),t,1};
    float T_linha[4]={(3*t*t),2*t,1,0};

    //for each component x,y,z
    for(int i=0;i<3;i++){
        // Compute A = M * P
        float res[4];
        float paux[4];
        paux[0]=p0[i], paux[1]=p1[i], paux[2]=p2[i],paux[3]=p3[i];

        multMatrixVector((float *)m,paux,res);
        // Compute pos = T * A
        pos[i]=T[0]*res[0]+T[1]*res[1]+T[2]*res[2]+T[3]*res[3];
        // compute deriv = T' * A
        deriv[i]=T_linha[0]*res[0]+T_linha[1]*res[1]+T_linha[2]*res[2]+T_linha[3]*res[3];

    }

}


// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv) {

	float t = gt * POINT_COUNT; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
    //?
	int indices[4]; 
	indices[0] = (index + POINT_COUNT-1)%POINT_COUNT;	
	indices[1] = (indices[0]+1)%POINT_COUNT;
	indices[2] = (indices[1]+1)%POINT_COUNT; 
	indices[3] = (indices[2]+1)%POINT_COUNT;
    //?
	getCatmullRomPoint(t, p[indices[0]], p[indices[1]], p[indices[2]], p[indices[3]], pos, deriv);
}

void read_patch(std::string filename,Patch*p){
    ifstream file_handler;
    file_handler.open(filename);
    std::string str;
   // char * s; 
    int n_patches,n_control_points;
    int *indices;//divided in n_patches segments of num_of_ind_by_patch(16) ints
    int num_of_ind_by_patch=16;
    int num_of_floats_per_point=3;
    float * control_points;

    //number of patches
    getline(file_handler,str);
    
    n_patches=std::stoi(str);
    str.erase(0,str.length());//limpar string
    //indices
    indices=new int[n_patches*num_of_ind_by_patch];
    for(int i=0;i<n_patches;i++){
        getline(file_handler,str);
        
        vector<string> words{};
        size_t pos;
        string delimiter=",";
        
        while ((pos = str.find(delimiter)) != string::npos) {
            words.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
        }
        for(string s:words){
            *indices=std::stoi(s);
            indices++;
        }
        
    }
    str.erase(0,str.length());//limpar string

    //num of control points
    getline(file_handler,str);
    n_control_points=std::stoi(str);
    str.erase(0,str.length());//limpar string
    
    //control points
    control_points=new float[n_control_points*num_of_floats_per_point];
    for(int i=0;i<n_control_points;i++){
        getline(file_handler,str);
        
        vector<string> words{};
        size_t pos;
        string delimiter=",";
        
        while ((pos = str.find(delimiter)) != string::npos) {
            words.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
        }
        for(string s:words){
            *control_points=std::stof(s);
            control_points++;
        }        
    }
    printf("num of patches: %d \nnum of control points: %d",n_patches,n_control_points);
    *p=Patch(n_patches,indices,n_control_points,control_points);
    file_handler.close();
}

//generates the triangles from a given patch
void generate_triangles(std::string patch,int t,std::string filename){
    Patch * p;
    read_patch(patch,p);
     ofstream file_handler;
    file_handler.open(filename);
    


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