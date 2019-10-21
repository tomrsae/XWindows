#include "XWindows.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XWindows w;
	w.show();
	return a.exec();
}
