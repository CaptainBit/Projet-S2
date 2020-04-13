#include "../Munitions.h"

Munitions::Munitions() {

	//Déclaration des pointeurs
	munitions1 = new QRadioButton();
	munitions1->setObjectName("Munition1");
	munitions2 = new QRadioButton();
	munitions2->setObjectName("Munition2");
	munitions3 = new QRadioButton();
	munitions3->setObjectName("Munition3");
	layout = new QHBoxLayout(this);

	
	//Définition de la taille des boutons

	//Ajouter les boutons au layout
	layout->addWidget(munitions1);
	layout->addWidget(munitions2);
	layout->addWidget(munitions3);
	layout->setMargin(0);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(10);
}

Munitions::~Munitions() {

}
void Munitions::select(int munition) {
	switch (munition) {
	case 1: munitions1->setChecked(true);
		break;
	case 2: munitions2->setChecked(true);
		break;
	case 3: munitions3->setChecked(true);
		break;
	}
}