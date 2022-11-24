#pragma once
class QuickSort
{
public:
	void swap(double* a, double* b);
	void quickSort(double array[], int low, int high);
	int partition(double array[], int low, int high);
};

