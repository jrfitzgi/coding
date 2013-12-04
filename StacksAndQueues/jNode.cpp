#include <iostream>
#include "jNode.h"

using namespace std;

void jNode::construct(int value)
{
	this->value = value;
	this->next = NULL;
}

jNode::jNode()
{
	this->construct(-1);
}

jNode::jNode(int value)
{
	this->construct(value);
}
