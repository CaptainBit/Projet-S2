//
// Created by fiset on 2020-02-11.
//

#include "Projectile.h"
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
	if (distance == 0) return Projectile::degat;
	if (distance <= AOF) return degat_AOF;
	else return 0;
}