#include "MyCefObj.h"


MyCefObj::MyCefObj(QThread *thread, std::string CefHomeUrl)
{
	qDebug("MyCefObj()");

	_CefHomeUrl = CefHomeUrl;

	moveToThread(thread);

	connect(thread, SIGNAL(started()), this, SLOT(start());


	qDebug("MyCefObj() ->");
}

void MyCefObj::start()
{
	sandbox_info = nullptr;

	main_args = new CefMainArgs(NULL);

	_CefApp = new MyCefApp(_CefHomeUrl);

	CefString(&settings.browser_subprocess_path).FromASCII("mytestapp_subprocess.exe");

	settings.no_sandbox = true;

	// completely disable log
	settings.log_severity = LOGSEVERITY_DISABLE;

	settings.command_line_args_disabled = true;


	CefInitialize(*main_args, settings, _CefApp.get(), sandbox_info);
	CefRunMessageLoop();

	CefShutdown();
}

MyCefObj::~MyCefObj()
{
	qDebug("~MyCefObj()");

}
