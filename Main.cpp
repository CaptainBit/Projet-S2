//
// Created by fiset on 2020-02-11.
//
#include "Projectile/Physic.h"
#include <iostream>

int main (int argc, char *argv[]) {
    Parabole p  = Parabole(Coord(0,0), 45,25);
    for(float i = 0; i < 10; i += 0.1){
        Coord c = p.displacement(i);
        std::cout << "x : " << c.x << " y: " << c.y << std::endl;
    }
}