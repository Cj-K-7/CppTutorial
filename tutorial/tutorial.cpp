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

// hInstace : OS �� �������ϵ��� �����ϱ� ���ؼ� �Ҵ����ִ� ���� �� (���� ���α׷��� ���� ��)
// hPrevInstance : �׻� 0 ( ���� �ν��Ͻ��� ���� �� )
// lpCmdLine : ���α׷� �ܺο��� ���η� ���� �� ��
// nCmdShow : ������ ��� ���¿� ���� �� 
// * hInstance ���� ���

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
