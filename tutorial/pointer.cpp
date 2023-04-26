#include <iostream>

using namespace std;

void printNumber(int* numberPtr) {
	cout << *numberPtr << endl;
}

void printLetter(char* charPtr) {
	cout << *charPtr << endl;
}

int getMin(int numbers[], int size) {
	int min = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
	return min;
}

int getMax(int numbers[], int size) {
	int max = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	return max;
}

void getMinandMax(int numbers[], int size, int* min, int* max) {
	for (int i = 1; i < size; i++) {
		if (numbers[i] < *min)
			*min = numbers[i];
		if (numbers[i] > *max)
			*max = numbers[i];

	}
}

int main()
{

	int numbers[5] = { 5,3,2,1,0 };

	int min = numbers[0];
	int max = numbers[0];

	getMinandMax(numbers, 5, &min, &max);
	cout << "minmax is " << min << ", " << max << endl;

	//cout << "Minimum is " << getMin(numbers, 5) << endl;
	//cout << "Maximum is " << getMax(numbers, 5) << endl;

	system("pause>0");
	return 0;
}

