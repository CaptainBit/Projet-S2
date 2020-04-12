#ifndef TANK_H
#define TANK_H
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QPixmap>
#include "joueur.h"
#define GREEN_BODY_PATH "./Images/body_green.png"
#define GREEN_CANNON_PATH "./Images/cannon_green.png"
#define RED_BODY_PATH "./Images/body_red.png"
#define RED_CANNON_PATH "./Images/cannon_red.png"

class Tank : public QWidget {
	Q_OBJECT
private:
	QPixmap picture_cannon;
	QPixmap picture_body;
	QLabel *body;
	QLabel *cannon;
	QProgressBar *jauge;
	Joueur *joueur;
	int sensTank;
public:
	Tank(int sens,QWidget *parent=NULL);
	~Tank();
	int getSensTank();
public slots:
	void updateJauge(int puissance);
	void affichageJauge();
	void updatePosition(int x, int y, int sens);
	void updateAngle(int angle);
	void move(int x, int y);
signals:
	void moved();

};

#endif // !TANK_H
