#include <iostream>
#include <limits>
using namespace std;

int GetTriangleType(int a, int b, int c)
{
	// Check for valid side lengths
	if (a<=0 || b<=0 || c<=0)
	{
		return 4;
	}

	// Convert to double for arithmetic to avoid overflows
	double A = a;
	double B = b;
	double C = c;

	// Check triangle inequality rule
	// For a side of lengths a, b, c, b-c < a < b+c
	if (abs(B-C) >= A || B+C <= A || abs(A-C) >= B || A+C <= B || abs(A-B) >= C || A+B <= C)
	{
		return 4;
	}

	// Check for equilateral
	if (a==b && b==c)
	{
		return 3;
	}

	// If any two sides are equal, it must be isosceles since it can't be equilateral at this point
	else if (a==b || b==c || a==c)
	{
		return 2;
	}

	// If it is not equilateral or isosceles, it must be scalene
	else
	{
		return 1;
	}

}

void TestGetTriangleType(int a, int b, int c, int expected)
{
	int result = GetTriangleType(a,b,c);


	if (result == expected)
	{
		cout << "PASS";
	}
	else
	{
		cout << "*FAIL";
	}

	cout << " input:" << a << "," << b << "," << c << " expected:" << expected << " actual:" << result << endl;

}

void RunTests()
{
	int max = numeric_limits<int>::max();
	int min = numeric_limits<int>::min();

	cout << "Valid Equilateral" << endl;
	TestGetTriangleType(1,1,1,3);
	TestGetTriangleType(100,100,100,3);
	TestGetTriangleType(max,max,max,3);
	cout << endl;

	cout << "Valid Isosceles" << endl;
	TestGetTriangleType(1,2,2,2);
	TestGetTriangleType(10000,1,10000,2);
	TestGetTriangleType(max,max,1,2);
	cout << endl;

	cout << "Valid Scalene" << endl;
	TestGetTriangleType(2,3,4,1);
	TestGetTriangleType(10,100001,100000,1);
	TestGetTriangleType(max,max-1,max-2,1);
	cout << endl;

	cout << "Invalid Inequality" << endl;
	TestGetTriangleType(2,2,4,4);
	TestGetTriangleType(5,3,1,4);
	TestGetTriangleType(1,1,10,4);
	cout << endl;

	cout << "Errors with 0 length sides" << endl;
	TestGetTriangleType(0,1,1,4);
	TestGetTriangleType(0,0,1,4);
	TestGetTriangleType(0,0,0,4);
	cout << endl;

	cout << "Erros with negative length sides" << endl;
	TestGetTriangleType(1,1,-1,4);
	TestGetTriangleType(-1,-1,1,4);
	TestGetTriangleType(-1,-1,-1,4);
	TestGetTriangleType(min,min,min,4);
	cout << endl;

}

int main(int argc, char** args)
{
	RunTests();
	system("PAUSE");
}

