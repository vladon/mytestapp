#pragma once
#include <QtCore/QObject>
#include "MyCefApp.h"

class MyCefObj :
	public QObject
{
	Q_OBJECT

public:
	MyCefObj(QThread *thread, std::string CefHomeUrl);
	~MyCefObj();

private:
	CefRefPtr<MyCefApp> _CefApp;
	QString _CefHomeUrl;

	void * sandbox_info;

	// Global CEF settings
	CefSettings settings;

	CefMainArgs * main_args;
};

