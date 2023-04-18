#include "Calculator.h"

class Calculator
{
public:
    ~Calculator() {}
    Calculator()
    {
        a = 0;
        b = 0;
        result = 0;
        std::cout << "계산기 생성" << std::endl;
    }
    void Add(int x, int y)
    {
        a = x;
        b = y;
        result = a + b;
    }
    void Subtract(int x, int y)
    {
        a = x;
        b = y;
        result = a - b;
    }
    void ShowResult()
    {
        std::cout << "result : " << result << std::endl;
    }
private:
    int a;
    int b;
    int result;
};
int main()
{
    Calculator c;
    c.Add(1, 2);
    c.ShowResult();
    c.Subtract(1, 2);
    c.ShowResult();
}