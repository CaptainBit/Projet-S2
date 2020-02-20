//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_GAMEMANAGER_H
#define PROJET_GAMEMANAGER_H

//#include "UI.h"
#include "../Projectile/Physic.h"
#include "../Projectile/Projectile.h"
#include "Joueur.h"
#include "../Terrain/Terrain.h"
#include "../UI/UI.h"

#define DEFAULT_SIZE Vec2(93,1)

class GameManager {

private:
	//Terrain *terrain;
	Joueur *joueur_un;			// Passer en argument les coord de depart?? -- objet provenant de TraitementJour.h
	Joueur *joueur_deux;		// Passer en argument les coord de depart?? -- objet provenant de TraitementJour.h
	//UI ui;

	float angle_tire = 0;
	float force_tire = 0;
	bool inGame = true;
	bool tour = true;
	Joueur *joueur_actif;
	Joueur *joueur_cible;
	UI ui;
	
public:
	GameManager();
	~GameManager();
	void changer_tour();	//refresh le nombre de pts de deplacement du joueur actif
	
	
	//Methodes lies a la gestion d evenements:
	void tirer();			//Va probablement appeler getAngle et getPuissance de maniere consecutive
	void setAngle(float angle_tire);
	void setPuissance(float force_tire);
	float getAngle();
	float getPuissance();

	void start_game();
	void en_jeux(char choice);
	void end_game();
	bool getStatus();

};


#endif //PROJET_GAMEMANAGER_H
