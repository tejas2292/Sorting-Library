#include "QuickSortStringMPI.h"
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <random>
int u = 0;

void QuickSortStringMPI::swap(string* a, string* b)
{
	string t = *a;
	*a = *b;
	*b = t;
}

void QuickSortStringMPI::quickSort(string arr[], int low_index, int high_index)
{
	int j;

	if (low_index < high_index)
	{
		j = partition(arr, low_index, high_index);
		//cout << "Pivot element with index " << j << " has been found out by thread " << u << "\n";

#pragma omp parallel sections
		{
#pragma omp section
			{
				u = u + 1;
				quickSort(arr, low_index, j - 1);
			}

#pragma omp section
			{
				u = u + 1;
				quickSort(arr, j + 1, high_index);
			}

		}
	}


}

int QuickSortStringMPI::partition(string arr[], int low_index, int high_index)
{
	int i, j;
	string temp;
	string key;
	key = arr[low_index];
	i = low_index + 1;
	j = high_index;
	while (1)
	{
		while (i < high_index && key >= arr[i])
			i++;
		while (key < arr[j])
			j--;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp = arr[low_index];
			arr[low_index] = arr[j];
			arr[j] = temp;
			return(j);
		}
	}
}
