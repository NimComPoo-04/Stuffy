#ifndef _BUBBLE_SORT_HH_
#define _BUBBLE_SORT_HH_

#include "Sorter.hh"

template<typename T>
class Bubble : public Sorter<T>
{
public:
	Bubble() : Sorter<T>() { Sorter<T>::name =  "Bubble"; }
	Bubble(int n) : Sorter<T>(n) { Sorter<T>::name =  "Bubble"; }
	Bubble(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Bubble"; }
	Bubble(const Sorter<T> &s) : Sorter<T>(s) { Sorter<T>::name =  "Bubble"; }

	void execute() override
	{
		for(int i = 0; i < Sorter<T>::size; i++)
		{
			for(int j = 0; j < Sorter<T>::size - 1; j++)
			{
				if(Sorter<T>::data[j] > Sorter<T>::data[j + 1])
					Sorter<T>::swap(Sorter<T>::data[j], Sorter<T>::data[j + 1]);
			}
		}
	}
};


#endif
