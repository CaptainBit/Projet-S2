/*
Classe de gestion du UI du tank et de sa jauge de puissance
*/

#ifndef TANK_H
#define TANK_H
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QPixmap>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QMatrix>

#include "joueur.h"

#define GREEN_BODY_PATH "./Ressources/Images/body_green.png"
#define GREEN_CANNON_PATH "./Ressources/Images/cannon_green.png"
#define RED_BODY_PATH "./Ressources/Images/body_red.png"
#define RED_CANNON_PATH "./Ressources/Images/cannon_red.png"

class Tank : public QWidget {
	Q_OBJECT
private:
	QHBoxLayout * layout;//Le main layout du widget contenant la jauge et le widget tankEtCannon
	QWidget *tankEtCannon;//Widget contenant les labels du canon et du body du tank
	QStackedLayout *stackedLayout;//Layout du widget tankEtCannon
	QPixmap picture_cannon; //Image du canon du tank
	QPixmap picture_body; //Image du char
	QLabel *body; //QLabel contenant l'image du char
	QLabel *cannon; //QLabel contenant l'image du canon
	QProgressBar *jauge; //Jauge de puissance
	int sensTank; //Sens dans lequel le tank commence
public:
	Tank(int sens, QWidget *parent = NULL);
	~Tank();
	int getSensTank(); //Retourne le sens du tank -1 pour vers la droite et 1 pour vers la gauche
public slots:
	void updateJauge(int puissance);//Update de la jauge de puissance
	void affichageJauge();//Afficher la jauge de puissance ou non dependament du tour
	void updatePosition(int x, int y, int sens);//Update la position du tank et du cannon
	void updateAngle(int angle);//Change l'angle du canon
	void move(int x, int y);//Override de la fonction move incluant le offset du tank
};

#endif // !TANK_H
