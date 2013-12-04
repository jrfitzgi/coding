#include "BtNode.h"

using namespace std;

class BstNode : BtNode
{
public:

	BstNode(int value=0);
	~BstNode();

	void Insert(BstNode* root, BstNode* node);

	static BtNode* ConstructBst();

};