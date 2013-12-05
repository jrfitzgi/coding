#ifndef BTNODE_H
#define BTNODE_H

using namespace std;


class BtNode
{
public:

	BtNode(int value=0);
	~BtNode();

	BtNode* left;
	BtNode* right;
	int value;

	static BtNode* ConstructBt();

	static void PreOrderPrint(BtNode* node);
	static void InOrderPrint(BtNode* node);
	static void PostOrderPrint(BtNode* node);

	static void LevelOrderPrintLines_TwoQueues(BtNode* node);
	static void LevelOrderPrintLines_TwoCounters(BtNode* node);
	static void LevelOrderPrintLines_Markers(BtNode* node);
	static void LevelOrderPrintFlat(BtNode* node);

};

#endif