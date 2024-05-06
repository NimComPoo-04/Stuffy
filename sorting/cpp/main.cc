#include <iostream>
#include <iomanip>
using namespace std;

#include "Sorter.hh"
#include "BubbleSort.hh"
#include "SelectionSort.hh"
#include "InsertionSort.hh"
#include "ShellSort.hh"
#include "MergeSort.hh"
#include "QuickSort.hh"
#include "HeapSort.hh"

int main(void)
{
	const int N = 40;

	static int a[N];
	for(int i = 0; i < N; i++)
		a[i] = i + 1;

	Sorter<int> def(a, N);

	def.shuffle();
	def.print();
	cout << "\n\n";

	Sorter<int> *sorters[] = {
		new Bubble<int>(def),
		new Selection<int>(def),
		new Insertion<int>(def),
		new Shell<int>(def),
		new Merge<int>(def),
		new Quick<int>(def),
		new Heap<int>(def)
	};

	cout << std::setprecision(9) << std::fixed;

	long time = def.sort();
	def.print();
	cout << "\tTime: " << time * 1E-9 << "\n\n";

	for(unsigned i = 0; i < sizeof sorters / sizeof sorters[0]; i++)
	{
		time = sorters[i]->sort();
		sorters[i]->print();
		cout << "\tTime: " << time * 1E-9 << endl;
	}

	for(unsigned i = 0; i < sizeof sorters / sizeof sorters[0]; i++)
		delete sorters[i];

	return 0;
}
