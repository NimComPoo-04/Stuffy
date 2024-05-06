public class Bubble implements Sorter
{
	public long sort(int a[])
	{		
		long start = System.nanoTime();

		for(int i = 0; i < a.length; i++)
		{
			for(int j = 0; j < a.length - 1; j++)
			{
				if(a[j] > a[j + 1])
				{
					int k = a[j];
					a[j] = a[j+1];
					a[j+1] = k;
				}
			}
		}

		long end = System.nanoTime();

		return end - start;
	}
}
