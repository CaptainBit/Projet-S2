//
// Created by fiset on 2020-02-11.
//

#include "GameManager.h"
#include "Interface.h"


GameManager::GameManager(Terrain *terrain)
{
	this->terrain = terrain;
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
		changementTour("JOUEUR 1");
	}
	else
	{
		joueur_actif = joueur_deux;
		joueur_cible = joueur_un;
		changementTour("JOUEUR 2");
	}
	
	joueur_actif->setPointsDeplacement(POINTS_DEPLACEMENT);			//A modifier en fonction de l implementation de la class joueur
	joueur_actif->setTypeProjectile(1);
	changementTour();
	tour = !tour;
}

void GameManager::start_game()
{
	joueur_un->setPosition({ 40 , terrain->getHauteur(40) });
	joueur_deux->setPosition({LONGUEUR_FENETRE-40 , terrain->getHauteur(LONGUEUR_FENETRE-40) });
	
	changer_tour();
}

void GameManager::en_jeux(char choice)
{
	switch (choice)
	{
	case 'a': joueur_actif->deplacer(-5, terrain->getHauteur(joueur_actif->getPosition().x - 5));
			  break;
	case 'd':
		joueur_actif->deplacer(5,terrain->getHauteur(joueur_actif->getPosition().x+5));
		break;
	case 'w':
		joueur_actif->setAngle(joueur_actif->getAngle() + 1);
		
		break;
	case 's':
		joueur_actif->setAngle(joueur_actif->getAngle() - 1);
		
		break;
	case 'f':
		joueur_actif->setPuissance(joueur_actif->getPuissance() - 1);
		
		break;
	case 'r':
		joueur_actif->setPuissance(joueur_actif->getPuissance() + 1);
		
		break;
	case 'e':
		tirer();
		if (inGame){
			
			changer_tour();
		}
		break;
	case '1':
		joueur_actif->setTypeProjectile(1);
		break;
	case '2':
		joueur_actif->setTypeProjectile(2);
		break;
	case '3':
		joueur_actif->setTypeProjectile(3);
		break;
	default:
		break;
	}
}

void GameManager::end_game()
{
	
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
Joueur* GameManager::getJoueur1() {
	return joueur_un;
}
Joueur* GameManager::getJoueur2() {
	return joueur_deux;
}

