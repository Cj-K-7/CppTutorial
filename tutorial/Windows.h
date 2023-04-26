#pragma once

#include <Windows.h>

LRESULT CALLBACK WinProc(HWND hWind, UINT uMsg, WPARAM wParam, LPARAM lParam);

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
	HANDLE hProcess;
	HANDLE hToken;
	HANDLE hDupToken;
	TCHAR szPath[MAX_PATH];

};
