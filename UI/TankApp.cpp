#include "TankApp.h"
#include "QStatusBar"

TankApp::TankApp(int &argc, char **argv)

	:QApplication(argc, argv)

{
	//Initialisation du fichier qss
	QFile qss("./Ressources/style.qss");
	qss.open(QFile::ReadOnly);
	this->setStyleSheet(qss.readAll());
	qss.close();

	mainWindow = new QMainWindow;

	//Initialisation de la barre démontrant les controls
	QStatusBar controlBar;
	controlBar.setSizeGripEnabled(false);
	QWidget controlWidget;
	QHBoxLayout controlLayout(&controlWidget);
	QLabel control("A & D: Droite/Gauche | W & S:  Augmenter/Diminuer le canon | R & F: Augmenter/Diminuer la puissance | E: Tirer | 1,2,3 : Type de projectile");
	control.setObjectName("Control");
	controlWidget.setObjectName("Control");
	controlLayout.addWidget(&control, 1, Qt::AlignCenter);
	controlBar.addWidget(&controlWidget, 1);
	mainWindow->setStatusBar(&controlBar);

	//Initialisation de la fenêtre
	mainWindow->setFixedSize(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
	mainWindow->setWindowTitle("Tank War - P15");
	mainWindow->show();
	setupMenu();
	exec();

}



TankApp::~TankApp() {
	if (music != nullptr)
		delete music;
	if (menu != nullptr)
		delete menu;
	if (game != nullptr)
		delete game;
	delete mainWindow;
}


//Création et affichage du menu principale
void TankApp::setupMenu() {

	menu = new Menu();

	//Démarage de la musique du menu
	music = new QMediaPlayer;
	music->setMedia(QUrl::fromLocalFile("./Ressources/Sons/play_2.wav"));
	music->play();
	music->setVolume(0);

	//Connect des boutons et slider du menu
	connect(menu->play_button, SIGNAL(clicked()), this, SLOT(setupGame()));
	connect(menu->exit_button, SIGNAL(clicked()), this, SLOT(quit()));
	connect(menu->volumeSlider, SIGNAL(valueChanged(int)), music, SLOT(setVolume(int)));

	mainWindow->setCentralWidget(menu);
}


//Création et affichage du jeu
void TankApp::setupGame() {
	delete menu;
	menu = nullptr;

	game = new Interface;

	mainWindow->setCentralWidget(game);
	game->setFocus();
	game->show();
}

//Ferme l'application
void TankApp::quit() {
	exit(0);
}