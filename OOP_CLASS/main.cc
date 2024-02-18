#include <iostream>
using namespace std;

class Something {
private:
	int a, b, c;
public:
	Something(int a, int b);
	~Something();
};

Something::Something(int a, int b) :a(a), b(b) {
	cout << "Hi Bois!" << endl;
}

Something::~Something() {
	cout << "Bye Bois!" << endl;
}

int main(void) {
	cout << "Hello, World!\n";
}
