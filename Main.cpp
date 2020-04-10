//
// Created by fiset on 2020-02-11.
//
#include "GameManager/GameManager.h"
#include <iostream>
#include "Terrain/Terrain.h"
#include "UI\UI.h"
#include <QApplication>

int main (int argc, char *argv[]) {
	GameManager game;

	QApplication app(argc, argv);
	UI ui;
	ui.show();
	
	// GameManager settings to add

	return app.exec();

}