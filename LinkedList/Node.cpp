#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int value)
{
	this->value = value;
}

Node::Node(int values[], int numValues)
{
	if (values != NULL && numValues > 0)
	{
		this->value = values[0];

		if (numValues > 1)
		{
			this->next = new Node(&values[1], numValues - 1);
		}
	}
}

Node::~Node()
{
	//delete this->next;
}

void Node::PrintLinkedList()
{
	cout << this->value << "->";

	if (this->next != NULL)
	{
		this->next->PrintLinkedList();
	}
	else
	{
		cout << "NULL" << endl;
	}
}

Node* Node::DeleteNode(Node* node, int value)
{
	Node* head = node;

	if (node == NULL)
	{
		return NULL;
	}

	if (node->value == value)
	{
		head = node->next;
		delete node;
		return head;
	}

	Node* temp = node;
	while (node->next != NULL)
	{
		if (node->next->value == value)
		{
			temp = node->next->next;
			delete node->next;
			node->next = temp;
		}

		node = node->next;
	}

	return head;
}


