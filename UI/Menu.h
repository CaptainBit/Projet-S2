/*
Classe du menu du jeu
*/
#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSlider>
#include <QStyleOption>
#include <QPainter>

class Menu : public QWidget
{
	Q_OBJECT
public:
	Menu();
	~Menu();

	QGridLayout* mainLayout;//Layout contenant les bouttons
	QPushButton* play_button;//Bouton de démarrage de la partie
	QPushButton* exit_button;//Bouton de femeture du programme
	QSlider* volumeSlider;//Slider modifiant le volume de la musique
	void paintEvent(QPaintEvent *);
};

#endif // !MENU_H