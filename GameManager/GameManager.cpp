//
// Created by fiset on 2020-02-11.
//

#include "GameManager.h"


GameManager::GameManager()
{
    joueur_un = new Joueur();
    joueur_deux = new Joueur();
    joueur_actif = joueur_un;
	joueur_cible = joueur_deux;
}


GameManager::~GameManager()
{
	delete joueur_un;
	delete joueur_deux;
}
void GameManager::changer_tour()	//refresh le nombre de pts de deplacement du joueur actif
{
	//reset angle & force
	if(tour)
	{
		joueur_actif = joueur_un;
		joueur_cible = joueur_deux;
	}
	else
	{
		joueur_actif = joueur_deux;
		joueur_cible = joueur_un;
	}
	
	joueur_actif->setPointsDeplacement(POINTS_DEPLACEMENT);			//A modifier en fonction de l implementation de la class joueur
	tour = !tour;
}

void GameManager::start_game()
{
	//START GUI (avec un beau ti tank en ascii de ALEX)
	//Initier tous les GUI avec valeurs de depart
	//etablir position initialle des joueurs
}

void GameManager::en_jeux(char choice)
{
	if(choice == 'a') joueur_actif->deplacer(-1);
	if(choice == 'd') joueur_actif->deplacer(1);
	if(choice == 'w') setAngle(1);
	if(choice == 's') setAngle(-1);
	if(choice == 'u') setPuissance(-1);
	if(choice == 'i') setPuissance(1);
	if(choice == 'f') tirer();
}

void GameManager::end_game()
{
	//ui de fin de jeu
	inGame = false;
}
	
	
	//Methodes lies a la gestion d evenements:

void GameManager::tirer()		//Va probablement appeler set_angle et set_puissance de maniere consecutive
{
	//Gerer les fonctions tirer des joueurs
	
	Projectile boum = joueur_actif->tirer(angle_tire, force_tire);
	int position_cible = joueur_cible->getPosition().y;
	int position_impact = boum.getTrajectoire().getY(joueur_cible->getPosition().x);
	int buffer_cible = 2;
	// APPELER AFFICHER EXPLOSITON
	if(position_cible-buffer_cible <= position_impact && position_cible+buffer_cible >= position_impact){
		int degat = boum.getDegat();
		if(!joueur_cible->endomager(degat)) end_game();
	}
	//AFFICHER UNE EXPLOSION AU SOL SI PAS TOUCHE CIBLE
	//AFFICHER NOUVEAU HUD avec la vie update du joueur
	changer_tour();
		
}
void GameManager::setAngle(float angle)
{
	angle_tire += angle;
}
void GameManager::setPuissance(float force)
{
	force_tire += force;
}
float GameManager::getAngle()
{
	return angle_tire;
}
float GameManager::getPuissance()
{
	return force_tire;
}

