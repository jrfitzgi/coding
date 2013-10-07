// node.h

class Node
{
public:

	Node(int value=0);
	Node(int values[], int numValues);

	Node next;
	int value;

	void PrintLinkedList();

	static Node DeleteNode(Node head, int value);
};
