#ifndef _QUICK_SORT_HH_
#define _QUICK_SORT_HH_

template<typename T>
class Quick : public Sorter<T>
{
public:
	Quick() : Sorter<T>() { Sorter<T>::name =  "Quick"; }
	Quick(int n) : Sorter<T>(n) { Sorter<T>::name =  "Quick"; }
	Quick(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Quick"; }
	Quick(const Sorter<T> &s) : Sorter<T>(s) { Sorter<T>::name =  "Quick"; }

	void quickSort(int start, int end)
	{
		if(end - start <= 1)
			return;		// nothing to do

		Sorter<T>::swap(Sorter<T>::data[(start + end - 1) / 2], Sorter<T>::data[end - 1]);

		int k = start;
		int l = end - 2;

		int pivot = Sorter<T>::data[end-1];

		while(k <= l && k < end && l >= start)
		{
			if(Sorter<T>::data[k] < pivot)
				k++;
			else if(Sorter<T>::data[l] > pivot)
				l--;
			else
			{
				Sorter<T>::swap(Sorter<T>::data[k], Sorter<T>::data[l]);
				k++;
				l--;
			}
		}

		// swap with the pivot
		Sorter<T>::swap(Sorter<T>::data[k], Sorter<T>::data[end-1]);

		quickSort(start, k);
		quickSort(k + 1, end);
	}

	void execute() override
	{
		quickSort(0, Sorter<T>::size);
	}
};

#endif
