//
// Created by fiset on 2020-02-11.
//
#include "GameManager/GameManager.h"
#include <iostream>
#include <conio.h>

int main (int argc, char *argv[]) {
<<<<<<< Updated upstream
	GameManager gm();
	gm.start_game();
	while (gm.getStatus()) {
		gm.en_jeu(getch());
=======
	GameManager gm;
	gm.start_game();
	while (gm.getStatus()) {
		gm.en_jeux(_getch());
>>>>>>> Stashed changes
	}
}