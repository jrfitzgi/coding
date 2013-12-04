#include <exception>
#include <iostream>
#include "jStack.h"
#include "jQueue.h"

using namespace std;

void testQueue();
void testStack();


int main(int argc, char** args)
{
	testQueue();
	system("PAUSE");

}

void testQueue()
{
	jQueue queue = jQueue();
	for (int i=0; i<6; i++)
	{
		queue.enqueue(i);
		cout << queue.dequeue() << endl;

	}

	for (int i=6; i<11; i++)
	{
		queue.enqueue(i);
	}


	while(!queue.isEmpty())
	{
		cout << queue.dequeue() << endl;
	}

	try
	{
		cout << queue.dequeue() << endl;
	}
	catch (exception const & e)
	{
		cout << e.what() << endl;
	}
}

void testStack()
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
}
