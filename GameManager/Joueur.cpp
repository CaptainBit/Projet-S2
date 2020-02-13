//
// Created by fiset on 2020-02-11.
//


#include "Joueur.h"
Joueur::Joueur()
{
	vie = VIE_MAX;
	pointsDeplacement = POINTS_DEPLACEMENT; 
}
int Joueur::getVie()
{
	return vie;
}

Coord Joueur::getPosition()
{
	return position;
}

int Joueur::getTypePrjectile()
{
	return typeProjectile;
}

int Joueur::getPointsDeplacement()
{
	return pointsDeplacement
}

void Joueur::setVie(int vie)
{
	this->vie = vie; 
}

void Joueur::setPosition(Coord position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}

void Joueur::setTypeProjectile(int type) 
{
	typeProjectile = type; 
}

void Joueur::setPointsDeplacement(int points) 
{
	pointsDeplacement = points; 
}

//Deplacer le tank(Positif vers la droite et negatif vers la gauche). Retourne s'il avait assez de point de deplacement
bool Joueur::deplacer(int deplacement)
{

}

//Enleve le nombre de point de degat a la vie. Retourne si le tank est toujours en vie. 
bool Joueur::endomager(int degat)
{
	vie -= degat;
	return (vie > 0);
}

Projectile Joueur::tirer(float force, float angle)
{
	Projectile projectile; 

}
