#include <iostream>

using namespace std;

void MergeSort(int a[], int b[], const int length);
void printIntArray(int a[], int length);

int main()
{
	const int length = 8;
	int a[] = {5, 2, 1, 3, 99, 3, 10, 20};
	int b[length];

	//const int length = 7;
	//int a[] = {4, 3, 2, 1, 6, 5, 7};
	//int b[length];

	printIntArray(a, length);

	MergeSort(a, b, length);
	cout << "DONE" << endl;
	printIntArray(a, length);

	system("pause");
}

