#pragma once

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWind, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
public:
	Window();
	Window(const Window&) = delete;
	Window& operator = (const Window&) = delete;
	~Window();

	bool ProcessMessages();
	HWND findHandle();

private:
	HINSTANCE m_hinstance;
	HWND m_hWnd;
};
