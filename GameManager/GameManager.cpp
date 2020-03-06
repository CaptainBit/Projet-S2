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
	ui.afficherTour(joueur_actif);
	tour = !tour;
}

void GameManager::start_game()
{
	joueur_un->setPosition({ 0,0 });
	joueur_deux->setPosition({ 79,0 });
	ui.initialiserEcran(93, 20);
	ui.afficherHUD(*joueur_un, *joueur_deux);
	ui.afficherJoueur(*joueur_un, *joueur_deux);
	changer_tour();
}

void GameManager::en_jeux(char choice)
{
	switch (choice)
	{
	case 'a': if (joueur_actif->deplacer(-1)) {
		ui.afficherJoueur(*joueur_un, *joueur_deux);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		ui.afficherTour(joueur_actif);
	}
			  break;
	case 'd':
		if (joueur_actif->deplacer(1)) {
			ui.afficherJoueur(*joueur_un, *joueur_deux);
			ui.afficherHUD(*joueur_un, *joueur_deux);
			ui.afficherTour(joueur_actif);
		}
		break;
	case 'w':
		joueur_actif->setAngle(joueur_actif->getAngle() + 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 's':
		joueur_actif->setAngle(joueur_actif->getAngle() - 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'u':
		joueur_actif->setPuissance(joueur_actif->getPuissance() - 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'i':
		joueur_actif->setPuissance(joueur_actif->getPuissance() + 1);
		ui.afficherHUD(*joueur_un, *joueur_deux);
		break;
	case 'f':
		tirer();
		if (inGame){
			ui.afficherHUD(*joueur_un, *joueur_deux);
			changer_tour();
		}
		break;
	default:
		break;
	}
}

void GameManager::end_game()
{
	ui.afficherVainqueur(tour);
	inGame = false;
}
	
	
	//Methodes lies a la gestion d evenements:

void GameManager::tirer()		//Va probablement appeler set_angle et set_puissance de maniere consecutive
{
	//Gerer les fonctions tirer des joueurs
	
	Projectile boum = joueur_actif->tirer(joueur_actif->getAngle(), joueur_actif->getPuissance());
	int position_cible = joueur_cible->getPosition().x;
	
	int buffer_cible = 12;
	// APPELER AFFICHER EXPLOSITON
	int sens;
	if (tour)
		sens = -1;
	else sens= 1;
	int position_impact = joueur_actif->getPosition().x + sens * boum.getTrajectoire().getX(0);
	ui.afficherProjectile(joueur_actif->getPosition().x + sens * boum.getTrajectoire().getX(0));

	// *** GERER CE IF CASE DANS PROJECTILE AFIN DE MIEUX GERER LES CAS DE "AREA OF EFFECT" ***					--->		NOTE VIANNEY
	// SOIT ATTRIBUER LES DEGATS EN FCT DE LA DISTANCE (rentrer distance en parametre)
	if(position_cible<= position_impact && position_cible+buffer_cible >= position_impact){
		int degat = boum.getDegat();
		if(!joueur_cible->endomager(degat))
			end_game();
	}
	//AFFICHER UNE EXPLOSION AU SOL SI PAS TOUCHE CIBLE
	//AFFICHER NOUVEAU HUD avec la vie update du joueur
	
		
}
bool GameManager::getStatus() {
	return inGame;
}

