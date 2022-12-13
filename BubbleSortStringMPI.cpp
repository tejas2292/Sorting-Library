#include "BubbleSortStringMPI.h"
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <random>


void BubbleSortStringMPI::sort(string A[], int N)
{
	int first,i,j;
	for (i = 0; i < N - 1; i++)
	{
		first = i % 2;
#pragma omp parallel for default(none),shared(A,first,N)
		for (j = first; j < N - 1; j += 1)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}

void BubbleSortStringMPI::swap(string* num1, string* num2) {
    string temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
