//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_PROJECTILE_H
#define PROJET_PROJECTILE_H
#include "Physic.h"
#include "../Projectile/Projectile.h"
#define DEGAT_DEFAULT=10;

class Projectile {
private:
	Parabole trajectoire;
	int degat;
public:
	Projectile(float force,float angle);
	Parabole getTrajectoire();
	int getDegat();
	void setParabole(Parabole trajectoire);
	void setDegat();
};


#endif //PROJET_PROJECTILE_H
