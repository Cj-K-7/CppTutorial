#include <iostream>
#include <Windows.h>
#include <string>
#include "Windows.h"

using namespace std;

int main(int argc, char* argv[])
{
	//std::cout << "Creating Window\n";

	//Window* pWindow = new Window();
	//HWND handle = pWindow->findHandle();
	//std::cout << "Found window: " << handle << std::endl;

	//bool running = true;

	//while (running) {
	//	if (!pWindow->ProcessMessages()) {
	//	std:cout << "Closing Window\n";
	//		running = false;

	//	}
	//}



	//	Sleep(10);

	//	delete pWindow;
	//return 0;

	if (argc > 1 && std::string(argv[1]) == "--wait_exit") {
		HANDLE hProcess = (HANDLE)std::stoul(argv[2]);
		WaitForSingleObject(hProcess, INFINITE);
		CloseHandle(hProcess);
	}
	else {
		HANDLE hProcess = GetCurrentProcess();
		HANDLE hDupHandle;

		if(!DuplicateHandle(hProcess, hProcess, hProcess, &hDupHandle, 0 , TRUE, DUPLICATE_SAME_ACCESS)){
			std::cerr << "Dup failed" << GetLastError() << std::endl;
			return -1;
			WCHAR szPath[MAX_PATH];
			if (!GetModuleFileName(NULL, szPath, MAX_PATH)) {
				std::cerr << "get module failed" << GetLastError() << std::endl;
				return -1;

			}
			STARTUPINFO si = {
				sizeof(si)
			};
			PROCESS_INFORMATION pi;
			std::string cmdLine = std::string("\"") + szPath + "\"--wait_exit " + std::to_string((ULONG_PTR)hDupHandle);

			if (!CreateProcess(NULL, &cmdLine[0], NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
				std::cerr << "get module failed" << GetLastError() << std::endl;
				return -1;
	
			
		}
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
	}


		return 0;
	}


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
