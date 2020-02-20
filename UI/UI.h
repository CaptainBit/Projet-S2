//
// Created by fiset on 2020-02-11.
//

#include "../GameManager/Joueur.h"
#ifndef PROJET_UI_H
#define PROJET_UI_H

#define offsetX 10
#define offsetY 3

class UI {
public:
	void initialiserEcran(int x,int y);
	void afficherHUD(Joueur j1, Joueur j2);
	void afficherJoueur(Joueur j1, Joueur j2);

};


#endif //PROJET_UI_H
