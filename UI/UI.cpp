//
// Created by fiset on 2020-02-11.
//

#include "UI.h"
#include <iomanip>

UI::UI() {
	mainCentralWidget = new QWidget(this);


	setFixedSize(1280, 720);
	setWindowTitle("Tank War - P15");
	
	mainLayout = new QHBoxLayout;
	mainBackground = new QLabel;

	mainBackground->setPixmap(QPixmap("./ressources/menu_tank.png").scaledToWidth(1280));

	layout()->setContentsMargins(0, 0, 0, 0);
	
	mainLayout->addWidget(mainBackground);
	mainCentralWidget->setLayout(mainLayout);
	setCentralWidget(mainCentralWidget);

	//show(); ***** On le montre deja dans le main il me semble
}


UI::~UI() {
	delete mainBackground;
	delete mainLayout;
	delete mainCentralWidget;
}

void UI::initialiserEcran(int x, int y) 
{
	//Ecran menu demarrage
	
	//HUD

	//Joueurs

	//Affichage vainqueur

	//Projectiles
}

void UI::afficherHUD(Joueur j1, Joueur j2)
{


}


void UI::afficherJoueur(Joueur j1, Joueur j2) 
{


}

//Affichage tour par tour
void UI::afficherTour(Joueur* pJoueurActif)
{

}

//Afficher le projedctile lancée
void UI::afficherProjectile(int position)
{

}

//Afficher le vainqueur
void UI::afficherVainqueur(bool t)
{

	
}

void UI::afficherMenuDemarrage() {

}

//SLOTS
void UI::play_game() {

}
void UI::mute_sound() {

}