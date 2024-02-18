#include <iostream>
#include <climits>
using namespace std;

class Bill {
private:
	int units;
	double charge_50;  // first 50 3.5
	double charge_150; // next 100 5.0
	double charge_250; // next 100 8.0
	double charge_rest; // above 250 10.0
	double surge_cost; // 20% extra

	int clamp(int max, int min, int value);
public:
	Bill(int units);
	~Bill() = default;
	void calculate_billing();
	double total();
	void display();
};

Bill::Bill(int units) {
	Bill::units = units;
	Bill::charge_50 = 0;
	Bill::charge_150 = 0;
	Bill::charge_250 = 0;
	Bill::charge_rest = 0;
	Bill::surge_cost = 0;
}

int Bill::clamp(int max, int min, int value) {
	return (value > min ? (value < max ? value : max) : min);
}

inline void Bill::calculate_billing() {

	charge_50   = clamp(0, 50,  units -   0) * 3.5;
	charge_150  = clamp(0, 100, units -  50) * 5.0;
	charge_250  = clamp(0, 100, units - 150) * 8.0;
	charge_rest = clamp(0, INT_MAX, units - 250) * 10.0;

	surge_cost = (charge_50 + charge_150 + charge_250 + charge_rest) * 20.0 / 100.0;
}

inline double Bill::total() {
	return charge_50 + charge_150 + charge_250 + charge_rest + surge_cost;
}

inline void Bill::display() {
	cout << "Charge For First 50 Units: " << charge_50 << endl;
	cout << "Charge For Next 100 Units: " << charge_150 << endl;
	cout << "Charge For Next 100 Units: " << charge_250 << endl;
	cout << "Charge For Above 250 Units: " << charge_rest << endl;
	cout << "Surge Charge: " << surge_cost << endl;
	cout << "Total: " << total() << endl;
}

int main() {
	int units;
	cin >> units;
	if(units <= 0) {
		cerr << "The Input is invalid: " << endl;
		return -1;
	}

	Bill b(units);
	b.calculate_billing();
	b.display();
}
