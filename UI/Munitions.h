#ifndef MUNITIONS_H
#define MUNITIONS_H

#include <QWidget>
#include <QRadioButton>
#include <QHboxLayout>

class Munitions :public QWidget {
	Q_OBJECT
public:
	Munitions();
	~Munitions();
private:
	QHBoxLayout * layout;//Layout contenant les 3 types de munition
	QRadioButton* munitions1;//Bouton pour le type de munition 1
	QRadioButton* munitions2;//Bouton pour le type de munition 2
	QRadioButton* munitions3;//Bouton pour le type de munition 3
public slots:
	void select(int munition);//Change le type de munition sélectionné (1,2,3)
};
#endif