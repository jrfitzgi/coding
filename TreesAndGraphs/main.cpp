#include <iostream>
#include "BtNode.h"
#include "BstNode.h"

using namespace std;

void TestBt();
void TestBst();

int main(int argc, char** argv)
{
	TestBst();
	system("PAUSE");
}

void TestBst()
{
	BstNode* root1 = BstNode::ConstructBalancedBst();
	cout << endl << "InOrder" << endl;
	BtNode::InOrderPrint((BtNode*)root1);

	cout << endl;
	cout << "Depth: " << root1->GetDepth() << endl;
	cout << "Nodes: " << root1->GetNodeCount() << endl;

	if (BstNode::IsBalanced(root1))
	{
		cout << "Tree is balanced" << endl;
	}
	else
	{
		cout << "Tree is not balanced" << endl;
	}

	BstNode* root2 = BstNode::ConstructOneLevelImbalanceBst();
	cout << endl << "InOrder" << endl;
	BtNode::InOrderPrint((BtNode*)root2);

	cout << endl;
	cout << "Depth: " << root2->GetDepth() << endl;
	cout << "Nodes: " << root2->GetNodeCount() << endl;

	if (BstNode::IsBalanced(root2))
	{
		cout << "Tree is balanced" << endl;
	}
	else
	{
		cout << "Tree is not balanced" << endl;
	}

	BstNode* root3 = BstNode::ConstructTwoLevelImbalanceBst();
	cout << endl << "InOrder" << endl;
	BtNode::InOrderPrint((BtNode*)root3);

	cout << endl;
	cout << "Depth: " << root3->GetDepth() << endl;
	cout << "Nodes: " << root3->GetNodeCount() << endl;

	if (BstNode::IsBalanced(root3))
	{
		cout << "Tree is balanced" << endl;
	}
	else
	{
		cout << "Tree is not balanced" << endl;
	}

}

void TestBt()
{
	BtNode* root = BtNode::ConstructBt();

	cout << endl << "PreOrder" << endl;
	BtNode::PreOrderPrint(root);

	cout << endl << "InOrder" << endl;
	BtNode::InOrderPrint(root);

	cout << endl << "PostOrder" << endl;
	BtNode::PostOrderPrint(root);

	cout << endl << "LevelOrderPrintLines_TwoQueues" << endl;;
	BtNode::LevelOrderPrintLines_TwoQueues(root);

	cout << endl << "LevelOrderPrintLines_TwoCounters" << endl;;
	BtNode::LevelOrderPrintLines_TwoCounters(root);

	cout << endl << "LevelOrderPrintLines_Markers" << endl;;
	BtNode::LevelOrderPrintLines_Markers(root);

	cout << endl << "LevelOrderFlat" << endl;;
	BtNode::LevelOrderPrintFlat(root);

	cout << endl;
}