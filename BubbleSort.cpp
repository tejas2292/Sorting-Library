#include "BubbleSort.h"

void BubbleSort::swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort::sort(double array[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}
