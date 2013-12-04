#include <iostream>
#include "BtNode.h"

using namespace std;

int main(int argc, char** argv)
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
	system("PAUSE");
}