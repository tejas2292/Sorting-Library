#include "QuickSortNumber.h"

void QuickSortNumber::swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void QuickSortNumber::quickSort(double array[], int low, int high)
{
	if (low < high) {
		int partI = partition(array, low, high);
		quickSort(array, low, partI - 1);
		quickSort(array, partI + 1, high);
	}
}

int QuickSortNumber::partition(double array[], int low, int high)
{
	double pivot = array[high];
	int i = low - 1;
	for (int j = low; j <= high-1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
}
