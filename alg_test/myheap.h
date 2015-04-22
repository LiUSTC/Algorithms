#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_

#include <vector>
#include <iterator>
#include "alg.h"

//push_heap
//该函数接受两个迭代器，用来表现一个heap底部容器(vector)的头尾
//并且新元素已经插入到底部容器的最尾端，即最后一个元素之前的元素的已经heap化了
template <typename RandomAccessIterator, typename Distance, typename T>
inline void __push_heap(RandomAccessIterator first, Distance holeIndex, Distance topIndex, T value)
{
	Distance parent = (holeIndex - 1) / 2;
	while (holeIndex > topIndex && *(first + parent) < value)
	{
		*(first + holeIndex) = *(first + parent);
		holeIndex = parent;
		parent = (holeIndex - 1) / 2;
	}
	*(first + holeIndex) = value;
}

template <typename RandomAccessIterator, typename Distance, typename T>
inline void __push_heap_aux(RandomAccessIterator first, RandomAccessIterator last, Distance*, T*)
{
	__push_heap(first, Distance(last - first - 1), Distance(0), T(*(last - 1)));
}


template <typename RandomAccessIterator>
inline void push_heap(RandomAccessIterator first, RandomAccessIterator last)
{
	RandomAccessIterator::value_type * x1 = new RandomAccessIterator::value_type;
	RandomAccessIterator::distance_type * x2 = new new RandomAccessIterator::distance_type;
	__push_heap_aux(first, last, x2, x1);
	delete x1;
	delete x2;
}




//pop_heap
//同样接受两个迭代器，用来用来表现一个heap底部容器(vector)的头尾
template <typename RandomAccessIterator, typename Distance, typename T>
inline void __adjust_heap(RandomAccessIterator first, Distance holeIndex, Distance len, T value)
{
	Distance topIndex = holeIndex;
	Distance secondChild = 2 * holeIndex + 2;
	while (secondChild < len)
	{
		if(*(first + secondChild) < *(first + secondChild - 1))
			--secondChild;
		*(first + holeIndex) = *(first + secondChild);
		holeIndex = secondChild;
		secondChild = 2 * secondChild + 2;
	}
	if(secondChild == len)
	{
		*(first + holeIndex) = *(first + secondChild - 1);
		holeIndex = secondChild - 1;
	}
	__push_heap(first, holeIndex, topIndex, value);
}

template <typename RandomAccessIterator, typename Distance, typename T>
inline void __pop_heap(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator result, T value, Distance *)
{
	*result = *first;
	__adjust_heap(first, Distance(0), Distance(last - first), value);
}

template <typename RandomAccessIterator, typename T>
inline void __pop_heap_aux(RandomAccessIterator first, RandomAccessIterator last, T*)
{
	RandomAccessIterator::distance_type * x2 = new RandomAccessIterator::distance_type;
	__pop_heap(first, last - 1, last - 1, T(*(last - 1)), x2);
	delete x2;
}

template <typename RandomAccessIterator>
inline void pop_heap(RandomAccessIterator first, RandomAccessIterator last)
{
	RandomAccessIterator::value_type * x1 = new RandomAccessIterator::value_type;
	__pop_heap_aux(first, last, x1);
	delete x1;
}


//sort_heap
//只要一直对heap做pop_heap操作即可,pop_heap把最大值放到底部容器（vector）的末尾，并不删除
template <typename RandomAccessIterator>
inline void sort_heap(RandomAccessIterator first, RandomAccessIterator last)
{
	while(last - first > 1)
		pop_heap(first, last--);
}

//make_heap
template <typename RandomAccessIterator, typename T, typename Distance>
inline void __make_heap(RandomAccessIterator first, RandomAccessIterator last, T *, Distance *)
{
	if (last - first < 2) return;
	Distance len = last - first;
	Distance parent = (len - 2) / 2;
	while(true)
	{
		__adjust_heap(first, parent, len, T(*(first + parent)));
		if(parent == 0) return;
		parent --;
	}
}

template <typename RandomAccessIterator>
inline void make_heap(RandomAccessIterator first, RandomAccessIterator last)
{
	RandomAccessIterator::value_type * x1 = new RandomAccessIterator::value_type;
	RandomAccessIterator::distance_type * x2 = new RandomAccessIterator::distance_type;
	__make_heap(first, last, x1, x2);
	delete x1;
	delete x2;
}

#endif