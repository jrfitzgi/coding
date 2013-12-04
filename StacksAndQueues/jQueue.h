#include <iostream>
#include "jNode.h"

using namespace std;

class jQueue
{
protected:
	jNode* first;
	jNode* last;
	jNode* minNode;
public:
	jQueue();
	void enqueue(int value);
	int dequeue();
	int front();
	bool isEmpty();
};