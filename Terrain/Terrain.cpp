//
// Created by fiset on 2020-02-13.
//

#include "Terrain.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPoint>
#include <QLinearGradient>
#include <QColor>
#include "Interface.h"
#define LOWEST 50
Terrain::Terrain(int longueurTerrain, int hauteurMax,int hauteurFenetre, QWidget *parent): QWidget(parent) {
	m_longueurTerrain = longueurTerrain;
	m_hauteurFenetre = hauteurFenetre;
	m_terrain = new int[longueurTerrain];
	m_hauteurMax = hauteurMax;
	setFixedHeight(hauteurFenetre);
	setFixedWidth(longueurTerrain);
	genererTerrain();
}

Terrain::~Terrain()
{
	delete[] m_terrain;
}

void Terrain::fragmenterTerrain(int x)
{

}

void Terrain::genererTerrain()
{
	bool terrainGenerer = false;
	int positionTerrain =0;
	int sensPente = 0;

	while (!terrainGenerer)
	{
		int longueurAleatoire = nombreAleatoire(20, 40);
		int pente = nombreAleatoire(1, 2);

		if (positionTerrain == 0 || sensPente == 2)
			sensPente = nombreAleatoire(0, 2);
		else
			sensPente = 2;
		
		
		int startPos = positionTerrain;
		while(positionTerrain<longueurAleatoire+ startPos)
		{
			int hauteurGenerer = 0;


			if (positionTerrain == 0)
			{
				hauteurGenerer = nombreAleatoire(m_hauteurMax/4, 3 * m_hauteurMax / 4 + LOWEST);
			}
			else
			{
				if (sensPente == 0)
					hauteurGenerer = m_terrain[positionTerrain- 1] - pente;
				else if (sensPente == 1)
					hauteurGenerer = m_terrain[positionTerrain- 1] + pente;
				else if (sensPente == 2)
					hauteurGenerer = m_terrain[positionTerrain- 1];
			}

			if (positionTerrain >= m_longueurTerrain)
			{
				terrainGenerer = true;
				break;
			}

			if (hauteurGenerer > m_hauteurMax || hauteurGenerer < LOWEST)
			{
				break;
			}
			
			m_terrain[positionTerrain] = hauteurGenerer;
			positionTerrain++;
		}
		points.push_back(QPoint(positionTerrain-1, m_hauteurFenetre-m_terrain[positionTerrain-1]));
	}
	cout << "Terrain Generer";
	
}
void Terrain::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	rectangle << QPoint(m_longueurTerrain, m_hauteurFenetre);
	rectangle << QPoint(0, m_hauteurFenetre);
	rectangle << QPoint(0, m_hauteurFenetre - m_terrain[0]);
	for (int i = 0; i < points.size(); i++) {
		rectangle << points[i];
	}
	QLinearGradient gradient(0,m_hauteurFenetre/5,0,m_hauteurFenetre);
	gradient.setColorAt(0, QColor(195, 149, 78));
	gradient.setColorAt(0.7, QColor(195, 149, 78));
	gradient.setColorAt(1, QColor(110, 83, 41));
	QBrush brush(gradient);
	brush.setStyle(Qt::LinearGradientPattern);
	QPainterPath path;
	path.addPolygon(rectangle);

	painter.drawPolygon(rectangle);
	painter.fillPath(path, brush);
}
int Terrain::getHauteur(int i) {
	return m_hauteurFenetre-m_terrain[i];
}