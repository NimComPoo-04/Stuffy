#include <iostream>
#include <ctype.h>
using namespace std;

static const char SYMBOL_CONVERTION_TABLE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Number
{
private:
	int value;

public:
	Number(int value);
	Number(int value, int base);
	Number(string value, int base);

	int toBaseAs(int base);
	string toBase(int base);
};

Number::Number(int a)
	:value(a)
{ }


Number::Number(int value, int base)
{
	Number::value = 0;

	int place_value = 1;
	while(value)
	{
		Number::value += (value % 10) * place_value;
		place_value *= base;
		value /= 10;
	}
}

int Number::toBaseAs(int base)
{
	if(base <= 1 || base > 10)
		return -1;

	int number = Number::value;
	int value = 0;
	int place_value = 1;

	while(number)
	{
		value = (number % base) * place_value + value;
		number /= base;
		place_value *= 10;
	}

	return value;
}

int main(void)
{
	int input_bin;
	int input_oct;

	cout << "Enter a number in binary form: ";
	cin >> input_bin;
	cout << "Enter a number in octal form: ";
	cin >> input_oct;

	Number n1(input_bin, 2);
	Number n2(input_oct, 8);

	cout << "Decimal Version of first number : " << n1.toBaseAs(10) << endl
		<< "Decimal Version of the second number :" << n2.toBaseAs(10);
}

