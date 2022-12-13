#include <random>
#include "BubbleSortNumberMPI.h"
#include "BubbleSortNumber.h"
#include "BubbleSortString.h"
#include "BubbleSortStringMPI.h"
#include "QuickSortNumberMPI.h"
#include "QuickSortNumber.h"
#include "QuickSortString.h"
#include "QuickSortStringMPI.h"
#include "RandStringGenerator.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <omp.h>
#include <chrono>

using namespace std;
int sizeInput, ch1;
double* arrayNumber = new double[1000000];
double* tempNumber = new double[1000000];
string* arrayString = new string[1000000];
string* tempString = new string[1000000];

BubbleSortNumber* bubbleNumber = new BubbleSortNumber();
BubbleSortString* bubbleString = new BubbleSortString();
BubbleSortNumberMPI* bubbleNumberMPI = new BubbleSortNumberMPI();
BubbleSortStringMPI* bubbleStringMPI = new BubbleSortStringMPI();
QuickSortNumber* quickNumber = new QuickSortNumber();
QuickSortString* quickString = new QuickSortString();
QuickSortNumberMPI* quickNumberMPI = new QuickSortNumberMPI();
QuickSortStringMPI* quickStringMPI = new QuickSortStringMPI();


void printNumbersArray() {
	for (int i = 0; i < sizeInput; i++) {
		tempNumber[i] = arrayNumber[i];
		cout << " " << arrayNumber[i];
	}
	cout << endl;
}

void sortedNumbersArray() {
	int i;
	int j = 0;

	for (i = 0; i < sizeInput; i++) {
		for (j=0; j< sizeInput; j++)
		{
			if (tempNumber[j] == arrayNumber[i]) {
				cout<<" "<< arrayNumber[i] << "(" << j << ")";
				break;
			}
		}
	}
	
}

void printStringArray() {
	for (int i = 0; i < sizeInput; i++) {
		tempString[i] = arrayString[i];
		cout << " " << arrayString[i];
	}
	cout << endl;
}

void sortedStringArray() {
	int i;
	int j = 0;

	for (i = 0; i < sizeInput; i++) {
		for (j = 0; j < sizeInput; j++)
		{
			if (tempString[j] == arrayString[i]) {
				cout << " " << arrayString[i] << "(" << j << ")";
				break;
			}
		}
	}
}

void getUserInput() {
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
}

void numbersArrayCreation() {
	for (int i = 0; i < sizeInput; i++) {
		arrayNumber[i] = rand() % 10000001;
	}
}

void stringsArrayCreation() {
	RandStringGenerator* randString = new RandStringGenerator();
	for (int i = 0; i < sizeInput; i++)
	{
		arrayString[i] = randString->random_string(5);
	}
}


int main() {
	
	cout << "\n ------------------- Select Sorting Type -------------------";
	cout << "\n 1: Bubble Sort Sequential Number";
	cout << "\n 2: Bubble Sort Sequential String";
	cout << "\n 3: Bubble Sort Parallel Number";
	cout << "\n 4: Bubble Sort Parallel String";
	cout << "\n 5: Quick Sort Sequential Number";
	cout << "\n 6: Quick Sort Sequential String";
	cout << "\n 7: Quick Sort Parallel Number";
	cout << "\n 8: Quick Sort Parallel String";
	cout << "\n 9: Exit";
	cout << "\n Enter Your Choice : ";
	cin >> ch1;

	switch (ch1)
	{
	case 1:
		getUserInput();
		numbersArrayCreation();
		printNumbersArray();
		bubbleNumber->sort(arrayNumber, sizeInput);
		sortedNumbersArray();
		break;
	case 2:
		getUserInput();
		stringsArrayCreation();
		printStringArray();
		bubbleString->sort(arrayString, sizeInput);
		sortedStringArray();
		break;
	case 3:
		getUserInput();
		numbersArrayCreation();
		printNumbersArray();
		bubbleNumberMPI->sort(arrayNumber, sizeInput);
		sortedNumbersArray();
		break;
	case 4:
		getUserInput();
		stringsArrayCreation();
		printStringArray();
		bubbleStringMPI->sort(arrayString, sizeInput);
		sortedStringArray();
		break;
	case 5:
		getUserInput();
		numbersArrayCreation();
		printNumbersArray();
		quickNumber->quickSort(arrayNumber,0, sizeInput-1);
		sortedNumbersArray();
		break;
	case 6:
		getUserInput();
		stringsArrayCreation();
		printStringArray();
		quickString->quickSort(arrayString, 0, sizeInput - 1);
		sortedStringArray();
		break;
	case 7:
		getUserInput();
		numbersArrayCreation();
		printNumbersArray();
		quickNumberMPI->quickSort(arrayNumber, 0, sizeInput - 1);
		sortedNumbersArray();
		break;
	case 8:
		getUserInput();
		stringsArrayCreation();
		printStringArray();
		quickStringMPI->quickSort(arrayString, 0, sizeInput - 1);
		sortedStringArray();
		break;
	default:
		cout << "\n Wrong input!! Please try again...";
		break;
	}

	return 0;
}