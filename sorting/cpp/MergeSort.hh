#ifndef _MERGE_SORT_HH_
#define _MERGE_SORT_HH_

template<typename T>
class Merge : public Sorter<T>
{
private:
	T *xtra;

public:
	Merge() : Sorter<T>() { Sorter<T>::name =  "Merge"; }
	Merge(int n) : Sorter<T>(n) { Sorter<T>::name =  "Merge"; }
	Merge(T *a, int n) : Sorter<T>(a, n) { Sorter<T>::name =  "Merge"; }
	Merge(const Sorter<T> &s) : Sorter<T>(s) { Sorter<T>::name =  "Merge"; }

	void mergeArrays(int start, int mid, int end)
	{
		int i = start, j = mid, c = 0;

		while(i < mid && j < end)
		{
			if(Sorter<T>::data[i] < Sorter<T>::data[j])
				xtra[c++] = Sorter<T>::data[i++];
			else
				xtra[c++] = Sorter<T>::data[j++];
		}

		while(i < mid)
			xtra[c++] = Sorter<T>::data[i++];

		while(j < end)
			xtra[c++] = Sorter<T>::data[j++];
	}

	void mergeSort(int start, int end)
	{
		if(end <= start + 1)
			return;

		int mid = (start + end) / 2;

		mergeSort(start, mid);
		mergeSort(mid, end);

		mergeArrays(start, mid, end);

		for(int i = start; i < end; i++)
			Sorter<T>::data[i] = xtra[i - start];
	}

	void execute() override
	{
		xtra = new T[Sorter<T>::size];
		mergeSort(0, Sorter<T>::size);
		delete[] xtra;
	}
};

#endif
