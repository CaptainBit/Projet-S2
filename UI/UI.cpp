//
// Created by fiset on 2020-02-11.
//

#include "UI.h"
#include <iomanip>

UI::UI() {
	mainCentralWidget = new QWidget;


	setFixedSize(1280, 720);
	setWindowTitle("Tank War - P15");
	
	QHBoxLayout* mainLayout = new QHBoxLayout;
	
	mainBackground = new QLabel;
	mainBackground->setPixmap(QPixmap("./img/fond.png"));

	layout()->setContentsMargins(0, 0, 0, 0);
	

	mainLayout->addWidget(mainBackground);
	mainCentralWidget->setLayout(mainLayout);
	setCentralWidget(mainCentralWidget);
	show();
}


UI::~UI() {

}

void UI::initialiserEcran(int x, int y) 
{
	
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