//
// Created by fiset on 2020-02-11.
//
#include "Joueur.h"
#include "Interface.h"

Joueur::Joueur()
{
    vie = VIE_MAX;
	pointsDeplacement = POINTS_DEPLACEMENT; 
	puissance = 0;
	angle = 1;
}

int Joueur::getVie()
{
	return vie;
}

Vec2 Joueur::getPosition()
{
	return position;
}

int Joueur::getTypePrjectile()
{
	return typeProjectile;
}

int Joueur::getPointsDeplacement()
{
	return pointsDeplacement;
}

void Joueur::setVie(int vie)
{
	this->vie = vie; 
	signalVie(vie);
}

void Joueur::setPosition(Vec2 position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	signalDeplacer(position.x,position.y);
}

void Joueur::setTypeProjectile(int type) 
{
	typeProjectile = type; 
}

void Joueur::setPointsDeplacement(int points) 
{
	pointsDeplacement = points; 
	signalPointDeDeplacement(points);
}

//Deplacer le tank(Positif vers la droite et negatif vers la gauche). Retourne s'il avait assez de point de deplacement
bool Joueur::deplacer(int x,int y)
{
	
	if (pointsDeplacement - abs(x) >= 0 && position.x + x>=35 && position.x + x <= LONGUEUR_FENETRE-35) {
		setPointsDeplacement(pointsDeplacement - abs(x));
		position.x += x;
		position.y = y;
		signalDeplacer(position.x,position.y);
		return 1;
	}
	return 0;
}

//Enleve le nombre de point de degat a la vie. Retourne si le tank est toujours en vie. 
bool Joueur::endomager(int degat)
{
	vie -= degat;
	signalVie(vie);
	return (vie > 0);
}

Projectile Joueur::tirer(float angle, float force)
{
	Projectile projectile(position,angle, force);
	signalTirer();
	return projectile; 
}
int Joueur::getAngle() {
	return angle;
}
int Joueur::getPuissance() {
	return puissance;
}
void Joueur::setPuissance(int puissance) {
	if (puissance <= 50 && puissance > 0) {
		this->puissance = puissance;
		signalPuissance(puissance);
	}
}
void Joueur::setAngle(int angle) {
	if (angle > 0 && angle < 90) {
		signalAngle(angle);
		this->angle = angle;
	}
}
