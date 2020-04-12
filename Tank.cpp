#include "tank.h"
#include "Interface.h"
#include <QHBoxLayout>
#include <QMatrix>
#include <QStackedLayout>
#include <QPainter>
Tank::Tank(int sens,QWidget * parent):QWidget(parent) {
	//Initialisation Layout
	QHBoxLayout *layout = new QHBoxLayout(this);
	QWidget *tankEtCannon = new QWidget();
	QStackedLayout *stackedLayout=new QStackedLayout(tankEtCannon);
	stackedLayout->setStackingMode(QStackedLayout::StackAll);
	layout->setMargin(0);
	stackedLayout->setMargin(0);
	int spacing = 10;
	sensTank= sens;

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
	jauge->setFixedHeight(picture_body.height()+20);
	jauge->setFixedWidth(int(picture_body.width() / 4));
	jauge->setMaximum(50);
	jauge->setMinimum(1);
	jauge->setValue(0);
	jauge->setOrientation(Qt::Vertical);
	jauge->setTextVisible(false);

	//Ajout aux layouts
	stackedLayout->addWidget(body);
	stackedLayout->addWidget(cannon);
	this->setFixedHeight(picture_body.height() + 20);
	this->setFixedWidth((picture_body.width() * 5/ 4) + spacing);
	layout->setSpacing(spacing);

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

}
void Tank::updateJauge(int puissance) {
	jauge->setValue(puissance);
}
void Tank::affichageJauge() {
	if (jauge->isVisible())
		jauge->setVisible(false);
	else
		jauge->setVisible(true);
}

void Tank::updatePosition(int x,int y, int sens) {
	QMatrix m;
	this->move(x, y);
	if (sensTank * sens > 0)
		m.scale(-1, 1);
	else if (sens * sensTank == 0)
		return;
	cannon->setPixmap(picture_cannon.transformed(m));
	body->setPixmap(picture_body.transformed(m));

}
void Tank::updateAngle(int angle) {
	QMatrix rm;
	rm.rotate(-angle);
	cannon->setPixmap(picture_cannon.transformed(rm));
}
void Tank::move(int x, int y) {
	QWidget::move(x - this->width() / 2, y - this->height());
}

int Tank::getSensTank() {
	return sensTank;
}