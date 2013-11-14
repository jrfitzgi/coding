using namespace std;

class BstNode
{
public:

	BstNode(int value=0);
	~BstNode();

	BstNode* left;
	BstNode* right;
	int value;

	static BstNode* ConstructBst();

	static void PreOrderPrint(BstNode* node);
	static void InOrderPrint(BstNode* node);
	static void PostOrderPrint(BstNode* node);

	static void LevelOrderPrintLines_TwoQueues(BstNode* node);
	static void LevelOrderPrintLines_TwoCounters(BstNode* node);
	static void LevelOrderPrintLines_Markers(BstNode* node);
	static void LevelOrderPrintFlat(BstNode* node);

};
