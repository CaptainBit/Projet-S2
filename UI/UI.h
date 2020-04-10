//
// Created by fiset on 2020-02-11.
//

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qsound.h>

#include "../GameManager/Joueur.h"

#ifndef PROJET_UI_H
#define PROJET_UI_H


class UI : public QMainWindow {
	Q_OBJECT
public:
	UI();
	~UI();
	void initialiserEcran(int x,int y);
	void afficherHUD(Joueur j1, Joueur j2);
	void afficherJoueur(Joueur j1, Joueur j2);
	void afficherProjectile(int position);
	void afficherTour(Joueur* pJoueurActif);
	void afficherVainqueur(bool t);
	void afficherMenuDemarrage();

public slots:
	void play_game();
	void mute_sound();

private:
	QWidget* mainCentralWidget;
	QLabel* mainBackground;
	QHBoxLayout* mainLayout;
	QRadioButton* mute;
	QSound* wav_player;

	//HUD
	QPixmap *key_binding;

	//COMMENT AFFICHER UN RECTANGLE DE VIE SIMPLEMENT? (qpainter?)

	QPixmap *projectile_1_j1;
	QPixmap *projectile_2_j1;
	QPixmap *projectile_3_j1;

	QPixmap *projectile_1_j2;
	QPixmap *projectile_2_j2;
	QPixmap *projectile_3_j2;
	

		//MENU DEMARRAGE
	QPushButton *start;
	QPushButton *exit;

	//Joueurs
	QPixmap *joueur_1;
	QPixmap *joueur_1_canon;
	QPixmap *joueur_2;
	QPixmap *joueur_2_canon;

	//Affichage vainqueur 
	QPixmap *joueur_1_WINS;
	QPixmap *joueur_2_WINS;

	//Projectiles
	QPixmap *bullet;
	QPixmap *buckshot[10];
	QPixmap *explosion_AOF[10];

};


#endif //PROJET_UI_H
