/*
Classe de gestion de tous les informations d'un joueur
*/


#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H
#include "..\Projectile\Projectile.h"
#include "../Vec2.h"
#include <cstdlib>
#include <Qt>
#include <QObject>

#define POINTS_DEPLACEMENT 200
#define VIE_MAX  100

class Joueur:public QObject {
	Q_OBJECT
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
	void setTypeProjectile(int type);
	int getPuissance();
	int getAngle();


	void setVie(int vie);
	void setPosition(Vec2 position);
	void setPuissance(int puissance);
	void setAngle(int angle);
	void setPointsDeplacement(int points);
	bool deplacer(int x, int y);
	bool endomager(int degat);
	Projectile tirer(float force, float angle);

signals:
	void signalVie(int vie);
	void signalPuissance(int puissance);
	void signalAngle(int angle);
	void signalPointDeDeplacement(int point);
	void signalDeplacer(int x,int y, int sens);
	void signalTirer();
	void selectAmmo(int type);
};


#endif //PROJET_JOUEUR_H
