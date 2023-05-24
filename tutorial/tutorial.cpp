#include <iostream>
#include <windows.h>
#include <winspool.h>

using namespace std;


int main() {
HANDLE hdl;
wchar_t szPrinter[MAX_PATH];

DWORD cchPrinter(ARRAYSIZE(szPrinter));
GetDefaultPrinter(szPrinter, &cchPrinter);
OpenPrinter(szPrinter, &hdl, NULL);

	return 0;
}