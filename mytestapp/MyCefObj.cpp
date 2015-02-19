#include "MyCefObj.h"


MyCefObj::MyCefObj(QThread *thread, std::string CefHomeUrl)
{
	moveToThread(thread);

	sandbox_info = nullptr;

	main_args = new CefMainArgs(NULL);

	_CefApp = new MyCefApp(CefHomeUrl);

	CefString(&settings.browser_subprocess_path).FromASCII("mytestapp_subprocess.exe");

	settings.no_sandbox = true;

	// completely disable log
	settings.log_severity = LOGSEVERITY_DISABLE;

	settings.command_line_args_disabled = true;


	CefInitialize(*main_args, settings, _CefApp.get(), sandbox_info);
	CefRunMessageLoop();
}


MyCefObj::~MyCefObj()
{
	CefShutdown();
}
