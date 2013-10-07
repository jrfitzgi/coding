#include<iostream>
using namespace std;

char* LinearReverse(char* originalString);
char* InPlaceReverse(char* originalString);

int main(int argc, char** args)
{
	char test1[] = "12345";
	char* test2 = "abcde";

	LinearReverse(test1);
	LinearReverse(test2);

	InPlaceReverse(test1);
	
	// Won't work since test2 points to a constant 
	//InPlaceReverse(test2);

	system("PAUSE");
}
