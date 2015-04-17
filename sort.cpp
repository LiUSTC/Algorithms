template <typename T>
void myswitch(T[] anarray, int i, int j)
{
	T temp = anarray[i];
	anarray[i] = anarray[j];
	anarray[j] = temp;
}

// bubble sort
template <typename T>
void bubble_sort(T[] unsorted, int n)
{
	for(int i = n - 1; i > 0; --i)
	{
		for(int j = i; j > 0; --j)
		{
			if (unsorted[j] < unsorted[j-1])
				myswitch(unsorted[j],unsorted[j-1]);
		}
	}
}