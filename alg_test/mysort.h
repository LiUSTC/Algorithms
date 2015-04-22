#ifndef _MYSORT_H_
#define _MYSORT_H_
//模板的声明与定义都放在头文件里，因分离模型需在声明处加关键字export，但很少编译器支持此特性。

#include <vector>
#include "alg.h"
#include "myheap.h"
using std::vector;

inline unsigned __int64 GetCycleCount()
{
__asm _emit 0x0F
__asm _emit 0x31
}

// bubble sort
template <typename T>
void bubble_sort(vector<T> &avector)
{
	int n = avector.size();
	for(int i = n - 1; i > 0; --i)
	{
		for(int j = n - 1; j > 0; --j)
		{
			if (avector[j] < avector[j - 1])
				myswitch(avector, j, j - 1);
		}
	}
}

// insertion sort
template <typename T>
void insertion_sort(vector<T> &avector)
{
	int n = int n = avector.size();
	for(int i = 1; i < n; ++i)
	{
		for(int j = i; j > 0; --j)
		{
			if (avector[j] < avector[j - 1])
				myswitch(avector, j, j - 1);
		}
	}
}

// merge sort
template <typename T>
void merge(vector<T> &avector, int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;
	if ((n1 > 0) && (n2 > 0))
	{
		vector<T> L1;
		vector<T> L2;
		for(int i = 0; i < n1; ++i)
		{
			L1.push_back(avector[start + i]);
		}
		for(int j = 0; j < n2; ++j)
		{
			L2.push_back(avector[middle + j + 1]);
		}
		int i1 = 0;
		int i2 = 0;
		for(int k = start;k <= end; ++k)
		{
			if((i1 < n1)&&(i2 < n2))
			{
				if(L1[i1] < L2[i2])
				{
					avector[k] = L1[i1];
					++i1;
				}
				else
				{
					avector[k] = L2[i2];
					++i2;
				}
			}
			else if(i1 == n1)
			{
				avector[k] = L2[i2];
				++i2;
			}
			else if(i2 == n2)
			{
				avector[k] = L1[i1];
				++i1;
			}
		}
	}
}

template <typename T>
void merge_sort(vector<T> &avector, int start, int end)
{
	if (start < end)
	{
		int temp = floor((start + end) / 2);
		merge_sort(avector, start, temp);
		merge_sort(avector, temp + 1, end);
		merge(avector,start,temp,end);
	}
}

//heap sort
template <typename T>
void heap_sort(vector<T> &avector)
{
	make_heap(avector.begin(),avector.end());
	sort_heap(avector.begin(),avector.end());
}

//quick sort
template <typename T>
int partition(vector<T> &avector, int start, int end)
{
	int x = avector[end];
	int i = start - 1;
	for(int j = start; j < end ; ++j)
	{
		if (avector[j] <= x)
		{
			++i;
			myswitch(avector, i,j);
		}
	}
	myswitch(avector, i + 1, end);
	return i + 1;
}

template <typename T>
void quick_sort(vector<T> &avector, int start, int end)
{
	if (start < end)
	{
		int middle = partition(avector, start, end);
		quick_sort(avector, start, middle - 1);
		quick_sort(avector, middle + 1, end);
	}
}
#endif