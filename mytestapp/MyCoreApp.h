#pragma once
#include <QtCore/QCoreApplication>
#include <QtCore/QThread>
#include <QtCore/QDebug>
#include "MyCefObj.h"

class MyCoreApp :
	public QCoreApplication
{
	Q_OBJECT

public:
	MyCoreApp(int &argc, char **argv);
	~MyCoreApp();

signals:

	public slots :
		void OnCefFinished();

private:
	QThread *_CefThread;
	MyCefObj *_CefObj;

	CefRefPtr<MyCefApp> _MyCefApp;

	void ShowCef(std::string url);
};

