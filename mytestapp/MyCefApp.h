#ifndef MYCEFAPP_H
#define MYCEFAPP_H

#pragma once

#include <include/cef_app.h>

class MyCefApp :
	public CefApp,
	public CefBrowserProcessHandler
{
public:
	MyCefApp(std::string url = "");

	// CefApp:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE{
		return this;
	}

	// CefBrowserProcessHandler:
	virtual void OnContextInitialized() OVERRIDE;

private:
	std::string _url;

	IMPLEMENT_REFCOUNTING(MyCefApp);
};

#endif // GSBROWSERAPP_H