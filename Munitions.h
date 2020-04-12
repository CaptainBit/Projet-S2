#ifndef MUNITIONS_H
#define MUNITIONS_H

#include <QWidget>
#include <QRadioButton>
#include <QHboxLayout>

class Munitions :public QWidget {
public:
	Munitions();
	~Munitions();
private:
	QHBoxLayout* layout;
	QRadioButton* munitions1;
	QRadioButton* munitions2;
	QRadioButton* munitions3;
};
#endif