/*
Classe gerant l'application au plus haut niveau
*/
#ifndef TANKAPP_H
#define TANKAPP_H

#include <QApplication>
#include <QMediaPlayer>
#include <QMainWindow>

#include "menu.h"
#include "Interface.h"

class TankApp : public QApplication
{
	Q_OBJECT
public:
	TankApp(int &argc, char **argv);
	~TankApp();

private:
	QMainWindow * mainWindow;//Fenêtre principale de l'application
	Menu *menu = nullptr;//Menu principale
	Interface *game = nullptr;//Widget du jeu
	QMediaPlayer* music = nullptr;//Lecteur de musique

public slots:
	void quit();//Ferme l'application
	void setupGame();//Création et affichage du jeu
	void setupMenu();//Création et affichage du menu principale
};
#endif // !TANKAPP_H