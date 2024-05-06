import java.util.Arrays;

public class Heap implements Sorter
{
	void shiftDown(int a[], int head, int count)
	{
		int child[] = {head * 2 + 1, head * 2 + 2};

		if(child[1] < count && a[child[0]] < a[child[1]])
		{
			if(a[child[1]] > a[head])
			{
				int t = a[child[1]];
				a[child[1]] = a[head];
				a[head] = t;

				shiftDown(a, child[1], count);
			}
		}
		else if(child[0] < count)
		{
			if(a[child[0]] > a[head])
			{
				int t = a[child[0]];
				a[child[0]] = a[head];
				a[head] = t;

				shiftDown(a, child[0], count);
			}
		}
	}

	void hepify(int a[])
	{
		for(int i = a.length - 1; i >= 0; i--)
		{
			shiftDown(a, i, a.length);
		}
	}

	public long sort(int a[])
	{
		long start = System.nanoTime();

		hepify(a);

		for(int i = a.length - 1; i >= 0; i--)
		{
			int t = a[0];
			a[0] = a[i];
			a[i] = t;

			shiftDown(a, 0, i);
		}

		return System.nanoTime() - start;
	}
}
