#include <iostream>
#include "mysort.h"

int main()
{
	using namespace std;
	int unsorted[10] = { 1, 8, 5, 10, 3, 2, 9, 6, 4, 7};
	merge_sort(unsorted, 0, 9);
	for(int i = 0; i < 10; ++i)
	{
		cout << unsorted[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
