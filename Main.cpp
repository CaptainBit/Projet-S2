//
// Created by fiset on 2020-02-11.
//
#include "GameManager/GameManager.h"
#include <iostream>

int main (int argc, char *argv[]) {
	GameManager gm();
	gm.start_game();
	while (gm.getStatus()) {
		gm.en_jeu(getch());
	}
}