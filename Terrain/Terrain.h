//
// Created by fiset on 2020-02-13.
//

#ifndef PROJET_TERRAIN_H
#define PROJET_TERRAIN_H

#include "../Vec2.h"
#include <ctime> 
#include "generique.h"
#include <iostream>
#include <QWidget>
#include <QPolygon>
#include <QPaintEvent>
#include <QPoint>
#include <vector>

using namespace std;

class Terrain :public QWidget{
public:
    Terrain(int longueurTerrain, int hauteurMax,int hauteurFenetre, QWidget *parent);
	void fragmenterTerrain(int x);
	~Terrain();
	QPolygon rectangle;
	int getHauteur(int i);
private:
	vector<QPoint> points;
	int* m_terrain;
	int m_hauteurFenetre;
	int m_longueurTerrain;
	int m_hauteurMax;
	void genererTerrain();
	void paintEvent(QPaintEvent* event) override;

};
#endif //PROJET_TERRAIN_H