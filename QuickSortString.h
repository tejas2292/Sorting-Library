#pragma once
#include <String>
#include <iostream>
using namespace::std;

class QuickSortString
{
public:
	void swap(string* a, string* b);
	void quickSort(string array[], int low, int high);
	int partition(string array[], int low, int high);
};