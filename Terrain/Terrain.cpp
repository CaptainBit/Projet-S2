//
// Created by fiset on 2020-02-13.
//

#include "Terrain.h"

Terrain::Terrain(int longueurTerrain, int hauteurMax) {
	m_longueurTerrain = longueurTerrain;
	m_terrain = new int[longueurTerrain];
	m_hauteurMax = hauteurMax;
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
	srand((unsigned)time(0));
	int dimensionDepart = 0;
	dimensionDepart = nombreAleatoire(1, m_hauteurMax);
	bool terrainGenerer = false;
	int positionTerrain = 0;
	int sensPente = 0;
	int nombreAjouter = 0;

	while (!terrainGenerer)
	{
		int longueurAleatoire = nombreAleatoire(4, 8);
		int pente = nombreAleatoire(1, 3);

		if (positionTerrain == 0 || sensPente == 2)
			sensPente = nombreAleatoire(0, 2);
		else
			sensPente = 2;

		

		for (int i = nombreAjouter; i < longueurAleatoire + positionTerrain; i++)
		{
			int hauteurGenerer = 0;


			if (i == 0)
			{
				hauteurGenerer = nombreAleatoire(m_hauteurMax/4, 3 * m_hauteurMax / 4);
			}
			else
			{
				if (sensPente == 0)
					hauteurGenerer = m_terrain[i - 1] - pente;
				else if (sensPente == 1)
					hauteurGenerer = m_terrain[i - 1] + pente;
				else if (sensPente == 2)
					hauteurGenerer = m_terrain[i - 1];
			}

			if (i >= m_longueurTerrain)
			{
				terrainGenerer = true;
				break;
			}

			if (hauteurGenerer > m_hauteurMax || hauteurGenerer < 1)
			{
				break;
			}

			m_terrain[i] = hauteurGenerer;
			for (int x = 0; x < hauteurGenerer; x++)
			{
				cout << "O";
			}
			cout << endl;
			nombreAjouter++;
		}
		positionTerrain += longueurAleatoire;
	}
	
}