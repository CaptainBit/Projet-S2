//
// Created by fiset on 2020-02-11.
//

#include "Projectile.h"
#include<cstdlib>

Projectile::Projectile() {
	degat = DEGAT_DEFAULT
}

Projectile::Projectile(Vec2 position, float angle, float force) {
	trajectoire = Parabole(position, angle, force);
	degat = DEGAT_DEFAULT;
}
Parabole Projectile::getTrajectoire() {
	return trajectoire;
}
int Projectile::getDegat() {						// AJOUTER UN PARAMETRE "int distance" COMME SUGGERE DANS Projectile.h ???
	return degat;
}
void Projectile::setParabole(Parabole trajectoire) {
	this->getTrajectoire() = trajectoire;
}
void Projectile::setDegat(int degat) {
	this->degat = degat;
}



Explosif::Explosif(Vec2 position, float angle, float force) {
	Projectile::trajectoire = Parabole(position, angle, force);
	Projectile::degat = 6;
	degat_AOF = 3;
	AOF = 12;
}

int Explosif::getDegat(int distance) {
	if (distance == 0) return Projectile::degat;	//Reecrire mieux le if case
	if (distance <= AOF) return degat_AOF;			//Reecrire mieux le if case
	else return 0;
}



Buckshot::Buckshot(Vec2 position, float angle, float force) {
	Projectile::trajectoire = Parabole(position, angle, force);
	Projectile::degat = 2;
	offset = 0;			// Redefinir en fct de la distance en x
}

int Buckshot::getDegat(int distance) {
	//verify if each bullet touches the target and sum the damages
	return 0;
}

void Buckshot::setOffset(int dist_x) {
	offset = dist_x / 4;
	for(int i; i < 10; i++) {
		bullets[i] // = GENERATE RANDOM NUMBERS - CAN IT BE FLOATS?;
	}
}