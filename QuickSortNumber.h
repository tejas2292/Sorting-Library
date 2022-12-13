#pragma once
class QuickSortNumber
{
public:
	void swap(double* a, double* b);
	void quickSort(double array[], int low, int high);
	int partition(double array[], int low, int high);
};

