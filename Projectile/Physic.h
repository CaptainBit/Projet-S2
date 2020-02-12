//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_PHYSIC_H
#define PROJET_PHYSIC_H

#include "../Coord.h"
#include <math.h>

#define G 9.81

class Parabole{
public:
    Parabole(Coord p_coord, float p_angle, float p_force){
        initialVelocity = p_force;
        angle = p_angle * (M_PI/180);
        initialCoord = p_coord;
    }

    Coord displacement(float t){
        float x = (initialVelocity * t * cos(angle)) + initialCoord.x;
        float y = (initialVelocity * t * sin(angle)) - (0.5 * t * t * G)  + initialCoord.y;
        return Coord(x,y);
    }

private:
    float initialVelocity;
    float angle;
    Coord initialCoord;

};


#endif //PROJET_PHYSIC_H

