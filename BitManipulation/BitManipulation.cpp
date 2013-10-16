#include <iostream>
#include <bitset>

using namespace std;

void printIntInBinary(int number)
{
	bitset<16> output = bitset<16>(number);
	cout << output << endl;;
}

void printCharInBinary(char character)
{
	bitset<8> output(character);
	cout << output << endl;
}

int subtract(int a, int b)
{
	int result = a & ~b;
	return result;
}

int lowest1Bit(int n)
{
	int valueOfLowest1Bit = n & ~(n-1);

	// perform a bit scan to figure out the index from the right (least significant) side
	unsigned long index = NULL;
	char isNonzero = _BitScanForward(&index, valueOfLowest1Bit);

	if (isNonzero == true)
	{
		return index;
	}
	else
	{
		return 0;
	}
}