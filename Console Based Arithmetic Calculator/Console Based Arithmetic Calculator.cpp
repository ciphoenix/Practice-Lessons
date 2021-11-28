#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double sum(double a, double b);
double difference(double a, double b);
double product(double a, double b);
double quotient(double a, double b);
double exponent(double a, double b);

int main()
{
	cout << "***************************************" << endl;
	cout << "********  CALCULATOR PROGRAM   ********" << endl;
	cout << "***************************************" << endl;
	cout << "\n\n\n\n";

	double num1, num2;
	char op;
	double answer;

	cout << "Enter arithmetic expression separated by spaces: ";
	cin >> num1 >> op >> num2;

	switch (op)
	{
	case '+':
		answer = sum(num1, num2);
		break;
	case '-':
		answer = difference(num1, num2);
		break;
	case '*':
		answer = product(num1, num2);
		break;
	case '/':
		answer = quotient(num1, num2);
		break;
	case '^':
		answer = exponent(num1, num2);
		break;
	default:
		cout << " INVALID OPERATOR";
		break;
	}

	cout << num1 << " " << op << " " << num2 << " = " << answer;

	return 0;
}


double sum(double a, double b)
{
	return a + b;
}

double difference(double a, double b)
{
	return a - b;
}

double product(double a, double b)
{
	return a * b;
}

double quotient(double a, double b)
{
	return a / b;
}

double exponent(double a, double b)
{
	double temp = a;
	for (int i = 1; i < b; i++)
	{
		a *= temp;
	}
	return a;
}
