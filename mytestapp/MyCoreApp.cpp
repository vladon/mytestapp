#include "MyCoreApp.h"


MyCoreApp::MyCoreApp(int &argc, char **argv) :
	QCoreApplication(argc, argv),
	_CefThread(0),
	_CefObj(0)
{
	// ...
	// some initialization procedures
	// ...

	ShowCef("http://www.google.com");
}

void MyCoreApp::ShowCef(std::string url)
{
	_CefThread = new QThread();
	connect(_CefThread, SIGNAL(finished()), this, SLOT(OnCefFinished()));
	_CefObj = new MyCefObj(_CefThread, url);
	_CefThread->start();
}

MyCoreApp::~MyCoreApp()
{
}

void MyCoreApp::OnCefFinished()
{
	// never executed
	qDebug() << "OnCefFinished";

	if (_CefThread) {
		_CefThread->deleteLater();
	}
	this->quit();
}
