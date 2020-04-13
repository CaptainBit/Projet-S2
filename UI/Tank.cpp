#include "tank.h"
#include "Interface.h"//Inclus pour la constante LONGUEUR_FENETRE


Tank::Tank(int sens, QWidget * parent) :QWidget(parent) {
	//Initialisation Layout
	layout = new QHBoxLayout(this);
	tankEtCannon = new QWidget();
	stackedLayout = new QStackedLayout(tankEtCannon);
	stackedLayout->setStackingMode(QStackedLayout::StackAll);
	layout->setMargin(0);
	int spacing = 10;
	sensTank = sens;

	//Creation Tank
	body = new QLabel();
	cannon = new QLabel();
	QMatrix matrice;
	matrice.scale(0.1, 0.1);
	if (sens == -1) {
		picture_body.load(GREEN_BODY_PATH);
		picture_cannon.load(GREEN_CANNON_PATH);
	}
	else {
		picture_body.load(RED_BODY_PATH);
		picture_cannon.load(RED_CANNON_PATH);
		matrice.scale(-1, 1);

	}
	picture_cannon = picture_cannon.transformed(matrice);
	picture_body = picture_body.transformed(matrice);
	cannon->setPixmap(picture_cannon);
	body->setPixmap(picture_body);

	//Creation Jauge de puissance
	jauge = new QProgressBar();
	jauge->setObjectName("Tank");
	jauge->setFixedHeight(picture_body.height() + 20);
	jauge->setFixedWidth(int(picture_body.width() / 4));
	jauge->setMaximum(50);
	jauge->setMinimum(0);
	jauge->setValue(1);
	jauge->setOrientation(Qt::Vertical);
	jauge->setTextVisible(false);

	//Ajout aux layouts
	stackedLayout->addWidget(body);
	stackedLayout->addWidget(cannon);
	this->setFixedHeight(picture_body.height() + 20);
	this->setFixedWidth((picture_body.width() * 5 / 4) + spacing);
	layout->setSpacing(spacing);

	//Ajout de la jauge avant ou apres le tank dependament du sens du tank
	if (sens == -1)
		layout->addWidget(jauge);
	layout->addWidget(tankEtCannon);
	if (sens == 1) {
		layout->addWidget(jauge);
		jauge->setVisible(false);
	}
	layout->setAlignment(tankEtCannon, Qt::AlignBottom);


}
Tank::~Tank() {
	delete jauge;
	delete cannon;
	delete body;
	delete stackedLayout;
	delete tankEtCannon;
	delete layout;
}

//Update de la jauge de puissance
void Tank::updateJauge(int puissance) {
	jauge->setValue(puissance);
}

//Afficher la jauge de puissance ou non dependament du tour
void Tank::affichageJauge() {
	if (jauge->isVisible())
		jauge->setVisible(false);
	else
		jauge->setVisible(true);
}

//Update la position du tank et du cannon
void Tank::updatePosition(int x, int y, int sens) {
	QMatrix m;
	this->move(x, y);
	if (sensTank * sens > 0)
		m.scale(-1, 1);
	else if (sens * sensTank == 0)
		return;
	cannon->setPixmap(picture_cannon.transformed(m));
	body->setPixmap(picture_body.transformed(m));

}

//Change l'angle du canon
void Tank::updateAngle(int angle) {
	QMatrix rm;
	rm.rotate(sensTank*angle);
	cannon->setPixmap(picture_cannon.transformed(rm));
}

//Override de la fonction move incluant le offset du tank
void Tank::move(int x, int y) {
	QWidget::move(x - this->width() / 2, y - this->height());
}

//Retourne le sens du tank -1 pour vers la droite et 1 pour vers la gauche
int Tank::getSensTank() {
	return sensTank;
}