#include <iostream>

using namespace std;

int* MergeSort(int a[], int b[], const int length);
void printIntArray(int a[], int length);

int main()
{
	//const int length = 8;
	//int a[] = {5, 2, 1, 4, 99, 3, 10, 20};
	//int b[length];

	const int length = 2;
	int a[] = {5, 2};
	int b[length];

	printIntArray(a, length);

	int* sortedArray = MergeSort(a, b, length);
	printIntArray(sortedArray, length);

	system("pause");
}

