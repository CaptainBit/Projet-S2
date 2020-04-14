#include "./UI/Interface.h"
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
#include <QFontDatabase>
#include <Qt>
#include <QStatusBar>
#include <QStyleOption>


Interface::Interface() {

	//D�claration des pointeurs
	barres = new QWidget();
	barres->setObjectName("HUD");
	zoneDeJeu = new QWidget();
	disposition = new QVBoxLayout(this);
	disposition->setMargin(0);
	hud = new QGridLayout(barres);
	QPalette palTank = palette();
	tour = new QLabel();
	tour->setObjectName("tourParTour");

	//Taille des layouts
	zoneDeJeu->setFixedHeight((HAUTEUR_FENETRE * 4) / 5);
	zoneDeJeu->setFixedWidth(LONGUEUR_FENETRE);
	barres->setFixedHeight(HAUTEUR_FENETRE / 5);
	barres->setFixedWidth(LONGUEUR_FENETRE);

	//Initialisation de la zone de jeu
	tank1 = new Tank(-1, zoneDeJeu);
	tank2 = new Tank(1, zoneDeJeu);
	terrain = new Terrain(LONGUEUR_FENETRE, (HAUTEUR_FENETRE * 2) / 5, (HAUTEUR_FENETRE * 4) / 5, zoneDeJeu);

	//D�claration des progfress bar de la vie des joueurs et de leurs points de d�placements
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

	//D�placement Player 1
	deplacement_p1->setObjectName("Deplacement");
	deplacement_p1->setOrientation(Qt::Horizontal);
	deplacement_p1->setMaximum(POINTS_DEPLACEMENT);
	deplacement_p1->setMinimum(0);
	deplacement_p1->setValue(POINTS_DEPLACEMENT);
	deplacement_p1->setFixedHeight(30);
	deplacement_p1->setFixedWidth(250);
	deplacement_p1->setTextVisible(false);

	//D�placement Player 2
	deplacement_p2->setObjectName("Deplacement");
	deplacement_p2->setOrientation(Qt::Horizontal);
	deplacement_p2->setInvertedAppearance(true);
	deplacement_p2->setMaximum(POINTS_DEPLACEMENT);
	deplacement_p2->setMinimum(0);
	deplacement_p2->setValue(POINTS_DEPLACEMENT);
	deplacement_p2->setFixedHeight(30);
	deplacement_p2->setFixedWidth(250);
	deplacement_p2->setTextVisible(false);

	//Initialisation des boutons
	munitionsPlayer1 = new Munitions();
	munitionsPlayer2 = new Munitions();

	//Ajouter les progress bar, le tour par tour et les boutons au HUD
	hud->addWidget(health_p1, 0, 0);
	hud->addWidget(health_p2, 0, 2);
	hud->addWidget(deplacement_p1, 1, 0);
	hud->addWidget(deplacement_p2, 1, 2);
	hud->addWidget(munitionsPlayer1, 2, 0);
	hud->addWidget(munitionsPlayer2, 2, 2);
	hud->addWidget(tour, 1, 1);
	hud->setVerticalSpacing(10);
	hud->setAlignment(tour, Qt::AlignCenter);
	hud->setAlignment(munitionsPlayer1, Qt::AlignLeft);
	hud->setAlignment(munitionsPlayer2, Qt::AlignRight);
	hud->setAlignment(health_p1, Qt::AlignLeft);
	hud->setAlignment(health_p2, Qt::AlignRight);
	hud->setAlignment(deplacement_p1, Qt::AlignLeft);
	hud->setAlignment(deplacement_p2, Qt::AlignRight);


	//Ajouteur les deux layouts au central widget
	disposition->addWidget(barres);
	disposition->addWidget(zoneDeJeu);

	//Les couleurs de fond de tous les widgets et layouts
	palTank.setColor(QPalette::Background, Qt::transparent);
	tank1->setAutoFillBackground(true);
	tank1->setPalette(palTank);
	tank2->setAutoFillBackground(true);
	tank2->setPalette(palTank);


	//Initialisation du GameManager
	gm = new GameManager(terrain);
	joueur1 = gm->getJoueur1();
	joueur2 = gm->getJoueur2();

	//Connect de tous les composantes
	connect(joueur1, SIGNAL(signalVie(int)), health_p1, SLOT(setValue(int)));
	connect(joueur2, SIGNAL(signalVie(int)), health_p2, SLOT(setValue(int)));
	connect(joueur1, SIGNAL(signalDeplacer(int, int, int)), tank1, SLOT(updatePosition(int, int, int)));
	connect(joueur2, SIGNAL(signalDeplacer(int, int, int)), tank2, SLOT(updatePosition(int, int, int)));
	connect(joueur1, SIGNAL(signalPointDeDeplacement(int)), deplacement_p1, SLOT(setValue(int)));
	connect(joueur2, SIGNAL(signalPointDeDeplacement(int)), deplacement_p2, SLOT(setValue(int)));
	connect(joueur1, SIGNAL(signalPuissance(int)), tank1, SLOT(updateJauge(int)));
	connect(joueur2, SIGNAL(signalPuissance(int)), tank2, SLOT(updateJauge(int)));
	connect(joueur1, SIGNAL(signalAngle(int)), tank1, SLOT(updateAngle(int)));
	connect(joueur2, SIGNAL(signalAngle(int)), tank2, SLOT(updateAngle(int)));
	connect(gm, SIGNAL(changementTour(string)), this, SLOT(changerTour(string)));
	connect(joueur1, SIGNAL(selectAmmo(int)), munitionsPlayer1, SLOT(select(int)));
	connect(joueur2, SIGNAL(selectAmmo(int)), munitionsPlayer2, SLOT(select(int)));
	gm->start_game();
	connect(gm, SIGNAL(changementTour()), tank1, SLOT(affichageJauge()));
	connect(gm, SIGNAL(changementTour()), tank2, SLOT(affichageJauge()));



}
Interface::~Interface() {
	//Joueur 1 et 2 sont delete dans le destructeur de GameManager
	delete health_p1;
	delete health_p2;
	delete deplacement_p1;
	delete deplacement_p2;
	delete tank1;
	delete tank2;
	delete terrain;
	delete munitionsPlayer1;
	delete munitionsPlayer2;
	delete tour;
	delete hud;
	delete barres;
	delete zoneDeJeu;
	delete gm;
	delete disposition;
}

//Traitement des touches
void Interface::keyPressEvent(QKeyEvent* event) {
	if (gm->getStatus()) {
		gm->en_jeux(event->text()[0].toLatin1());
	}
}

//Changement du texte affichant à qui le tour
void Interface::changerTour(string texte) {
	tour->setText(QString::fromStdString(texte));
	if (texte == "JOUEUR 1")
		tour->setStyleSheet("border: 5px solid #4e9a06");
	else tour->setStyleSheet("border: 5px solid #cd002a");;
}

//Sert à l'affichage du background du widget
void Interface::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}