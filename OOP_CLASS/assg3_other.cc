#include <iostream>
#include <climits>
using namespace std;

int units = 0;
double charge_50 = 0;  // first 50 3.5
double charge_150 = 0; // next 100 5.0
double charge_250 = 0; // next 100 8.0
double charge_rest = 0; // above 250 10.0
double surge_cost = 0; // 20% extra

void calculate_billing();
double total();
void display();

#define clamp(min, max, value) ((value) > (min) ? ((value) < (max) ? (value) : (max)) : (min))

void calculate_billing() {

	charge_50   = clamp(0, 50,  units -   0) * 3.5;
	charge_150  = clamp(0, 100, units -  50) * 5.0;
	charge_250  = clamp(0, 100, units - 150) * 8.0;
	charge_rest = clamp(0, INT_MAX, units - 250) * 10.0;

	surge_cost = (charge_50 + charge_150 + charge_250 + charge_rest) * 20.0 / 100.0;
}

double total() { return charge_50 + charge_150 + charge_250 + charge_rest + surge_cost; }

void display() {
	cout << "Charge For First 50 Units: " << charge_50 << endl
	     << "Charge For Next 100 Units: " << charge_150 << endl
	     << "Charge For Next 100 Units: " << charge_250 << endl
	     << "Charge For Above 250 Units: " << charge_rest << endl
	     << "Surge Charge: " << surge_cost << endl
	     << "Total: " << total() << endl;
}

int main() {
	cin >> units;

	if(units <= 0) {
		cerr << "The Input is invalid: " << endl;
		return 1;
	}

	calculate_billing();
	display();
}
