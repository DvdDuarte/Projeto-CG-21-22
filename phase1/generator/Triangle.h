#ifndef PHASE1_TRIANGLE_H
#define PHASE1_TRIANGLE_H

#include "Vertex.h"

class Triangle {
public:
    Triangle(Vertex *vertex1, Vertex *vertex2, Vertex *vertex3) {
        v1 = new Vertex(vertex1);
        v2 = new Vertex(vertex2);
        v3 = new Vertex(vertex3);
    };

    Triangle(Triangle *triangle){
        v1 = triangle->v1;
        v2 = triangle->v2;
        v3 = triangle->v3;
    }

    Triangle(){
        v1 = new Vertex();
        v2 = new Vertex();
        v3 = new Vertex();
    }

    Vertex v1;
    Vertex v2;
    Vertex v3;
};


#endif //PHASE1_TRIANGLE_H
