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
	joueur_un->setPosition({ 0,0 });
	joueur_deux->setPosition({ 79,0 });
	ui.initialiserEcran(93, 20);
	ui.afficherHUD(*joueur_un, *joueur_deux);
	ui.afficherJoueur(*joueur_un, *joueur_deux);
}

void GameManager::en_jeux(char choice)
{
	switch (choice)
	{
	case 'a': if (joueur_actif->deplacer(-1)) {
		ui.afficherJoueur(*joueur_un, *joueur_deux);
		ui.afficherHUD(*joueur_un, *joueur_deux);
	}
			  break;
	case 'd':
		if (joueur_actif->deplacer(1)) {
			ui.afficherJoueur(*joueur_un, *joueur_deux);
			ui.afficherHUD(*joueur_un, *joueur_deux);
		}
		break;
	case 'w':
		joueur_actif->setAngle(getAngle() + 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 's':
		joueur_actif->setAngle(getAngle() - 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'u':
		joueur_actif->setPuissance(getPuissance() + 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'i':
		joueur_actif->setPuissance(getPuissance()-1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'f':
		tirer();
		break;
	default:
		break;
	}
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
		if(!joueur_cible->endomager(degat))
			end_game();
	}
	//AFFICHER UNE EXPLOSION AU SOL SI PAS TOUCHE CIBLE
	//AFFICHER NOUVEAU HUD avec la vie update du joueur
	changer_tour();
		
}
bool GameManager::getStatus() {
	return inGame;
}

