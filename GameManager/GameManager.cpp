//
// Created by fiset on 2020-02-11.
//

#include "GameManager.h"


GameManager::GameManager()
{// pour un array de 10X10
	terrain = new Terrain(DEFAULT_SIZE);

    joueur_un = new Joueur();
    joueur_deux = new Joueur();
}

GameManager::GameManager(int hauteur, int largeur)
{
	terrain = new Terrain(Vec2(hauteur,largeur));
    joueur_un = new Joueur();
    joueur_deux = new Joueur();
}
GameManager::~GameManager()
{
	delete joueur_un;
	delete joueur_deux;
	delete terrain;
}
void GameManager::changer_tour()	//refresh le nombre de pts de deplacement du joueur actif
{
	tour = !tour;
	if(tour){
		joueur_un->setPointsDeplacement(POINTS_DEPLACEMENT);			//A modifier en fonction de l implementation de la class joueur
	}
	else{
		joueur_deux->setPointsDeplacement(POINTS_DEPLACEMENT);			//A modifier en fonction de l implementation de la class joueur
	}
}
void GameManager::refresh_frame()	//Afficher le UI avec les donnees a jour
{
	//ui.afficher();
}

void GameManager::start_game()
{
	
}

void GameManager::end_game()
{
	
}
	
	
	//Methodes lies a la gestion d evenements:
void GameManager::deplacer_joueur()
{
	refresh_frame();
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
