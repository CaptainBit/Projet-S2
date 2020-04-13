#ifndef INTERFACE_H
#define INTERFACE_H

#include <qapplication.h>
#include <qpushbutton.h>
#include <QSound>
#include <QMediaPlayer>
#include <qslider.h>

#include <QMainWindow>
#include <QWidget>
#include <QProgressBar>
#include <QKeyEvent>
#include <QPixmap>
#include <QLabel>
#include <QPolygon>
#include <QPaintEvent>
#include <QGridLayout>
#include <QToolBar>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "../Tank.h"
#include "../Terrain/Terrain.h"
#include "../GameManager/GameManager.h"
#include "../Munitions.h"
#define HAUTEUR_FENETRE  720
#define LONGUEUR_FENETRE  1280

class Interface :public QWidget {
	Q_OBJECT
private:
	Joueur* joueur1;
	Joueur* joueur2;
	QProgressBar* health_p1;
	QProgressBar* health_p2;
	QProgressBar* deplacement_p1;
	QProgressBar* deplacement_p2;
	Tank* tank1;
	Tank* tank2;
	Terrain* terrain;
	QPolygon rectangle;
	QWidget* centralWidget;
	QWidget* barres;
	QWidget* zoneDeJeu;
	QVBoxLayout* disposition;
	QGridLayout* hud;
	GameManager* gm;
	Munitions* munitionsPlayer1;
	Munitions* munitionsPlayer2;
	QLabel* tour; 
public:
	Interface();
	~Interface();
	void keyPressEvent(QKeyEvent* event);
	void paintEvent(QPaintEvent *);
public slots:
	void changerTour(string);
};

class Menu : public QWidget
{
	Q_OBJECT
public:
	Menu();
	~Menu();

	QGridLayout* mainLayout;
	QPushButton* play_button;
	QPushButton* exit_button;
	QSlider* volumeSlider;
	void paintEvent(QPaintEvent *);
	
};

class TankApp : public QApplication
{
	Q_OBJECT
public:
	TankApp(int &argc, char **argv);
	~TankApp();

	
	

	QMainWindow* mainWindow;
	QWidget* CentralWidget;
	Menu *menu;
	Interface *game;
	QMediaPlayer* music;
	QWidget *control;
	QGridLayout *layoutControl;

public slots:
	void play();
	void quit();
	void setupGame();
	void setupMenu();


};


#endif
