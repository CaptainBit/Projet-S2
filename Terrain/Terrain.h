/*
Classe de génération et gestion du terrain
*/


#ifndef PROJET_TERRAIN_H
#define PROJET_TERRAIN_H

#include "../Vec2.h"
#include <ctime> 
#include "generique.h"
#include <QWidget>
#include <QPolygon>
#include <QPoint>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>
#include <QBrush>
#include <QPainterPath>
#include <QColor>

using namespace std;

class Terrain :public QWidget {
public:
	Terrain(int longueurTerrain, int hauteurMax, int hauteurFenetre, QWidget *parent);
	~Terrain();
	QPolygon formeTerrain;//Polygone représenant le terrain visuellement
	int getHauteur(int i);//Retourne la hauteur du terrain sur l'écran
private:
	vector<QPoint> points;
	int* m_terrain;//Tableau contenant toutes les hauteurs du terrain
	int m_hauteurFenetre;//Hauteur du widget contenant le terrain
	int m_longueurTerrain;//Longeur du terrain
	int m_hauteurMax;//Hauteur maximale du terrain
	void genererTerrain();//Génération du terrain
	void paintEvent(QPaintEvent* event) override;//Affichage du terrain

};
#endif //PROJET_TERRAIN_H