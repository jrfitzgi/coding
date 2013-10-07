#include<iostream>
using namespace std;

char* LinearReverse(char* originalString)
{
	cout << "LinearReverse" << endl;
	cout << "Reversing: " << originalString << endl;

	int stringLength = strlen(originalString);
	cout << "String length is " << stringLength << endl;

	char* reversedString = new char[stringLength + 1];
	reversedString[stringLength] = '\0';

	for (int i=0; i < stringLength; i++)
	{
		reversedString[i] = originalString[stringLength-i-1];
	}

	cout << "Reversed:  " << reversedString << endl << endl;
	return reversedString;
}

char* InPlaceReverse(char* originalString)
{
	cout << "InPlaceReverse" << endl;
	cout << "Reversing: " << originalString << endl;

	int stringLength = strlen(originalString);
	cout << "String length is " << stringLength << endl;

	char temp;
	char* start = originalString;
	char* end = originalString;

	if (originalString)
	{
		// Find the end of the string
		while (*end)
		{
			end++;
		}
		end--;

		while (start < end)
		{
			temp = *start;
			*start = *end;
			*end = temp;

			start++;
			end--;
		}

	}

	cout << "Reversed:  " << originalString << endl << endl;
	return originalString;
}
