#include "QuickSortString.h"
#include <iostream>
#include <cstdlib>
#include <random>


void QuickSortString::swap(string* a, string* b)
{
	string t = *a;
	*a = *b;
	*b = t;
}

void QuickSortString::quickSort(string array[], int low, int high)
{
	if (low < high) {
		int partI = partition(array, low, high);
		quickSort(array, low, partI - 1);
		quickSort(array, partI + 1, high);
	}
}

int QuickSortString::partition(string array[], int low, int high)
{
	string pivot = array[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
}
