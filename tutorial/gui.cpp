#include <Windows.h>

// �����ڵ�� ��Ƽ����Ʈ(ANSI) ��ȯ�� �ؾ��ϴ� ��츦 Ȯ���ؾ��Ѵ�.(���õ� ������ ����)
//    -TCHAR- 
// 
//  ANSI    UNI
//  CHAR   WCHAR
//  char  wchar_t
// 
//	 -LPTSTR-
// 
//  ANSI    UNI
//  LPSTR  LPWSTR
//  char*  wchar_t*
// 
// ANSI ���ڿ��� �����ڵ�� ��ȯ�ϴ� �Լ�
// LPTSTR str = TEXT("���ڿ�")


//hWnd :
// CALLBACK = __stdcall
// LRESULT = LONG_PTR

//Windows procedure : �޼��� ó�� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	// WPARAM = UINT_PTR = unsigned int
	// LPARAM = LONG_PTR = long
	// unsigned int = UINT

	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	case WM_PAINT:
		// ������ ����
		hdc = BeginPaint(hWnd, &ps);

		//�� �׸���

		// ������ ����
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:

		//�޸� ���� �ڵ���� ������

		PostQuitMessage(0); //WM_QUIT �߻�
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// hInstace : OS �� �������ϵ��� �����ϱ� ���ؼ� �Ҵ����ִ� ���� �� (���� ���α׷��� ���� ��)
// hPrevInstance : �׻� 0 ( ���� �ν��Ͻ��� ���� �� )
// lpCmdLine : ���α׷� �ܺο��� ���η� ���� �� ��
// nCmdShow : ������ ��� ���¿� ���� �� 
// * hInstance ���� ���

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//Make windows structure

	//�̹� ������ ����ü ���

	WNDCLASSEX wcex;

	//����ü ũ�� �¾�

	wcex.cbSize = sizeof(WNDCLASSEX);

	// ������ �̵� �� ũ�Ⱑ ���Ҷ� horizon / vertical �� ���� �ٽ� �׸���.

	wcex.style = CS_HREDRAW | CS_VREDRAW;

	// �Լ��� �޸� �ּҸ� �Լ� �����Ϳ� �Ҵ�.

	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"basic";

	RegisterClassEx(&wcex);

	//Create windows and return

	HWND hWnd = CreateWindow(L"basic", L"HELLO WORLD", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 720, NULL, NULL, hInstance, NULL);


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	//Loop message (input & output of message)

	while (GetMessage(&msg, NULL, 0, 0)) {

		//keyboard input event

		TranslateMessage(&msg);

		//dispatch = send to windows procedure ���ν����� �޼��� ������ �Լ�

		DispatchMessage(&msg);
	}
	return 0;
}
