import java.util.Arrays;

public class Shell implements Sorter
{
	public long sort(int a[])
	{
		long start = System.nanoTime();

		int gap = a.length / 2;

		while(gap > 0)
		{
			for(int i = gap; i < a.length; i++)
			{
				for(int j = i; j >= gap; j -= gap)
				{
					if(a[j] > a[j - gap])
						break;

					int t = a[j];
					a[j] = a[j - gap];
					a[j - gap] = t;
				}
			}

			gap /= 2;
		}

		return System.nanoTime() - start;
	}
}
