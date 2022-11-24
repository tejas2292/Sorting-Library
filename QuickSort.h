#pragma once
class QuickSort
{
public:
	void swap(double* a, int* b);
	void quickSort(int array[], int low, int high);
	int partition(int array[], int low, int high);
};

