#include <iostream>
#include "Windows.h"

LRESULT CALLBACK WinProc(HWND hWind, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE: DestroyWindow(hWind);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWind, uMsg, wParam, lParam);
};

Window::Window(): m_hinstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"CJ window Class";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hinstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WinProc; // Fix later

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width = 640;
	int height = 480;

	RECT rect{};
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Title",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hinstance,
		NULL
	);

	hProcess = GetCurrentProcess();
	if (!OpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken)) {	}
	if (!DuplicateHandle(hProcess, hToken, hProcess, &hDupToken,0, FALSE, DUPLICATE_SAME_ACCESS)) {
	}

	if(GetModuleFileName(NULL, szPath, MAX_PATH)){}




	CloseHandle(hToken);
	CloseHandle(hDupToken);
	ShowWindow(m_hWnd, SW_SHOW);

}

Window::~Window()
{
	const wchar_t* CLASS_NAME = L"CJ window Class";

	UnregisterClass(CLASS_NAME, m_hinstance);
}

bool Window::ProcessMessages()
{
	MSG msg = {};
	
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			return false;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

HWND Window::findHandle()
{
	LPCSTR windowName = "just_do_it";
	HWND handle = FindWindowA(NULL, windowName);

	if (handle == NULL) {
		std::cout << "Could not find window" << std::endl;
	}
	else {
		std::cout << "Found window: " << handle << std::endl;
	}

	return handle;
}
