#include <iostream>
#include "BstNode.h"

using namespace std;

int main(int argc, char** argv)
{
	BstNode* root = BstNode::ConstructBst();

	cout << endl << "PreOrder" << endl;
	BstNode::PreOrderPrint(root);

	cout << endl << "InOrder" << endl;
	BstNode::InOrderPrint(root);

	cout << endl << "PostOrder" << endl;
	BstNode::PostOrderPrint(root);

	cout << endl << "LevelOrderPrintLines_TwoQueues" << endl;;
	BstNode::LevelOrderPrintLines_TwoQueues(root);

	cout << endl << "LevelOrderPrintLines_TwoCounters" << endl;;
	BstNode::LevelOrderPrintLines_TwoCounters(root);

	cout << endl << "LevelOrderPrintLines_Markers" << endl;;
	BstNode::LevelOrderPrintLines_Markers(root);

	cout << endl << "LevelOrderFlat" << endl;;
	BstNode::LevelOrderPrintFlat(root);

	cout << endl;
	system("PAUSE");
}