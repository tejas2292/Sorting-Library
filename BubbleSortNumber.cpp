#include "BubbleSortNumber.h"
#include <iostream>

void BubbleSortNumber::swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void BubbleSortNumber::sort(double array[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
