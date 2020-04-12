#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QWidget>
#include <QProgressBar>
#include <QKeyEvent>
#include <QPixmap>
#include <QLabel>
#include <QPolygon>
#include <QPaintEvent>
#include <QGridLayout>
#include <QToolBar>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "../Tank.h"
#include "../Terrain/Terrain.h"
#include "../GameManager/GameManager.h"
#define HAUTEUR_FENETRE  720
#define LONGUEUR_FENETRE  1280

class Interface :public QMainWindow {
	Q_OBJECT
private:
	Joueur* joueur1;
	Joueur* joueur2;
	QProgressBar* health_p1;
	QProgressBar* health_p2;
	QProgressBar* deplacement_p1;
	QProgressBar* deplacement_p2;
	Tank* tank1;
	Tank* tank2;
	Terrain* terrain;
	QPolygon rectangle;
	QWidget* centralWidget;
	QWidget* barres;
	QWidget* zoneDeJeu;
	QVBoxLayout* disposition;
	QGridLayout* hud;
	GameManager* gm;
public:
	Interface();
	~Interface();
	void keyPressEvent(QKeyEvent* event);
};

#endif
