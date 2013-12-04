#include <exception>
#include <iostream>
#include "jQueue.h"

using namespace std;

jQueue::jQueue()
{
	this->first = NULL;
	this->last = NULL;
	this->minNode = NULL;
}

void jQueue::enqueue(int value)
{
	jNode* newNode = new jNode(value);

	if (this->isEmpty())
	{
		// this is the first node in the queue
		this->first = newNode;
		this->last = newNode;
	}
	else
	{
		this->last->next = newNode;
		this->last = newNode;
	}
}

int jQueue::dequeue()
{
	if (!this->isEmpty())
	{
		// re-arrange the first node pointer
		jNode* dequeueNode = this->first;
		this->first = dequeueNode->next;

		// store the result, delete the storage node, return the result
		int result = dequeueNode->value;
		delete dequeueNode;
		return result;
	}
	else
	{
		throw exception("The queue is empty");
	}
}

int jQueue::front()
{
	if (!this->isEmpty())
	{
		return this->first->value;
	}
	else
	{
		throw exception("The queue is empty");
	}
}

bool jQueue::isEmpty()
{
	return (NULL == this->first);
}
