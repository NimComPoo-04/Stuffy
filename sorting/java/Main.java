import java.util.Arrays;

public class Main
{
	static int dataset[];

	public static void main(String args[])
	{
		dataset = new int[(int)20];

		for(int i = 0; i < dataset.length; i++)
			dataset[i] = (int)(Math.random() * 1000);

		System.out.println("== Sorting Algorithms ==\n");

		/*
		System.out.println("Data Set used: ");
		System.out.println(Arrays.toString(dataset)+"\n");
		*/

		Sorter sorters[] = new Sorter[] {
			new Bubble(),
			new Selection(),
			new Insertion(),
			new Shell(),
			new Merge(),
			new Quick(),
			new Heap()
		};

		for(final Sorter s : sorters)
			executeSort(s);

		int duplicate[] = Arrays.copyOf(dataset, dataset.length);
		long start = System.nanoTime();
		Arrays.sort(duplicate);
		long dt = System.nanoTime() - start;

		System.out.printf("\nDefault Sort for Comparisn : %f\n\n", dt * 1E-9);
	}

	static  void executeSort(final Sorter s)
	{
		int duplicate[] = Arrays.copyOf(dataset, dataset.length);
		System.out.printf(s.toString().split("@")[0] + " Sort: Time %f\n", s.sort(duplicate) * 1E-9);

		if(duplicate.length <= 30)
			System.out.println(Arrays.toString(duplicate) + "\n");
	}
}
