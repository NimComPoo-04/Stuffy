import java.util.Arrays;

public class Merge implements Sorter
{
	int[] mergeArray(int a[], int b[])
	{
		int n[] = new int[a.length + b.length];
		
		int i = 0, j = 0, c = 0;

		while(i < a.length && j < b.length)
		{
			if(a[i] < b[j])
				n[c++] = a[i++];
			else
				n[c++] = b[j++];
		}

		while(i < a.length)
		{
			n[c++] = a[i++];
		}

		while(j < b.length)
		{
			n[c++] = b[j++];
		}

		return n;
	}

	int[] mergeSort(int a[])
	{
		if(a.length == 1)
			return a;

		int mid = a.length / 2;

		int f[] = mergeSort(Arrays.copyOfRange(a, 0, mid));
		int s[] = mergeSort(Arrays.copyOfRange(a, mid, a.length));

		return mergeArray(f, s);
	}

	public long sort(int a[])
	{
		long start = System.nanoTime();

		int n[] = mergeSort(a);

		for(int i = 0; i < a.length; i++)
			a[i] = n[i];

		return System.nanoTime() - start;
	}
}
