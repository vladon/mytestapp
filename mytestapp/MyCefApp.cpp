#include "MyCefApp.h"

#include <include/cef_browser.h>
#include <include/cef_command_line.h>
#include <include/wrapper/cef_helpers.h>

#include "MyCefHandler.h"

#include <string>


MyCefApp::MyCefApp(std::string url)
{
	_url = url;
}

void MyCefApp::OnContextInitialized()
{
	CEF_REQUIRE_UI_THREAD();

	CefWindowInfo window_info;

#if defined(OS_WIN)
	window_info.SetAsPopup(NULL, "MyBrowser");
#endif // OS_WIN

	CefRefPtr<MyCefHandler> handler(new MyCefHandler());

	CefBrowserSettings browser_settings;

	if (_url.empty()) {
		this->_url = "http://www.google.com";
	}

	CefBrowserHost::CreateBrowser(window_info, handler.get(), this->_url, browser_settings, NULL);
}