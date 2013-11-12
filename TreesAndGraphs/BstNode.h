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

	static void LevelOrderPrintFlat(BstNode* node);
	static void LevelOrderPrintLines(BstNode* node);

};
