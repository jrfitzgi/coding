#include <iostream>
#include "Node.h"

using namespace std;

int main(int argc, char** argv)
{

 	int nodeValues[] = {1, 2, 3, 4, 5};
	Node* head = new Node(nodeValues, 5);
	head->PrintLinkedList();

	Node::DeleteNode(head, 3);

	head->PrintLinkedList();

	system("PAUSE");
}