#include "./UI/Menu.h"
Menu::Menu()

{

	//Declaration des pointeurs
	mainLayout = new QGridLayout(this);

	play_button = new QPushButton("JOUER");

	exit_button = new QPushButton("SORTIR");

	volumeSlider = new QSlider(Qt::Horizontal, this);

	play_button->setFixedSize(70, 30);

	exit_button->setFixedSize(70, 30);

	volumeSlider->setFixedWidth(100);
	volumeSlider->setRange(0, 100);
	volumeSlider->setValue(0);


	//Set background image
	mainLayout->addWidget(volumeSlider, 1, 0, Qt::AlignRight);

	mainLayout->addWidget(play_button, 2, 0, Qt::AlignCenter);

	mainLayout->addWidget(exit_button, 3, 0, Qt::AlignCenter);



}

Menu::~Menu() {

	delete play_button;

	delete exit_button;

	delete volumeSlider;

	delete mainLayout;

}

void Menu::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
