#include <exception>
#include "jNode.h"

using namespace std;

class jStack
{
protected:
	jNode* topNode;

public:
	jStack();
	void push(int value);
	int pop();
	bool isEmpty();
};