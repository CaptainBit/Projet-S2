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
	Joueur *joueur_un;			// Passer en argument les coord de depart?? -- objet provenant de TraitementJour.h
	Joueur *joueur_deux;		// Passer en argument les coord de depart?? -- objet provenant de TraitementJour.h
	UI ui;
	int tour[]= {1,2}
	
public:
	GameManager();
	~GameManager();
	void changer_tour();	//refresh le nombre de pts de deplacement du joueur actif
	void refresh_frame();	//Afficher le UI avec les donnees a jour
	
	
	//Methodes lies a la gestion d evenements:
	void deplacer_joueur();
	void tirer();			//Va probablement appeler set_angle et set_puissance de maniere consecutive
	void set_angle();
	void set_puissance();


};


#endif //PROJET_GAMEMANAGER_H
