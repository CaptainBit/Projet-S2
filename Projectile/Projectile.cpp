//
// Created by fiset on 2020-02-11.
//

#include "Projectile.h"
#include<cstdlib>

float randomRange(float min, float max)
{
	return ((rand() % (int)((max - min)*100)) + min*100)/100.0;
}

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
int Projectile::getDegat(int position_impact, int position_cible) {						// AJOUTER UN PARAMETRE "int distance" COMME SUGGERE DANS Projectile.h ???
	if (position_cible <= position_impact && position_cible + buffer >= position_impact) {
		return degat;
	}
	return 0;
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
	buffer_AOF = 6;
}

int Explosif::getDegat(int position_impact, int position_cible) {
	if (position_cible <= position_impact && position_cible + buffer >= position_impact) {
		return degat;
	}
	if (position_cible - buffer_AOF <= position_impact && position_cible + buffer + buffer_AOF >= position_impact) {
		return degat_AOF;
	}
	else return 0;
}



Buckshot::Buckshot(Vec2 position, float angle, float force) {
	degat = 1;
	for (Projectile i : bullets) {
		i = Projectile(position, angle, force*randomRange(0.8,1.2));
		i.setDegat(degat);
	}
}

int Buckshot::getDegat(int position_impact, int position_cible) {
	int degat_resultant = 0;
	for (Projectile i : bullets) {
		degat_resultant += i.getDegat(position_impact, position_cible);
	}
	return degat_resultant;
}