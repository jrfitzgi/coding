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
	BstNode* root = BstNode::ConstructBst();

	cout << endl << "InOrder" << endl;
	BtNode::InOrderPrint((BtNode*)root);

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