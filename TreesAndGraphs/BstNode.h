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

	int GetDepth();
	int GetNodeCount();
	void Insert(BstNode* node);

	static BstNode* ConstructBalancedBst();
	static BstNode* ConstructInvalidBst();
	static BstNode* ConstructOneLevelImbalanceBst();
	static BstNode* ConstructTwoLevelImbalanceBst();
	static void InOrderPrint(BstNode* node);
	static bool IsBst(BstNode* root, int min, int max);
	static bool IsBalanced(BstNode* root);
};