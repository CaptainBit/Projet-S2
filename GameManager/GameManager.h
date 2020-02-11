//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_GAMEMANAGER_H
#define PROJET_GAMEMANAGER_H

#include UI.h
#include traitementPhysic.h
#include traitementProjectile.h
#include traitementJoueur.h
#include traitementTerrain.h

class GameManager {

private:
	Terrain terrain(int hauteur, int largeur);
	Joueur joueur_un;		// Passer en argument les coord de depart??
	Joueur joueur_deux;		// Passer en argument les coord de depart??
	UI ui;
	
public:
	GameManager();
	~GameManager();
	void changer_tour();
	void refresh_frame();	//Afficher le UI avec les donnees a jour
	
	//Methodes lies a la gestion d evenements:



};


#endif //PROJET_GAMEMANAGER_H
