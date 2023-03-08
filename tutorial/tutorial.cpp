#include <iostream>
using namespace std;

class Car {
    //all variables in class is private as default;
private:
    int wheels = 4;
    string Name;
    string Color;
    double Price;
    bool isBroken;
public:
    Car(string name, string color, double price) {
        Name = name;
        Color = color;
        Price = price;
        isBroken = false;
    }
    //print Information
    void getInfo() {
        cout << "Name : " << Name << endl;
        cout << "Color : " << Color << endl;
        cout << "Price : " << Price << endl;
    }
    //
    void crashCar() {
        cout << Name << " has been crashed" << endl;
        isBroken = true;
    }

    void fixCar() {
        cout << Name << " has been fixed" << endl;
        isBroken = false;
    }

    void move() {
        if (isBroken) {
            cout << Name << " is broken" << endl;
        }
        else {
            cout << Name << "is driving" << endl;
        }
    }
};

enum EyeColor
{
    Brown, Blue, Green, Black, Other
};


//function
float sum(float a, float b);
void introduceMe(string name, int* age = 0);

int main()
{
    cout << "Wellcome to C++ Crash Course\n";
    
    //Class
    Car myCar("Perari", "Black", 30000.0);
    myCar.getInfo();
    myCar.crashCar();
    myCar.move();
    myCar.fixCar();
    myCar.move();


    //Intergar => short & int & long
    short age = 25;
    age = 26;

    int num = 2147483647;

    cout << "value of variable 'num' is " << num << endl;

    num = 2147483648;

    cout << "value of variable 'num' is " << num << endl;

    long long longNum = 2147483648;

    cout << "value of variable 'longNum' is " << longNum << endl;


    //Real Number => float & double
    float floatPi = 3.1415926535897932;
    cout << "floatPi is " << floatPi << endl;

    double doublePi = 3.1415926535897932;
    cout << "doublePi is " << doublePi << endl;

    long double longFloatPi = 3.1415926535897932;
    cout << "longFloatPi is " << longFloatPi << endl;

    //character
    char gender = 'm';

    //string
    string username = "CodeBeauty";

    //boolean
    bool isTodaySunny = true;
    bool isTodayWeekend = true;

    //array
    string colors[10] = { "red", "green", " pink", "blue", "black" };

    //if else
    if (isTodaySunny && isTodayWeekend) {
        cout << "Go to the park" << endl;
    }
    else if (!isTodaySunny && isTodayWeekend) {
        cout << "Take an umbrella" << endl;
    }
    else
    {
        cout << "Go to work" << endl;
    }

    //isTodaySunny ? cout << "Go to the park" : cout << "Take an umbrella";

    //enum
    EyeColor eyeColor = Brown;

    //switch
    switch (eyeColor) {
    case Brown: cout << "80% of peaple have Brown eyes.\n"; break;
    case Blue: cout << "10% of peaple have Blue eyes.\n"; break;
    case Black: cout << "8% of peaple have Black eyes.\n"; break;
    case Green: cout << "1.5% of peaple have Green eyes.\n"; break;
    case Other: cout << "0.5% of peaple have Other eyes.\n"; break;
    default: cout << "Not Valid\n"; break;
    }

    //loop & iteration
    //while
    cout << "While:\n";
    int counter = 11; 
    while (counter <= 10) {
        cout << counter << endl;
        counter++;
    }

    //do while

    cout << "Do-While:\n";
    int counter2 = 11;

    do {
        cout << counter2 << endl;
        counter2++;
    } while (counter2 <= 10);

    //for

    string animals[5] = { "cat", "dog", "cow", "goat", "bee" };

    for (int i = 0; i < 5; i++) {
        cout << animals[i] << endl;
    }

    //function
    cout << sum(2.2, 5) << endl;


    //pointer 1
    int myAge = 30;

    introduceMe("changju", &myAge);

    cout << myAge << endl;

    //pointer 2
    int luckyNumbers[5] = { 1,3,5,7,9 };
    cout << luckyNumbers << endl;
    cout << &luckyNumbers[1] << endl;
    cout << luckyNumbers[1] << endl;

    int* luckyPointer = luckyNumbers;

    cout << "Pointing to " << luckyPointer << " , value : " << *luckyPointer << endl;

    luckyPointer++;

    cout << "Pointing to " << luckyPointer << " , value : " << *luckyPointer << endl;



    system("pause>0");
}



//function
float sum(float a, float b) {
    return a + b;
}

void introduceMe(string name, int* age) {
    cout << "My name is " << name << endl;
    (*age)++;
    cout << "I am " << *age << " years old" << endl;
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
