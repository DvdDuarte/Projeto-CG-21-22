#ifndef PHASE1_VERTEX_H
#define PHASE1_VERTEX_H


class Vertex {
public:
    Vertex(float x_axis, float y_axis, float z_axis){
        x = x_axis;
        y = y_axis;
        z = z_axis;
    }
    Vertex(Vertex *v){
        x = v->x;
        y = v->y;
        z = v->z;
    }
    Vertex(){
        x = 0; y = 0; z = 0;
    }
    float x;
    float y;
    float z;
};

#endif //PHASE1_VERTEX_H
