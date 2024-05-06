#ifndef _SORTER_HH_
#define _SORTER_HH_

#include <iostream>
#include <algorithm> // for default sorting
#include <chrono>    // for time dawg
#include <random>
#include <iomanip>

template<typename T>
class Sorter
{
protected:
	T *data;
	int size;

	std::string name;

public:
	Sorter()
	{
		data = nullptr;
		size = 0;
		name = "Default";
	}

	Sorter(int n)
	{
		size = n;
		data = new T[n];
		name = "Default";
	}

	Sorter(T *a, int size)
	{
		data = new T[size];
		this->size = size;
		name = "Default";

		std::copy(a, a + size, data);
	}

	Sorter(const Sorter<T> &a)
	{
		data = new T[a.size];
		this->size = a.size;
		name = "Default";

		std::copy(a.data, a.data + a.size, data);
	}

	void shuffle()
	{
		std::random_device rnd;
		std::mt19937 gen(rnd());
		std::uniform_int_distribution<int> distr(0, size);

		for(int i = size - 1; i > 0; i--)
		{
			int j = distr(gen) % i;

			std::swap(data[i], data[j]);
		}
	}

	void print()
	{
		using namespace std;

		cout << setw(10) << name << " : ";

		if(size <= 40)
		{
			cout << "[ ";
			for(int i = 0; i < size; i++)
			{
				cout << data[i];
				if(i != size - 1)
					cout << ", ";
			}
			cout << " ] ";
		}
	}

	void swap(T &a, T &b)
	{
		T k = a;
		a = b;
		b = k;
	}

	virtual void execute()
	{
		std::sort(data, data + size);
	}

	// We want a default sorting done by the algorithm lib
	unsigned long sort()
	{
		std::chrono::time_point<std::chrono::system_clock> start =
			std::chrono::system_clock::now();

		execute();

		std::chrono::time_point<std::chrono::system_clock> end =
			std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}

	virtual ~Sorter()
	{
		delete[] data;
	}
};

#endif
