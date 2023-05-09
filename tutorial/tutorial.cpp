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

//Windows procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
// WPARAM = UINT_PTR = unsigned int
// LPARAM = LONG_PTR = long
// unsigned int = UINT
	switch (message) {
	case: break;
		default
	: DefWindowProc();
	}
}

// hInstace : OS 가 실행파일들을 구별하기 위해서 할당해주는 고유 값 (같은 프로그램은 같은 값)
// hPrevInstance : 항상 0 ( 이전 인스턴스에 대한 값 )
// lpCmdLine : 프로그램 외부에서 내부로 값을 줄 때
// nCmdShow : 윈도우 출력 형태에 관한 값 
// * hInstance 거의 사용

int WINAPI WinMain(HINSTANCE hInstance,  HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Make windows structure


	//Create windows and return


	//Loop message (input & output of message)
	while (GetMessage(&msg, NULL, 0 ,0)) {
		//keyboard input event
		TranslateMessage(&msg);
		//dispatch = send to windows procedure
		DispatchMessage(&msg);
	}
	return 0;
}
