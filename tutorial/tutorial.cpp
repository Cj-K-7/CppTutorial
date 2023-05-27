#include <iostream>
#include <windows.h>
#include <winspool.h>

using namespace std;

BOOL GetJobs(HANDLE hPrinter,        /* Handle to the printer. */

    JOB_INFO_2** ppJobInfo, /* Pointer to be filled.  */
    int* pcJobs,            /* Count of jobs filled.  */
    DWORD* pStatus)         /* Print Queue status.    */

{

    DWORD               cByteNeeded,
        nReturned,
        cByteUsed;
    JOB_INFO_2* pJobStorage = NULL;
    PRINTER_INFO_2* pPrinterInfo = NULL;

    /* Get the buffer size needed. */
    if (!GetPrinter(hPrinter, 2, NULL, 0, &cByteNeeded))
    {
        if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
            return FALSE;
    }

    pPrinterInfo = (PRINTER_INFO_2*)malloc(cByteNeeded);
    if (!(pPrinterInfo))
        /* Failure to allocate memory. */
        return FALSE;

    /* Get the printer information. */
    if (!GetPrinter(hPrinter,
        2,
        (LPBYTE)pPrinterInfo,
        cByteNeeded,
        &cByteUsed))
    {
        /* Failure to access the printer. */
        free(pPrinterInfo);
        pPrinterInfo = NULL;
        return FALSE;
    }

    /* Get job storage space. */
    if (!EnumJobs(hPrinter,
        0,
        pPrinterInfo->cJobs,
        2,
        NULL,
        0,
        (LPDWORD)&cByteNeeded,
        (LPDWORD)&nReturned))
    {
        if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
        {
            free(pPrinterInfo);
            pPrinterInfo = NULL;
            return FALSE;
        }
    }

    pJobStorage = (JOB_INFO_2*)malloc(cByteNeeded);
    if (!pJobStorage)
    {
        /* Failure to allocate Job storage space. */
        free(pPrinterInfo);
        pPrinterInfo = NULL;
        return FALSE;
    }

    ZeroMemory(pJobStorage, cByteNeeded);

    /* Get the list of jobs. */
    if (!EnumJobs(hPrinter,
        0,
        pPrinterInfo->cJobs,
        2,
        (LPBYTE)pJobStorage,
        cByteNeeded,
        (LPDWORD)&cByteUsed,
        (LPDWORD)&nReturned))
    {
        free(pPrinterInfo);
        free(pJobStorage);
        pJobStorage = NULL;
        pPrinterInfo = NULL;
        return FALSE;
    }

    /*
            *  Return the information.
            */
    *pcJobs = nReturned;
    *pStatus = pPrinterInfo->Status;
    *ppJobInfo = pJobStorage;
    free(pPrinterInfo);

    return TRUE;

}


int main() {
HANDLE hPrinter;
wchar_t szPrinter[MAX_PATH];

JOB_INFO_2* pJobs;
int         cJobs,
i;
DWORD       dwPrinterStatus;
wchar_t printerName[260] = L"printerName";

DWORD cchPrinter(ARRAYSIZE(szPrinter));
GetDefaultPrinter(szPrinter, &cchPrinter);
OpenPrinter(printerName, &hPrinter, NULL);


if (!GetJobs(hPrinter, &pJobs, &cJobs, &dwPrinterStatus)) {
    cout << "get Printer's Job Failed" << endl;

}

//cout << dwPrinterStatus << endl;


wstring ws(printerName);
string str(ws.begin(), ws.end());
cout << str << endl;

while (true) {
    cout << "no end" << endl;
}

return FALSE;
}