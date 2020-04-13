/*
Classes de gestion des différents projectiles
*/

#ifndef PROJET_PROJECTILE_H
#define PROJET_PROJECTILE_H

#include "../Projectile/Physic.h"
#include "../Vec2.h"

#define DEGAT_DEFAULT 10;

//Projectile de base
class Projectile {
protected:
	Parabole trajectoire;//Trajectoire du projectile
	int degat;// Dégat du projectile
	int buffer = 12;		// LARGEUR DU TANK - Verifier avec Qt
public:
	Projectile();		// Besoin d un default constructor pour instancier les classe enfant
	Projectile(Vec2 position, float force, float angle);
	Parabole getTrajectoire();
	int getDegat();
	void setParabole(Parabole trajectoire);
	void setDegat(int degat);
};


class Explosif :public Projectile {
protected:
	int buffer_AOF;
	int degat_AOF;
public:
	Explosif(Vec2 position, float angle, float force);
	int getDegat(int position_impact, int position_cible);		// Determine si degat type direct ou type AOF
};


class Buckshot : public Projectile {
protected:
	Projectile bullets[12];		// This array stores the offset from center impact each bullet of the buckshot have
public:
	Buckshot(Vec2 position, float angle, float force);
	int getDegat(int position_impact, int position_cible);
};
#endif //PROJET_PROJECTILE_H