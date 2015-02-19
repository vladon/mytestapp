#include "MyCoreApp.h"

// main:

int main(int argc, char *argv[])
{
	qDebug("Test");

	MyCoreApp a(argc, argv);

	int result = 0;

	// whether I call a.exec() or not, behavior is the same
	result = a.exec();

	return result;
}
