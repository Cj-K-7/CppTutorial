#pragma once

class Calculator {
public: 
	~Calculator() {}
	Calculator();
	void Add(int x, int y);
	void Subtract(int x, int y);
	void ShowResult();
private:
	int a;
	int b;
	int result;
};