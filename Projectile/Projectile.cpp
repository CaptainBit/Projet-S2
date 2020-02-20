//
// Created by fiset on 2020-02-11.
//

#include "Projectile.h"

Projectile::Projectile(Vec2 position, float angle, float force) {
	trajectoire = Parabole(position, angle, force);
	degat = DEGAT_DEFAULT;
}
Parabole Projectile::getTrajectoire() {
	return trajectoire;
}
int Projectile::getDegat() {
	return degat;
}
void Projectile::setParabole(Parabole trajectoire) {
	this->getTrajectoire() = trajectoire;
}
void Projectile::setDegat(int degat) {
	this->degat = degat;
}