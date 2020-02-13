//
// Created by fiset on 2020-02-11.
//

#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H
#define POINT_DEPLACEMENT=10;
struct coord {
	int x;
	int y;
};
class Joueur {
private:
	int vie;
	coord position;
	int projectileType;
	int pointsDeplacement;
public:
	int getVie();
	coord getPosition();
	int getProjectileType();
	int getPointDeplacement();
	void setVie(int vie);
	void setPosition(coord Position);
	void setProjectileType(int type);
	void setPointsDeplacement(int points);

	//Deplacer le tank(Positif ver la droit et negatif vers la gauche). Retourne s'il avait assez de point de deplacement
	bool deplacer(int deplacement);
	//Enleve le nombre de point de degat a la vie. Retourne si le tank est toujours en vie
	bool endomager(int degat);

};


#endif //PROJET_JOUEUR_H
