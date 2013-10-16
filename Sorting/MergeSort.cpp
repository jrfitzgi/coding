#include <iostream>

using namespace std;

void printIntArray(int a[], int length)
{
	for (int i=0; i < length; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}


int* MergeSort(int a[], int b[], int start, int end)
{
	cout << "Called mergesort with start and end as " << start << " " << end << endl;

	if (a == NULL || start > end || start == end)
	{
		cout << "Base case, returning address of " << a[start] << endl;

		// Base case: There are 0 or 1 elements
		return &a[start];
	}

	int middle = (end-start)/2;
	cout << "Middle of " << start << " and " << end << " is " << middle << endl;

	cout << "Calling into mergesort... " << endl;
	int* left = MergeSort(a, b, start, middle);
	int* right = MergeSort(a, b, middle+1, end);

	// merge left and right
	int leftIndex = 0;
	int rightIndex = 0;

	cout << "Merging. Start and End are " << start << " " << end << endl;
	for (int i=start; i <= end; i++)
	{
		if (leftIndex > middle - start)
		{
			// no more items in left
			cout << "No items remain in left. Adding right's " << right[rightIndex] << endl;
			b[i] = right[rightIndex];
		}
		else if (rightIndex > end - middle)
		{
			// no more items in right
			cout << "No items remain in right. Adding left's " << left[leftIndex] << endl;
			b[i] = left[leftIndex];
		}
		else if (left[leftIndex] <= right[rightIndex])
		{
			cout << "Adding left's" << left[leftIndex] << endl;
			b[i] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			cout << "Adding rights's" << right[rightIndex] << endl;
			b[i] = right[rightIndex];
			rightIndex++;
		}

	}

	cout << "Return b ";
	printIntArray(b, end-start+1);
	
	return b;
}

int* MergeSort(int a[], int b[], const int length)
{
	int* result = MergeSort(a, b, 0, length-1);
	return result;
}

