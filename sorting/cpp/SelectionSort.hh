#ifndef _SELECTION_SORT_HH_
#define _SELECTION_SORT_HH_

#include "Sorter.hh"

template<typename T>
class Selection : public Sorter<T>
{
public:
	Selection() : Sorter<T>() { Sorter<T>::name =  "Selection"; }
	Selection(int n) : Sorter<T>(n) { Sorter<T>::name =  "Selection"; }
	Selection(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Selection"; }
	Selection(const Sorter<T>& s) : Sorter<T>(s) { Sorter<T>::name =  "Selection"; }

	void execute() override
	{
		for(int i = 0; i < Sorter<T>::size; i++)
		{
			int k = i;
			for(int j = i+1; j < Sorter<T>::size; j++)
			{
				if(Sorter<T>::data[k] > Sorter<T>::data[j])
					k = j;
			}

			Sorter<T>::swap(Sorter<T>::data[k], Sorter<T>::data[i]);
		}
	}
};


#endif
