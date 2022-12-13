#include "BubbleSortString.h"
#include <iostream>
#include <cstdlib>
#include <random>

void BubbleSortString::sort(string array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }


	
}
