class BstNode
{
public:

	BstNode(int value=0);
	~BstNode();

	BstNode* left;
	BstNode* right;
	int value;

	static BstNode* ConstructBst();

	void PreOrderPrint();
	//void PostOrderPrint();
	//void InOrderPrint();

};
