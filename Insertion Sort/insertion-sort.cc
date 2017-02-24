/*
* Insertion sort using binary search 
* Created on: 06-10-16
* Done by Dharini Sreenivasan and Divya Ramnath 
*/

#include <assert.h>
#include<stdio.h>
#include<stdlib.h>

#include "sort.hh"

int binarysearch(unsigned long a[], int key, int low, int high)
{
	int mid;
	mid = (high + low) / 2;
	if (low == high)
		return low;
	if (key < a[mid])
		return(binarysearch(a, key, low, mid));
	else if (key > a[mid])
		return(binarysearch(a, key, mid + 1, high));
	return mid;
}

void insertionSort(int N, keytype* A)
{
	int key, pos, temp, i, j;
	for (int j = 1; j<N; j++)
	{
		pos = binarysearch(A, A[j], 0, j);
		temp = A[j];
		for (int i = j - 1; i >= pos; i--)
		{
			A[i + 1] = A[i];
		}
		A[pos] = temp; 
	}
}
