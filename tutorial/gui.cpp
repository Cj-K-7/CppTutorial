#include <Windows.h>

// 유니코드와 멀티바이트(ANSI) 변환을 해야하는 경우를 확인해야한다.(세팅도 영향이 있음)
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
// ANSI 문자열을 유니코드로 변환하는 함수
// LPTSTR str = TEXT("문자열")


//hWnd :
// CALLBACK = __stdcall
// LRESULT = LONG_PTR

//Windows procedure : 메세지 처리 역할
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	// WPARAM = UINT_PTR = unsigned int
	// LPARAM = LONG_PTR = long
	// unsigned int = UINT

	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	case WM_PAINT:
		// 페인팅 시작
		hdc = BeginPaint(hWnd, &ps);

		//앱 그리기

		// 페인팅 종료
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:

		//메모리 해제 코드들이 들어가야함

		PostQuitMessage(0); //WM_QUIT 발생
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// hInstace : OS 가 실행파일들을 구별하기 위해서 할당해주는 고유 값 (같은 프로그램은 같은 값)
// hPrevInstance : 항상 0 ( 이전 인스턴스에 대한 값 )
// lpCmdLine : 프로그램 외부에서 내부로 값을 줄 때
// nCmdShow : 윈도우 출력 형태에 관한 값 
// * hInstance 거의 사용

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//Make windows structure

	//이미 정해진 구조체 사용

	WNDCLASSEX wcex;

	//구조체 크기 셋업

	wcex.cbSize = sizeof(WNDCLASSEX);

	// 윈도우 이동 및 크기가 변할때 horizon / vertical 에 따라 다시 그린다.

	wcex.style = CS_HREDRAW | CS_VREDRAW;

	// 함수의 메모리 주소를 함수 포인터에 할당.

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

		//dispatch = send to windows procedure 프로시져로 메세지 보내는 함수

		DispatchMessage(&msg);
	}
	return 0;
}
