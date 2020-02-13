//
// Created by fiset on 2020-02-11.
//

#include "GameManager.h"


GameManager::GameManager()
{
	Terrain t(10,10);	// pour un array de 10X10
	terrain = &t;
	Joueur un;
	Joueur deux;
	Joueur_un = &un;
	Joueur_deux = &deux;
}
GameManager::GameManager(int hauteur, int largeur)
{
	Terrain t(hauteur,largeur);	
	terrain = &t;
	Joueur un;
	Joueur deux;
	Joueur_un = &un;
	Joueur_deux = &deux;
}
GameManager::~GameManager()
{
	delete Joueur_un;
	delete Joueur_deux;
	delete terrain;
}
void GameManager::changer_tour()	//refresh le nombre de pts de deplacement du joueur actif
{
	tour = !tour;
	if(tour){
		joueur_un->mvt = 5;			//A modifier en fonction de l implementation de la class joueur
	}
	else{
		joueur_deux->mvt = 5;			//A modifier en fonction de l implementation de la class joueur
	}
}
void GameManager::refresh_frame()	//Afficher le UI avec les donnees a jour
{
	ui.afficher();
}
	
	
	//Methodes lies a la gestion d evenements:
void GameManager::deplacer_joueur()
{
	
}
void GameManager::tirer()		//Va probablement appeler set_angle et set_puissance de maniere consecutive
{
	
}
void GameManager::set_angle()
{
	
}
void GameManager::set_puissance()
{
	
}
