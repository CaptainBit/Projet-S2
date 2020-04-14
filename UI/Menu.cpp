#include "./UI/Menu.h"
Menu::Menu()

{

	//Declaration des pointeurs
	mainLayout = new QGridLayout(this);

	play_button = new QPushButton();
	play_button->setObjectName("Jouer");

	exit_button = new QPushButton();
	exit_button->setObjectName("Sortir");

	volumeSlider = new QSlider(Qt::Horizontal, this);



	volumeSlider->setFixedWidth(100);
	volumeSlider->setRange(0, 100);
	volumeSlider->setValue(0);
	volume=new QWidget();
	volume->setObjectName("Control");
	hbox=new QHBoxLayout(volume);
	volumeLabel=new QLabel("Musique: ");
	volumeLabel->setObjectName("Control");
	hbox->addWidget(volumeLabel);
	hbox->addWidget(volumeSlider);


	//Positionement du menu
	mainLayout->addWidget(volume, 0, 0, Qt::AlignRight);

	mainLayout->addWidget(play_button,2, 0, Qt::AlignCenter);

	mainLayout->addWidget(exit_button, 3, 0, Qt::AlignCenter);

	mainLayout->setRowStretch(1, 1);
	mainLayout->setRowStretch(4, 1);
	mainLayout->setSpacing(10);


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
