/*
Classe de l'interface du jeu
*/

#ifndef INTERFACE_H
#define INTERFACE_H


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
#include "./UI/Tank.h"
#include "Terrain.h"
#include "GameManager.h"
#include "Munitions.h"
#define HAUTEUR_FENETRE  720
#define LONGUEUR_FENETRE  1280

class Interface :public QWidget {
	Q_OBJECT
private:
	Joueur * joueur1;//pointeur vers le joueur 1 du game manager
	Joueur* joueur2;//pointeur vers le joueur 1 du game manager
	QProgressBar* health_p1;//Barre de vie du joueur 1
	QProgressBar* health_p2;//Barre de vie du joueur 2
	QProgressBar* deplacement_p1;//Barre de déplacement du joueur 1
	QProgressBar* deplacement_p2;//Barre de déplacement du joueur 1
	Tank* tank1;//Visuel du tank et puissance du joueur 1
	Tank* tank2;//Visuel du tank et puissance du joueur 2
	Terrain* terrain;//Widget contenant le terrain
	QWidget* barres;//Widget contenant tous les barres d'informations
	QWidget* zoneDeJeu;//Widget contenant tous les éléments du jeu (Tanks et terrain)
	QVBoxLayout* disposition;//VBox assemblant les barres et la zone de jeu
	QGridLayout* hud;//Layout des barres du HUD
	GameManager* gm;//Gère les informations d'arrière plan du jeu
	Munitions* munitionsPlayer1;//Selecteur de munitions du joueur 1
	Munitions* munitionsPlayer2;//Selecteur de munitions du joueur 2
	QLabel* tour; //Texte affichant le tour actuel
public:
	Interface();
	~Interface();
	void keyPressEvent(QKeyEvent* event);//Traitement des touches
	void paintEvent(QPaintEvent *);//Sert à l'affichage du background du widget
public slots:
	void changerTour(string);//Changement du texte affichant à qui le tour
};

#endif
