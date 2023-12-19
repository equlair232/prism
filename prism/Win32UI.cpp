#include "Win32UI.h"

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Win32UI::Win32UI(std::int16_t windowWidth, std::int16_t windowHeight)
{
	_windowWidth = windowWidth;
	_windowHeight = windowHeight;
	_windowClass = {};
	_hwnd = nullptr;
	_wrc = {};
	_msg = {};
}

void Win32UI::InitMainWindow(const wchar_t* windowName)
{
	_windowClass.cbSize = sizeof(WNDCLASSEX);
	_windowClass.lpfnWndProc = (WNDPROC)WindowProcedure;
	_windowClass.lpszClassName = windowName;
	_windowClass.hInstance = GetModuleHandle(nullptr);

	RegisterClassEx(&_windowClass);

	_wrc = { 0, 0, _windowWidth, _windowHeight };

	AdjustWindowRect(&_wrc, WS_OVERLAPPEDWINDOW, false);

	_hwnd = CreateWindow(_windowClass.lpszClassName,
		windowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		_wrc.right - _wrc.left,
		_wrc.bottom - _wrc.top,
		nullptr,
		nullptr,
		_windowClass.hInstance,
		nullptr);

	ShowWindow(_hwnd, SW_SHOW);
}

HWND& Win32UI::GetHwnd()
{
	return _hwnd;
}

bool Win32UI::IsQuit()
{
	if (PeekMessage(&_msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&_msg);
		DispatchMessage(&_msg);

		if (_msg.message == WM_QUIT)
		{
			return true;
		}
	}

	return false;
}
