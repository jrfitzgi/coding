#include <exception>
#include <iostream>
#include "jStack.h"

using namespace std;

jStack::jStack()
{
	this->topNode = NULL;
}

void jStack::push(int value)
{
	jNode* newTop = new jNode();
	newTop->value = value;
	newTop->next = this->topNode;
	this->topNode = newTop;
}

int jStack::pop()
{
	if (this->isEmpty())
	{
		throw exception("Stack is empty");
	}
	else
	{
		jNode* popNode = this->topNode;
		int value = popNode->value;
		this->topNode = this->topNode->next;

		delete popNode;

		return value;
	}
}

bool jStack::isEmpty()
{
	return (this->topNode == NULL);
}
