//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_PROJECTILE_H
#define PROJET_PROJECTILE_H

#include "../Projectile/Physic.h"
#include "../Projectile/Projectile.h"
#include "../Vec2.h"

#define DEGAT_DEFAULT 10;

class Projectile {
protected:
	Parabole trajectoire;
	int degat;
public:
	Projectile();		// Besoin d un default constructeur pour instancier la classe enfant Explosif
	Projectile(Vec2 position,float force,float angle);
	Parabole getTrajectoire();
	int getDegat();
	void setParabole(Parabole trajectoire);
	void setDegat(int degat);
};


class Explosif :public Projectile
{
protected:
	int AOF;
	int degat_AOF;
public:
	Explosif(Vec2 position, float angle, float force);
	int getDegat(int distance);		// Determine si degat type direct ou type AOF
};

#endif //PROJET_PROJECTILE_H
