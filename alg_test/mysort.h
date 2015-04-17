#ifndef _MYSORT_H_
#define _MYSORT_H_
#include <limits>
template <typename T>     //模板的定义放在头文件里，分离模型需在声明处加关键字export，但很少编译器支持此特性。
void myswitch(T anarray[], int i, int j)
{
	T temp = anarray[i];
	anarray[i] = anarray[j];
	anarray[j] = temp;
}

// bubble sort
template <typename T>
void bubble_sort(T unsorted[], int n)
{
	for(int i = n - 1; i > 0; --i)
	{
		for(int j = n - 1; j > 0; --j)
		{
			if (unsorted[j] < unsorted[j - 1])
				myswitch(unsorted, j, j - 1);
		}
	}
}

// insertion sort
template <typename T>
void insertion_sort(T unsorted[], int n)
{
	for(int i = 1; i < n; ++i)
	{
		for(int j = i; j > 0; --j)
		{
			if (unsorted[j] < unsorted[j - 1])
				myswitch(unsorted, j, j - 1);
		}
	}
}

// merge sort
template <typename T>
void merge(T unsorted[], int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;
	if ((n1 > 0) && (n2 > 0))
	{
		T* p1 = new T[n1];
		T* p2 = new T[n2];
		for(int i = 0; i < n1; ++i)
		{
			p1[i] = unsorted[start + i];
		}
		for(int j = 0; j < n2; ++j)
		{
			p2[j] = unsorted[middle + j + 1];
		}
		int i1 = 0;
		int i2 = 0;
		for(int k = start;k <= end; ++k)
		{
			if((i1 < n1)&&(i2 < n2))
			{
				if(p1[i1] <= p2[i2])
				{
					unsorted[k] = p1[i1];
					++i1;
				}
				else
				{
					unsorted[k] = p2[i2];
					++i2;
				}
			}
			else if(i1 == n1)
			{
				unsorted[k] = p2[i2];
				++i2;
			}
			else if(i2 == n2)
			{
				unsorted[k] = p1[i1];
				++i1;
			}
		}
		delete[] p1;
		delete[] p2;
	}
}

template <typename T>
void merge_sort(T unsorted[], int start, int end)
{
	if (start < end)
	{
		int temp = floor((start + end) / 2);
		merge_sort(unsorted, start, temp);
		merge_sort(unsorted, temp + 1, end);
		merge(unsorted,start,temp,end);
	}
}



#endif