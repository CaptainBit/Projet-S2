//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_PHYSIC_H
#define PROJET_PHYSIC_H

#include "../Vec2.h"
#include <math.h>

#define G 9.81

class Parabole{
public:
    Parabole(){
        initialVelocity = 0;
        angle = 0;
        initialCoord = Vec2(0,0);
    }

    Parabole(Vec2 p_coord, float p_angle, float p_force){
        initialVelocity = p_force;
        angle = p_angle * (M_PI/180);
        initialCoord = p_coord;
    }

    Vec2 displacement(float t){
        float x = (initialVelocity * t * cos(angle)) + initialCoord.x;
        float y = (initialVelocity * t * sin(angle)) - (0.5 * t * t * G)  + initialCoord.y;
        return Vec2((int)x,(int)y);
    }

    int getY(int x){
        float t = (x - initialCoord.x)/(initialVelocity*cos(angle));
        return (initialVelocity * t * sin(angle)) - (0.5 * t * t * G)  + initialCoord.y;
    }

private:
    float initialVelocity;
    float angle;
    Vec2 initialCoord;

};


#endif //PROJET_PHYSIC_H

