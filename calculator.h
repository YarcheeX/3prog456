#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Calculator
{
private:
	T num1, num2;
public:
	Calculator(T n1, T n2) {

		num1 = n1; num2 = n2;
	}

	void print_results(){
		cout << "Числа: " << num1 << " и " << num2 << "." << endl;
		cout << "Сложение: " << add() << endl;
		cout << "Разница: " << subtract() << endl;
		cout << "Произведение: " << multiply() << endl;
		cout << "Частное: " << divide() << endl;
	}
	void set_numbers(T n1, T n2) {
		num1 = n1;
		num2 = n2;
	}
	T add() { return num1 + num2; }
	T subtract() { return num1 - num2; }
	T multiply() { return num1 * num2; }
	T divide() { return num1 / num2; }
};