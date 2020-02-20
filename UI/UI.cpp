//
// Created by fiset on 2020-02-11.
//

#include "UI.h"
#include "DosGraph.h"
#include <iomanip>

void UI::initialiserEcran(int x, int y) {
	setScreen(x+20,y+6);
	dessinerCadre(offsetX, offsetY, x + offsetX, y + offsetY, CadreDouble);
	setXY(50, 1);
	setTextBackgroundColor(ROUGE,NOIR);
	cout << "LE BUS";
	setTextBackgroundColor(NOIR, NOIR);
	setXY(50, y + 4);



	//Affichage joueur 1
	setTextBackgroundColor(GRIS, NOIR);
	setXY(offsetX + 2, offsetY + 2);
	cout << "JOUEUR 1";
	setXY(offsetX + 2, offsetY + 4);
	cout << "POINT";
	setXY(offsetX + 2, offsetY + 5);
	cout << "MOUVEMENT";
	setXY(offsetX + 2, offsetY + 7);
	cout << "ANGLE";
	setXY(offsetX + 2, offsetY + 9);
	cout << "PUISSANCE";

	//Affichage joueur 2
	setXY(offsetX + 83, offsetY + 2);
	cout << "JOUEUR 2";
	setXY(offsetX + 83, offsetY + 4);
	cout << "POINT";
	setXY(offsetX + 83, offsetY + 5);
	cout << "MOUVEMENT";
	setXY(offsetX + 83, offsetY + 7);
	cout << "ANGLE";
	setXY(offsetX + 83, offsetY + 9);
	cout << "PUISSANCE";
}

void UI::afficherHUD(Joueur j1, Joueur j2) {


	//Affichage vie joueur 1
	setXY(offsetX + 12, offsetY + 2);
	cout << setw(20) << " ";

	setBackgroundColor(ROUGE_CLAIR);
	for (int i = 0; i < 20; i++) {
		if (i < j1.getVie())
			setBackgroundColor(ROUGE_CLAIR);
		else
			setBackgroundColor(GRIS_CLAIR);

		setX(offsetX + 12 + i);
		cout << " ";
	}


	//affichage vie joueur 2
	setXY(offsetX + 61, offsetY + 2);
	cout << setw(20) << " ";

	for (int i = 19; i >= 0; i--) {
		if (i < j2.getVie())
			setBackgroundColor(ROUGE_CLAIR);
		else
			setBackgroundColor(GRIS_CLAIR);


		setX(offsetX + 61 + i);
		cout << " ";
	}


	//affichage point déplacement joueur 1
	setBackgroundColor(NOIR);
	setXY(offsetX + 12, offsetY + 4);
	cout << setw(20) << " ";

	setBackgroundColor(BLEU);
	for (int i = 0; i < j1.getPointsDeplacement(); i++) {
		setX(offsetX + 12 + (2*i));
		cout << " ";
	}


	//affichage point déplacement joueur 2
	setBackgroundColor(NOIR);
	setXY(offsetX + 61, offsetY + 4);
	cout << setw(20) << " ";

	setBackgroundColor(BLEU);
	for (int i = 0; i < j2.getPointsDeplacement(); i++) {
		setX(offsetX + 80 - (2 * i));
		cout << " ";
	}

	//Affichage de l'angle joueur 1
	setTextBackgroundColor(GRIS_CLAIR, NOIR);
	setXY(offsetX + 12, offsetY + 7);
	cout << j1.getAngle() <<" deg";
	if (j1.getAngle() < 10)
		cout << " " ;
	//Affichage de l'angle joueur 2
	setXY(offsetX + 75,offsetY+7);
	cout << j2.getAngle()<<" deg";
	if (j2.getAngle() < 10)
		cout << " ";

	//Affichage de la puissance joueur 1
	setTextBackgroundColor(GRIS_CLAIR, NOIR);
	setXY(offsetX + 12, offsetY + 9);
	cout << j1.getPuissance() << " ";
	if (j1.getPuissance() < 10)
		cout << " ";

	//Affichage de la puissance joueur 2
	setTextBackgroundColor(GRIS_CLAIR, NOIR);
	setXY(offsetX + 75, offsetY + 9);
	cout << j2.getPuissance() << " ";
	if (j2.getPuissance() < 10)
		cout << " ";
}


void UI::afficherJoueur(Joueur j1, Joueur j2) {

	setBackgroundColor(NOIR);
	setXY(offsetX + 1, offsetY + 16);
	cout << setw(92);
	cout << " ";
	setXY(offsetX + 1, offsetY + 17); 
	cout << setw(92);
	cout << " ";
	setXY(offsetX + 1, offsetY + 18);
	cout << setw(92);
	cout << " ";
	setXY(offsetX + 1, offsetY + 19);
	cout << setw(92);
	cout << " ";

	//Affichage tank du joueur 1
	setXY(offsetX + 1 + j1.getPosition().x, offsetY + 16);
	cout << "   ___";
	setXY(offsetX + 1 + j1.getPosition().x, offsetY + 17);
	cout << " _(   )======";
	setXY(offsetX + 1 + j1.getPosition().x, offsetY + 18);
	cout << "/~~~~~~~\\";
	setXY(offsetX + 1 + j1.getPosition().x, offsetY + 19);
	cout << "\\O.O.O.O/";


	//Affichage tank du joueur 2

	setXY(offsetX + 1 + j2.getPosition().x, offsetY + 16);
	cout << "       ___";
	setXY(offsetX + 1 + j2.getPosition().x, offsetY + 17);
	cout << "======(   )_";
	setXY(offsetX + 1 + j2.getPosition().x, offsetY + 18);
	cout << "    /~~~~~~~\\";
	setXY(offsetX + 1 + j2.getPosition().x, offsetY + 19);
	cout << "    \\O.O.O.O/";



}