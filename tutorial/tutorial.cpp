#include <windows.h>;
#include <winspool.h>;

int main() {
    DWORD numprinters;
    DWORD defprinter = 0;
    DWORD               dwSizeNeeded = 0;
    DWORD               dwItem;
    LPPRINTER_INFO_2    printerinfo = NULL;

    // Get buffer size

    EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 2, NULL, 0, &dwSizeNeeded, &numprinters);

    // allocate memory
    //printerinfo = (LPPRINTER_INFO_2)HeapAlloc ( GetProcessHeap (), HEAP_ZERO_MEMORY, dwSizeNeeded );
    printerinfo = (LPPRINTER_INFO_2)new char[dwSizeNeeded];

    if (EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,      // what to enumerate
        NULL,           // printer name (NULL for all)
        2,              // level
        (LPBYTE)printerinfo,        // buffer
        dwSizeNeeded,       // size of buffer
        &dwSizeNeeded,      // returns size
        &numprinters            // return num. items
    ) == 0)
    {
        numprinters = 0;
    }

    {
        DWORD size = 0;

        // Get the size of the default printer name.
        GetDefaultPrinter(NULL, &size);
        if (size)
        {
            // Allocate a buffer large enough to hold the printer name.
            TCHAR* buffer = new TCHAR[size];

            // Get the printer name.
            GetDefaultPrinter(buffer, &size);

            for (dwItem = 0; dwItem < numprinters; dwItem++)
            {
                if (!strcmp(buffer, printerinfo[dwItem].pPrinterName))
                    defprinter = dwItem;
            }
            delete buffer;
        }
    }
}