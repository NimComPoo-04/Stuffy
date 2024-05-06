#ifndef _INSERTION_SORT_HH_
#define _INSERTION_SORT_HH_

#include "Sorter.hh"

template<typename T>
class Insertion : public Sorter<T>
{
public:
	Insertion() : Sorter<T>() { Sorter<T>::name =  "Insertion"; }
	Insertion(int n) : Sorter<T>(n) { Sorter<T>::name =  "Insertion"; }
	Insertion(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Insertion"; }
	Insertion(const Sorter<T> &s) : Sorter<T>(s) { Sorter<T>::name =  "Insertion"; }

	void execute() override
	{
		for(int i = 0; i < Sorter<T>::size - 1; i++)
		{
			for(int j = i; j >= 0; j--)
			{
				if(Sorter<T>::data[j] < Sorter<T>::data[j+1])
					break;
				Sorter<T>::swap(Sorter<T>::data[j], Sorter<T>::data[j+1]);
			}
		}
	}
};


#endif
