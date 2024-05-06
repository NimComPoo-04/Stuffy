#ifndef _HEAP_SORT_HH_
#define _HEAP_SORT_HH_

#include "Sorter.hh"

template<typename T>
class Heap : public Sorter<T>
{
public:
	Heap() : Sorter<T>() { Sorter<T>::name =  "Heap"; }
	Heap(int n) : Sorter<T>(n) { Sorter<T>::name =  "Heap"; }
	Heap(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Heap"; }
	Heap(const Sorter<T> &s) : Sorter<T>(s) { Sorter<T>::name =  "Heap"; }	

	void shiftDown(int head, int count)
	{
		if(head >= count || head < 0)
			return;

		int child1 = head * 2 + 1;
		int child2 = head * 2 + 2;

		if(child1 < count)
		{
			if(child2 < count && Sorter<T>::data[child2] > Sorter<T>::data[child1])
			{
				if(Sorter<T>::data[child2] > Sorter<T>::data[head])
				{
					Sorter<T>::swap(Sorter<T>::data[child2], Sorter<T>::data[head]);
					shiftDown(child2, count);
				}
			}
			else
			{
				if(Sorter<T>::data[child1] > Sorter<T>::data[head])
				{
					Sorter<T>::swap(Sorter<T>::data[child1], Sorter<T>::data[head]);
					shiftDown(child1, count);
				}
			}
		}
	}

	void heapify()
	{
		for(int i = Sorter<T>::size - 1; i >= 0; i--)
			shiftDown(i, Sorter<T>::size);
	}

	void execute() override
	{
		heapify();

		for(int i = Sorter<T>::size - 1; i > 0; i--)
		{
			Sorter<T>::swap(Sorter<T>::data[0], Sorter<T>::data[i]);
			shiftDown(0, i);
		}
	}
};


#endif
