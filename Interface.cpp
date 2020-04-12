#include "../Interface.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QMatrix>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QPainterPath>
#include <QString>
#include <QChar>





Interface::Interface() {
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	setStyleSheet(qss.readAll());
	qss.close();
	//Déclaration des pointeurs
	centralWidget = new QWidget();
	barres = new QWidget();
	zoneDeJeu= new QWidget();
	disposition = new QVBoxLayout(centralWidget);
	hud = new QGridLayout(barres);
	QPalette palFond = palette();
	QPalette palTank = palette();

	//Taille des layouts du centralWidget
	zoneDeJeu->setFixedHeight((HAUTEUR_FENETRE * 4) / 5);
	zoneDeJeu->setFixedWidth(LONGUEUR_FENETRE);
	barres->setFixedHeight(HAUTEUR_FENETRE / 5);
	barres->setFixedWidth(LONGUEUR_FENETRE);

	//Initialisation de la zone de jeu
	
	tank1 = new Tank(0, zoneDeJeu);
	tank2 = new Tank(1, zoneDeJeu);
	terrain = new Terrain(LONGUEUR_FENETRE, (HAUTEUR_FENETRE * 1) / 5, (HAUTEUR_FENETRE * 4) / 5, zoneDeJeu);

	//Déclaration des progfress bar de la vie des joueurs et de leurs points de déplacements
	health_p1 = new QProgressBar();
	health_p2 = new QProgressBar();
	deplacement_p1 = new QProgressBar();
	deplacement_p2 = new QProgressBar();
	
	

	//Vie Player 1
	health_p1->setObjectName("Health");
	health_p1->setOrientation(Qt::Horizontal);
	health_p1->setMaximum(VIE_MAX);
	health_p1->setMinimum(0);
	health_p1->setValue(VIE_MAX);
	health_p1->setFixedHeight(30);
	health_p1->setFixedWidth(250);
	health_p1->setTextVisible(false);

	//Vie Player 2
	health_p2->setObjectName("Health");
	health_p2->setOrientation(Qt::Horizontal);
	health_p2->setInvertedAppearance(true);
	health_p2->setMaximum(VIE_MAX);
	health_p2->setMinimum(0);
	health_p2->setValue(VIE_MAX);
	health_p2->setFixedHeight(30);
	health_p2->setFixedWidth(250);
	health_p2->setTextVisible(false);

	//Déplacement Player 1
	deplacement_p1->setObjectName("Deplacement");
	deplacement_p1->setOrientation(Qt::Horizontal);
	deplacement_p1->setMaximum(POINTS_DEPLACEMENT);
	deplacement_p1->setMinimum(0);
	deplacement_p1->setValue(POINTS_DEPLACEMENT);
	deplacement_p1->setFixedHeight(30);
	deplacement_p1->setFixedWidth(250);
	deplacement_p1->setTextVisible(false);

	//Déplacement Player 2
	deplacement_p2->setObjectName("Deplacement");
	deplacement_p2->setOrientation(Qt::Horizontal);
	deplacement_p2->setInvertedAppearance(true);
	deplacement_p2->setMaximum(POINTS_DEPLACEMENT);
	deplacement_p2->setMinimum(0);
	deplacement_p2->setValue(POINTS_DEPLACEMENT);
	deplacement_p2->setFixedHeight(30);
	deplacement_p2->setFixedWidth(250);
	deplacement_p2->setTextVisible(false);
	
	//Ajouter les progress bar au HUD
	hud->addWidget(health_p1, 0, 0);
	hud->addWidget(health_p2, 0, 1);
	hud->addWidget(deplacement_p1, 1, 0);
	hud->addWidget(deplacement_p2, 1, 1);
	hud->setVerticalSpacing(1);
	hud->setHorizontalSpacing(800);

	//Ajouteur les deux layouts au central widget
	disposition->addWidget(barres);
	disposition->addWidget(zoneDeJeu);

	//Les couleurs de fond de tous les widgets et layouts
	palTank.setColor(QPalette::Background, Qt::transparent);
	tank1->setAutoFillBackground(true);
	tank1->setPalette(palTank);
	tank2->setAutoFillBackground(true);
	tank2->setPalette(palTank);
	palFond.setColor(QPalette::Background, Qt::blue);
	centralWidget->setAutoFillBackground(true);
	centralWidget->setPalette(palFond);

	//Initialisation du GameManager
	gm = new GameManager(terrain);
	gm->start_game();
	joueur1 = gm->getJoueur1();
	joueur2 = gm->getJoueur2();
	connect(joueur1, SIGNAL(signalVie(int)), health_p1, SLOT(setValue(int)));
	connect(joueur2, SIGNAL(signalVie(int)), health_p2, SLOT(setValue(int)));
	connect(joueur1, SIGNAL(signalDeplacer(int, int)), tank1, SLOT(updatePosition(int, int)));
	connect(joueur2, SIGNAL(signalDeplacer(int, int)), tank2, SLOT(updatePosition(int, int)));
	connect(joueur1, SIGNAL(signalPointDeDeplacement(int)), deplacement_p1, SLOT(setValue(int)));
	connect(joueur2, SIGNAL(signalPointDeDeplacement(int)), deplacement_p2, SLOT(setValue(int)));
	connect(joueur1, SIGNAL(signalPuissance(int)), tank1, SLOT(updatePuissance(int)));
	connect(joueur2, SIGNAL(signalPuissance(int)), tank2, SLOT(updatePuissance(int)));
	connect(joueur1, SIGNAL(signalAngle(int)), tank1, SLOT(updateAngle(int)));
	connect(joueur2, SIGNAL(signalAngle(int)), tank2, SLOT(updateAngle(int)));
	connect(tank1, SIGNAL(moved()), terrain, SLOT(update()));
	connect(tank2, SIGNAL(moved()), terrain, SLOT(update()));
	
	
	

	//Initialisation du centralWidget
	setCentralWidget(centralWidget);
}
Interface::~Interface() {

}
void Interface::keyPressEvent(QKeyEvent* event) {
	if (gm->getStatus()) {
		gm->en_jeux(event->text()[0].toLatin1());

	}
}
