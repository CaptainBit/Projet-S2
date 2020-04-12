#include "../Munitions.h"

Munitions::Munitions() {

	//Déclaration des pointeurs
	munitions1 = new QRadioButton();
	munitions2 = new QRadioButton();
	munitions3 = new QRadioButton();
	layout = new QHBoxLayout(this);

	
	//Définition de la taille des boutons
	munitions1->setFixedHeight(50);
	munitions1->setFixedWidth(50);
	munitions2->setFixedHeight(50);
	munitions2->setFixedWidth(50);
	munitions3->setFixedHeight(50);
	munitions3->setFixedWidth(50);

	//Ajouter les boutons au layout
	layout->addWidget(munitions1);
	layout->addWidget(munitions2);
	layout->addWidget(munitions3);
	layout->setMargin(0);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(0);
}

Munitions::~Munitions() {

}