import java.util.Arrays;

public class Insertion implements Sorter
{
	public long sort(int a[])
	{
		long start = System.nanoTime();

		for(int i = 0; i < a.length; i++)
		{
			for(int j = i; j > 0; j--)
			{
				if(a[j] > a[j-1])
					break;

				int t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
			}
		}

		return System.nanoTime() - start;
	}
}
