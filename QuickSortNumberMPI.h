#pragma once

#include <iostream>

using namespace::std;

class QuickSortNumberMPI
{
public:
	void swap(double* a, double* b);
	void quickSort(double array[], int low, int high);
	int partition(double array[], int low, int high);
};