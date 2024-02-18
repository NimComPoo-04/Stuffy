#include <iostream>
using namespace std;
/*
 * accept 2 number:
 * if equal 
	 * display sum of the cube of 2 number
 * otherwise
	 * display the squre of the sum of the 2 numbers
 * */

class NumOp {
private:
	int a, b;
public:
	NumOp(int a, int b);
	~NumOp() = default;

	int opResult();
};

NumOp::NumOp(int a, int b) {
	NumOp::a = a;
	NumOp::b = b;
}

int NumOp::opResult() {
	return (a == b) ?
		(a * a * a + b * b * b)
		: (a * a + b * b);
}

int main(void)
{
	int a, b;
	cout << "Enter 2 Numbers: ";
	cin >> a >> b;

	NumOp np(a, b);
	cout << np.opResult() << endl;

	return 0;
}
