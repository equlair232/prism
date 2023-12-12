#include <Windows.h>
#include <memory>
#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto app = std::make_unique<App>();
	app->Run();

	return 0;
}