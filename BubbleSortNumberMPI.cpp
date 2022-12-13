#include "BubbleSortNumberMPI.h"
#include <omp.h>
#include <iostream>

void BubbleSortNumberMPI::swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void BubbleSortNumberMPI::sort(double array[], int size)
{
	
#pragma omp parallel for default(none) shared(array,size)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
