#include <windows.h>
#include <memory>
#include <iostream>


using namespace std;

int main()
{

    //two dimetional array
    int rows, cols;

    cout << "rows , cols :";
    cin >> rows >> cols;

    int** table = new int*[rows];
    for (int i = 0; i < rows; i++) {
        table[i] = new int[cols];
    }


    for (int i = 0; i < rows; i++) {
        delete[] table[i];
    }

    //life end
    delete[] table;
    table = NULL;

    system("pause>0");
    return 0;
}


