#include <iostream>
#include "mysort.h"

int main()
{
	using namespace std;
	int ivec[10] = { 1, 8, 5, 10, 3, 2, 9, 6, 4, 7};
	std::vector<int> unsorted(ivec, ivec + 10);
	randomize(unsorted);
	quick_sort(unsorted,0,9);
	for(int i = 0; i < 10; ++i)
	{
		cout << unsorted[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
