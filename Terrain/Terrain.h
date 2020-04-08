//
// Created by fiset on 2020-02-13.
//

#ifndef PROJET_TERRAIN_H
#define PROJET_TERRAIN_H

#include "../Vec2.h"
#include <ctime> 
#include "../generique.h"
#include <iostream>
#include "../UI/DosGraph.h"

using namespace std;

class Terrain {
public:
    Terrain(int longueurTerrain, int hauteurMax);
	void fragmenterTerrain(int x);
	~Terrain();
private:
	int* m_terrain;
	int m_longueurTerrain;
	int m_hauteurMax;
	void genererTerrain();
	

};


#endif //PROJET_TERRAIN_H
