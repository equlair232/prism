#include "App.h"

void App::Run()
{
	this->Start();
	this->Update();
}

void App::Start()
{
	_window = std::make_unique<Win32UI>(1920, 1080);

	_window->InitMainWindow(L"prism");
}

void App::Update()
{
	while (true)
	{
		if (_window->IsQuit())
		{
			break;
		}
	}
}
