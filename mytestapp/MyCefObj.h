#pragma once
#include <QtCore/QObject>
#include <QtCore/QThread>
#include "MyCefApp.h"

class MyCefObj :
	public QObject
{
	Q_OBJECT

public:
	MyCefObj(QThread *thread, std::string CefHomeUrl);
	~MyCefObj();

	public slots:
	void start();

private:
	CefRefPtr<MyCefApp> _CefApp;
	std::string _CefHomeUrl;

	void * sandbox_info;

	// Global CEF settings
	CefSettings settings;

	CefMainArgs * main_args;
};

