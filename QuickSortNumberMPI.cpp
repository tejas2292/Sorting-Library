#include "QuickSortNumberMPI.h"
#include <omp.h>
#include <iostream>
int k=0;

void QuickSortNumberMPI::swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void QuickSortNumberMPI::quickSort(double arr[], int low_index, int high_index)
{
	int j;

	if (low_index < high_index)
	{
		j = partition(arr, low_index, high_index);
		//cout << "Pivot element with index " << j << " has been found out by thread " << k << "\n";

#pragma omp parallel sections
		{
#pragma omp section
			{
				k = k + 1;
				quickSort(arr, low_index, j - 1);
			}

#pragma omp section
			{
				k = k + 1;
				quickSort(arr, j + 1, high_index);
			}

		}
	}
	

}

int QuickSortNumberMPI::partition(double arr[], int low_index, int high_index)
{
	int i, j, temp, key;
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
