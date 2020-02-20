//
// Created by fiset on 2020-02-11.
//


#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H
#include "..\Projectile\Projectile.h"
#include "../Vec2.h"
#include <cstdlib>

#define POINTS_DEPLACEMENT 10
#define VIE_MAX  20

class Joueur {
private:
	int vie;
	Vec2 position;
	int typeProjectile;
	int pointsDeplacement;
	int angle;
	int puissance;
public:
	Joueur();
	int getVie();
	Vec2 getPosition();
	int getTypePrjectile();
	int getPointsDeplacement();
	void setVie(int vie);
	void setPosition(Vec2 position);
	void setTypeProjectile(int type);
	void setPointsDeplacement(int points);
	int getPuissance();
	int getAngle();
	void setPuissance(int puissance);
	void setAngle(int angle);

	//Deplacer le tank(Positif ver la droit et negatif vers la gauche). Retourne s'il avait assez de point de deplacement
	bool deplacer(int deplacement);
	//Enleve le nombre de point de degat a la vie. Retourne si le tank est toujours en vie
	bool endomager(int degat);
	Projectile tirer(float force, float angle);

};


#endif //PROJET_JOUEUR_H
