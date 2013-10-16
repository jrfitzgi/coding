#include <iostream>
#include <bitset>

using namespace std;

void printIntInBinary(int number);
int subtract(int a, int b);
int lowest1Bit(int n);

int main()
{
	int result = lowest1Bit(8);
	//printIntInBinary(result);
	cout << result << endl;

	system("PAUSE");
}