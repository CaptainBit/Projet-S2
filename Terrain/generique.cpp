#include "generique.h"

int nombreAleatoire(int min, int max)
{
	return rand() % (max - min + 1) + min;
}