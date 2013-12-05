#include "BtNode.h"

using namespace std;

class BstNode //: BtNode
{
public:

	BstNode(int value=0);
	~BstNode();

	BstNode* left;
	BstNode* right;
	int value;

	void Insert(BstNode* node);
	static BstNode* ConstructBst();
	static void InOrderPrint(BstNode* node);

};