import java.util.Arrays;

public class Quick implements Sorter
{
	void qsort(int a[], int start, int end)
	{
		if(end <= start)
			return;

		// choose mid point as swap index and swap it with the end
		int pivot = a[(end + start) / 2];
		a[(end + start) / 2] = a[end];
		a[end] = pivot;

		// do the sorting
		int k = start;
		int l = end - 1;

		while(k <= l)
		{
			if(a[k] < pivot)
			{
				k++;
			}
			else if(a[l] > pivot)
			{
				l--;
			}
			else
			{
				int t = a[k];
				a[k] = a[l];
				a[l] = t;

				k++;
				l--;
			}
		}

		int t = a[end];
		a[end] = a[k];
		a[k] = t;

		// System.out.println(Arrays.toString(Arrays.copyOfRange(a, start, end + 1)) + " | Pivot: " + pivot);

		qsort(a, start, k - 1);
		qsort(a, k + 1, end);
	}

	public long sort(int a[])
	{
		long start = System.nanoTime();

		qsort(a, 0, a.length - 1);

		return System.nanoTime() - start;
	}
}
