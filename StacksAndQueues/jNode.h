using namespace std;

#ifndef JNODE_H
#define JNODE_H

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