#include "Minesweeper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/Resources/mineBig.png"));
	Minesweeper w;
	w.show();
	return a.exec();
}
