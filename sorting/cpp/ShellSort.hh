#ifndef _SHELL_SORT_HH_
#define _SHELL_SORT_HH_

#include "Sorter.hh"

template<typename T>
class Shell: public Sorter<T>
{
public:
	Shell() : Sorter<T>() { Sorter<T>::name =  "Shell"; }
	Shell(int n) : Sorter<T>(n) { Sorter<T>::name =  "Shell"; }
	Shell(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Shell"; }
	Shell(const Sorter<T>& s) : Sorter<T>(s) { Sorter<T>::name =  "Shell"; }

	void execute() override
	{
		int gap = Sorter<T>::size / 2;

		while(gap != 0)
		{
			for(int i = gap; i < Sorter<T>::size; i++)
			{
				for(int j = i; j >= gap; j -= gap)
				{
					if(Sorter<T>::data[j] > Sorter<T>::data[j - gap])
						break;

					Sorter<T>::swap(Sorter<T>::data[j], Sorter<T>::data[j - gap]);
				}
			}

			gap /= 2;
		}
	}
};


#endif
