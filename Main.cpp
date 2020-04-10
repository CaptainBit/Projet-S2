//
// Created by fiset on 2020-02-11.
//
#include "GameManager/GameManager.h"
#include <iostream>
#include "Terrain/Terrain.h"
#include "UI\UI.h"
#include <QApplication>

int main (int argc, char *argv[]) {

	QApplication app(argc, argv);
	UI ui;
	ui.show();
	return app.exec();

}