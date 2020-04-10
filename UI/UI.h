//
// Created by fiset on 2020-02-11.
//

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QLayout>

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

private:
	QWidget* mainCentralWidget;
	QLabel* mainBackground;

};


#endif //PROJET_UI_H
