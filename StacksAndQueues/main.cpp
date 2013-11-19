#include <exception>
#include <iostream>
#include "jStack.h"

using namespace std;

int main(int argc, char** args)
{
	jStack stack = jStack();
	stack.push(1);
	stack.push(2);
	stack.push(3);

	while(!stack.isEmpty())
	{
		cout << stack.pop() << endl;
	}

	try
	{
		cout << stack.pop() << endl;
	}
	catch (exception const & e)
	{
		cout << e.what() << endl;
	}

	system("PAUSE");
}