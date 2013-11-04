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


void MergeSort(int a[], int b[], int start, int end)
{
	cout << "Called mergesort with start and end as " << start << " " << end << endl;

	if (a == NULL || start > end || start == end)
	{
		cout << "Base case for element [" << start << "]=" << a[start] << endl;
		return;
	}

	int middle = start + (end-start)/2;
	cout << "Middle of " << start << " and " << end << " is " << middle << endl;

	cout << "Calling Mergesort on left " << start << "-" << middle << " and right " << middle+1 << "-" << end << endl;
	MergeSort(a, b, start, middle);
	MergeSort(a, b, middle+1, end);

	// merge left and right
	int leftIndex = start;
	int rightIndex = middle+1;

	cout << "Merging on left " << start << "-" << middle << " and right " << middle+1 << "-" << end << endl;

	for (int i=start; i <= end; i++)
	{
		if (leftIndex > middle)
		{
			// no more items in left
			cout << "No items remain in left. Adding right's " << a[rightIndex] << endl;
			b[i] = a[rightIndex];
			rightIndex++;
		}
		else if (rightIndex > end)
		{
			// no more items in right
			cout << "No items remain in right. Adding left's " << a[leftIndex] << endl;
			b[i] = a[leftIndex];
			leftIndex++;
		}
		else if (a[leftIndex] <= a[rightIndex])
		{
			cout << "Adding left's" << a[leftIndex] << endl;
			b[i] = a[leftIndex];
			leftIndex++;
		}
		else
		{
			cout << "Adding right's " << a[rightIndex] << endl;
			b[i] = a[rightIndex];
			rightIndex++;
		}

	}

	// Copy b back into a
	cout << "Copying b back into a" << endl;
	for (int i=start; i <= end; i++)
	{
		a[i] = b[i];
	}

	cout << "a now looks like this ";
	printIntArray(a, end-start+1);

}

void MergeSort(int a[], int b[], const int length)
{
	MergeSort(a, b, 0, length-1);
}

