#ifndef _COMMON_H_
#define _COMMON_H_
#include <vector>

using std::vector;
// switch
template <typename T>
void myswitch(vector<T> &avector, int i, int j)
{
	T temp = avector[i];
	avector[i] = avector[j];
	avector[j] = temp;
}

// randomize vector
template <typename T>
void randomize(vector<T> &avector)
{
	int n = avector.size();
	for(int i = 0; i < n - 1; ++i)
	{
		srand(GetCycleCount());
		myswitch(avector, i, i + (rand() % (n-i)));
	}
}

#endif