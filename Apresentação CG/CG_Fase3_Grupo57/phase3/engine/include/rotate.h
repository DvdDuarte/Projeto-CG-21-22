//
// Created by ema on 29/04/22.
//

#ifndef PROJETO_CG_21_22_ROTATE_H
#define PROJETO_CG_21_22_ROTATE_H



class Rotate {
public:
    Rotate (bool rtime1,float angle1, float axisX, float axisY, float axisZ) {
        rtime=rtime1;

        angle = angle1;

        x = axisX;

        y = axisY;

        z = axisZ;
        if(rtime)
            cout << " rotate: time: " << angle << " x: " << x <<" y: " << y << " z: " << z << endl;
        else
            cout << " rotate: angle: " << angle << " x: " << x <<" y: " << y << " z: " << z << endl;

    }
    Rotate (Rotate *r) {
        rtime=r->rtime;
        x = r->x;
        y= r-> y;
        z = r->z;
        angle = r->angle;
    }
    Rotate () {
        rtime=false;
        x= 0;
        y= 0;
        z = 0;
        angle = 0;
    }
    bool rtime;
    float x;
    float y;
    float z;
    float angle;
};


#endif //PROJETO_CG_21_22_ROTATE_H
