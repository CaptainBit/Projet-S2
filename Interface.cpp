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
#include <QFontDatabase>
#include <Qt>
#include <QStatusBar>
#include <QStyleOption>


Interface::Interface() {

	//D�claration des pointeurs
	barres = new QWidget();
	barres->setObjectName("HUD");
	zoneDeJeu= new QWidget();
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
	terrain = new Terrain(LONGUEUR_FENETRE, (HAUTEUR_FENETRE * 1) / 5, (HAUTEUR_FENETRE * 4) / 5, zoneDeJeu);

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
	hud->addWidget(tour, 1,1);
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
	connect(joueur1, SIGNAL(signalDeplacer(int, int,int)), tank1, SLOT(updatePosition(int, int,int)));
	connect(joueur2, SIGNAL(signalDeplacer(int, int,int)), tank2, SLOT(updatePosition(int, int,int)));
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

}
void Interface::keyPressEvent(QKeyEvent* event) {
	if (gm->getStatus()) {
		gm->en_jeux(event->text()[0].toLatin1());

	}
}
void Interface::changerTour(string texte) {
	tour->setText(QString::fromStdString(texte));
	if (texte == "JOUEUR 1")
		tour->setStyleSheet("border: 5px solid #4e9a06");
	else tour->setStyleSheet("border: 5px solid #cd002a");;
}
void Interface::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


TankApp::TankApp(int &argc, char **argv)

	:QApplication(argc, argv)

{
	

	mainWindow = new QMainWindow;
	QFile qss("style.qss");
	qss.open(QFile::ReadOnly);
	this->setStyleSheet(qss.readAll());
	qss.close();


	QStatusBar controlBar;
	controlBar.setSizeGripEnabled(false);
	QWidget controlWidget;
	QHBoxLayout controlLayout(&controlWidget);
	controlLayout.setMargin(5);
	QLabel control("A & D: Déplacement   W & S: Changer l'angle du canon   F & R: Changer la puissance   E: Tirer  1,2,3 : Type de projectile");
	control.setObjectName("Control");
	controlWidget.setObjectName("Control");
	controlLayout.addWidget(&control,1,Qt::AlignCenter);
	controlBar.addWidget(&controlWidget,1);
	mainWindow->setStatusBar(&controlBar);
	
	
	mainWindow->setFixedSize(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
	mainWindow->setWindowTitle("Tank War - P15");
	


	
	

	mainWindow->show();
	setupMenu();

	exec();

}



TankApp::~TankApp() {


	delete mainWindow;

}



void TankApp::setupMenu() {

	menu = new Menu();
	

	mainWindow->setCentralWidget(menu);
	music = new QMediaPlayer;

	music->setMedia(QUrl::fromLocalFile("Ressources/sons/play_2.wav"));

	music->play();
	
	music->setVolume(0);


	connect(menu->play_button, SIGNAL(clicked()), this, SLOT(setupGame()));

	connect(menu->exit_button, SIGNAL(clicked()), this, SLOT(quit()));

	connect(menu->volumeSlider, SIGNAL(valueChanged(int)), music, SLOT(setVolume(int)));
	//mainWindow->setPalette(palette);






}



void TankApp::setupGame() {

	game = new Interface;
	this->setObjectName("CentralWidget");

	mainWindow->setCentralWidget(game);
	mainWindow->setObjectName("Game");
	game->setFocus();
	game->show();



}



Menu::Menu() 

{

	//Declaration des pointeurs



	mainLayout = new QGridLayout(this);

	play_button = new QPushButton("JOUER");

	exit_button = new QPushButton("SORTIR");

	volumeSlider = new QSlider(Qt::Horizontal, this);





	play_button->setFixedSize(70, 30);

	exit_button->setFixedSize(70, 30);

	volumeSlider->setFixedWidth(100);
	volumeSlider->setRange(0, 100);
	volumeSlider->setValue(0);


	//Set background image




	mainLayout->addWidget(volumeSlider, 1, 0, Qt::AlignRight);

	mainLayout->addWidget(play_button, 2, 0, Qt::AlignCenter);

	mainLayout->addWidget(exit_button, 3, 0, Qt::AlignCenter);



}



Menu::~Menu() {

	delete play_button;

	delete exit_button;

	delete volumeSlider;

	delete mainLayout;

}

void Menu::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}



void TankApp::play() {

	setupGame();

}





void TankApp::quit() {

	exit(0);

}