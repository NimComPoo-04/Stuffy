#include <iostream>
using namespace std;
/*
 * Accept 2 numbers and display the larger of the 2
 */

class Larger {
private:
	int a, b;

public:
	Larger(int a, int b);
	~Larger() = default;

	void acceptValue();
	int findLarger();
	void display();
};

inline Larger::Larger(int a, int b) {
	Larger::a = a;
	Larger::b = b;
}

inline void Larger::acceptValue() {
	cout << "Enter 2 number: ";
	cin >> Larger::a >> Larger::b;
}

inline int Larger::findLarger() {
	return a > b ? a : b;
}

void Larger::display() {
	cout << "First Number: " << a << endl
	     << "Second Number: " << b << endl
	     << "Larger: " << findLarger() << endl;
}

int main() {
	Larger l = Larger(0, 0);
	l.acceptValue();
	l.display();

	int larger = l.findLarger();
	cout << "Larger Square: " << larger * larger << endl;
}
