#include "MiniSudokuCalc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MiniSudoCalc w;
	w.show();
	return a.exec();
}
