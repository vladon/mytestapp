// mytestapp_subprocess.cpp : Defines the entry point for the application.
//

#include "mytestapp_subprocess.h"

#include <include/cef_app.h>

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CefMainArgs main_args(GetModuleHandle(NULL));

	//	CefRefPtr<GSBrowserApp> app(new GSBrowserApp);

	return CefExecuteProcess(main_args, NULL, NULL);
}
