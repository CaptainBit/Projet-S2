//
// Created by fiset on 2020-02-11.
//
#include "Projectile/Physic.h"
#include <iostream>

int main (int argc, char *argv[]) {
    Parabole p  = Parabole(Vec2(0,0), 45,25);
    for(float i = 0; i < 10; i += 0.1){
        Vec2 c = p.displacement(i);
        std::cout << "Y : " << c.y << " Y calculated : " << p.getY(c.x) << std::endl;
    }
}