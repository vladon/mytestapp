#include "MyCefObj.h"


MyCefObj::MyCefObj(QThread *thread, std::string CefHomeUrl)
{
	moveToThread(thread);

	sandbox_info = nullptr;

	main_args = new CefMainArgs(NULL);

	_CefApp = new MyCefApp(CefHomeUrl);

	// ...
	// establishing CEF settings, no sandbox, paths etc.
	// ...

	CefInitialize(*main_args, settings, _CefApp.get(), sandbox_info);
	CefRunMessageLoop();
}


MyCefObj::~MyCefObj()
{
	CefShutdown();
}
