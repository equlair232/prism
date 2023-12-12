#pragma once

#include <memory>
#include "Win32UI.h"

class App
{
public:
	App() = default;
	~App() = default;

	void Run();

private:
	std::unique_ptr<Win32UI> _window;

	void Start();
	void Update();
};
