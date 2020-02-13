//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_PROJECTILE_H
#define PROJET_PROJECTILE_H

#include "../Projectile/Physic.h"
#include "../Projectile/Projectile.h"
#include "../Vec2.h"

#define DEGAT_DEFAULT=10;

class Projectile {
private:
	Parabole trajectoire;
	int degat;
public:
	Projectile(Vec2 position,float force,float angle);
	Parabole getTrajectoire();
	int getDegat();
	void setParabole(Parabole trajectoire);
	void setDegat(int degat);
};


#endif //PROJET_PROJECTILE_H
