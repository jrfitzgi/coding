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
			this->next = Node(&values[1], numValues - 1);
		}
	}
}

void Node::PrintLinkedList()
{
	cout << value << "->";

	if (this->next != NULL)
	{
		this->next.PrintLinkedList();
	}
	else
	{
		cout << "NULL" << endl;
	}
}

Node Node::DeleteNode(Node node, int value)
{
//	if (node == NULL)
//	{
//		return NULL;
//	}


	if (node.value == value)
	{
		return node.next;
	}

	Node head = node;
	while (node.next != NULL)
	{
		if (node.next.value == value)
		{
			node.next = node.next.next;
		}

		node = node.next;
	}


	return head;
}


