//
// Created by fiset on 2020-02-11.
//
#include "GameManager/GameManager.h"
#include <iostream>
#include <conio.h>

int main (int argc, char *argv[]) {
	recommencer:
	GameManager gm;
	gm.start_game();
	while (gm.getStatus()) {
		gm.en_jeux(_getch());
	}
	system("PAUSE");
	goto recommencer;
}