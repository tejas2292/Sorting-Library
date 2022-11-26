#include <random>
#include "BubbleSort.h"
#include "QuickSort.h"
#include <chrono>

using namespace std;

int main() {
	int sizeInput;
	cout << "Please enter an array size: ";
	while (true) {
		cin >> sizeInput;
		if (sizeInput == NULL or sizeInput <= 0 or sizeInput > 1000000) {
			cout << "Please enter a number between 1 and 1 million.\n";
		}
		else {
			break;
		}
	}
	// Create two arrays of 1E6 elements, only sizeInput elements will be filled.
	double* array1 = new double[1000000];
	double* array2 = new double[1000000];
	srand(time(NULL));
	for (int i = 0; i < sizeInput; i++) {
		array1[i] = rand() % 10000001;
		array2[i] = rand() % 10000001;
	}
	auto start = chrono::high_resolution_clock::now();
	// Bubble sort
	BubbleSort* bubbles = new BubbleSort();

	bubbles->sort(array1, sizeInput);

	// Quicksort
	//cout << "Quicksorting array 2:\n";
	QuickSort* quicks = new QuickSort();
	quicks->quickSort(array2, 0, sizeInput);

	auto stop = chrono::high_resolution_clock::now();
	chrono::microseconds time = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Elapsed time: " << time.count() << " us";
	/*
	for (int i = 0; i < sizeInput; i++) {
		cout << array2[i] << " ";
	}
	*/

	// Delete both arrays
	delete[] array1;
	delete[] array2;

	return 0;
}