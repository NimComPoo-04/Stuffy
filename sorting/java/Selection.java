public class Selection implements Sorter
{
	public long sort(int a[])
	{
		long start = System.nanoTime();

		for(int i = 0; i < a.length; i++)
		{
			int k = i;
			for(int j = i+1; j < a.length; j++)
			{
				if(a[k] > a[j])
					k = j;
			}

			int t = a[k];
			a[k] = a[i];
			a[i] = t;
		}

		return System.nanoTime() - start;
	}
}
