#include "GameManager/GameManager.h"
#include <iostream>
#include <conio.h>
#include <QApplication>
#include "interface.h"
int main (int argc, char ** argv) {
	QApplication app(argc,argv);
	
	Interface inter;
	inter.show();
	return app.exec();
}