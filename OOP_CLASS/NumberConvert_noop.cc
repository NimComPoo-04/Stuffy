#include <iostream>
#include <cstring>
using namespace std;

static const char SYMBOL_CONVERTION_TABLE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static inline int platonize(int value, int in_base, int place_holder = 1) {
	return value ? (value % 10) * place_holder + platonize(value / 10, in_base, place_holder * in_base) : 0;
}

static int deplatonize(int value, int out_base) {
	return value ? deplatonize(value / out_base, out_base) * 10 + (value % out_base) : 0;
}

#define toBase(value, in_base, out_base) deplatonize(platonize(value, in_base), out_base)

int main(void) {
	int input_bin, input_oct;

	cout << "Enter a number in binary form: ";
	cin >> input_bin;
	cout << "Enter a number in octal form: ";
	cin >> input_oct;

	cout << "Decimal Version of first number : " << toBase(input_bin, 2, 10) << endl
		<< "Decimal Version of the second number :" << toBase(input_oct, 8, 10) << endl;
}
