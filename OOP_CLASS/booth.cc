#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

class Multiplier
{
protected:
	int multiplicand;
	int multiplier;
	mutable int product;

public:
	Multiplier(int x, int y);

	virtual void multiply();

	int get_multiplicand() const;
	int get_multiplier() const;
	int get_product() const;

	friend ostream& operator<<(ostream&, const Multiplier&);
};

class Booth : public Multiplier
{
public:
	Booth(int x, int y);
	virtual void multiply() override;
};

Multiplier::Multiplier(int x, int y)
{
	Multiplier::multiplicand = x;
	Multiplier::multiplier = y;
	Multiplier::product = 0;
}

class Karatsuba : public Multiplier
{
private:
	int mult(int, int) const;

public:
	Karatsuba(int x, int y);
	virtual void multiply() override;
};

int Multiplier::get_multiplicand() const { return multiplicand; }
int Multiplier::get_multiplier() const { return multiplier; }
int Multiplier::get_product() const { return product; }

void Multiplier::multiply()
{
	product = multiplicand * multiplier;
}

ostream& operator<<(ostream& o, const Multiplier& m)
{
	return o << m.multiplicand << " ‥ " << m.multiplier << " = " << m.product << endl;
}

Booth::Booth(int x, int y) :Multiplier(x, y) { }

void Booth::multiply()
{
	int x = multiplicand;
	int y = multiplier << 1;
	int p = 0;

	// While there is something in the multiplier
	while(y != 0 && y != -1) {
		switch(y & 3) {
			case 1: p += x; break;
			case 2: p -= x; break;
		}

		x <<= 1;
		y >>= 1;
	}
	
	product = p;
}

Karatsuba::Karatsuba(int x, int y) :Multiplier(x, y) { }

// FIXME: use base 2 instead
int Karatsuba::mult(int x, int y) const {
	if(x < 10 || y < 10) return x * y;

	const int t1 = pow(10, (int)(log10(x) + 1) / 2);
	const int x0 = x % t1;
	const int x1 = x / t1;

	const int t2 = pow(10, (int)(log10(y) + 1) / 2);
	const int y0 = y % t2;
	const int y1 = y / t2;

	const int z0 = mult(x0, y0);
	const int z2 = mult(x1, y1);
	const int z1 = mult(x1 + x0, y1 + y0) - z2 - z0;

	const int t = (t2 > t1 ? t2 : t1);
	return z2 * t * t + z1 * t + z0;
}

void Karatsuba::multiply()
{
	product = mult(multiplicand, multiplier);
}

int main(void)
{
	int x, y;
	cout << "Enter 2 numbers: ";
	cin >> x >> y;

	Multiplier&& a = Multiplier(x, y);
	a.multiply();
	cout << a;

	Multiplier&& b = Karatsuba(x, y);
	b.multiply();
	cout << b;

	Multiplier&& c = Booth(x, y);
	c.multiply();
	cout << c;

	return 0;
}
