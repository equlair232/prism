#pragma once

#include <Windows.h>
#include <string>

class Win32UI
{
public:
	Win32UI(std::int16_t windowWidth, std::int16_t windowHeight);
	~Win32UI() = default;

	void InitMainWindow(const wchar_t* windowName);
	HWND& GetHwnd();
	bool IsQuit();

private:
	std::int16_t _windowWidth;
	std::int16_t _windowHeight;
	WNDCLASSEX _windowClass;
	HWND _hwnd;
	RECT _wrc;
	MSG _msg;
};
