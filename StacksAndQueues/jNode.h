#ifndef JNODE_H
#define JNODE_H

using namespace std;

class jNode
{
protected:
	virtual void construct(int value);

public:
	int value;
	jNode* next;

	jNode();
	jNode(int value);
};

#endif