#include <iostream>
#include "BstNode.h"

using namespace std;

int main(int argc, char** argv)
{
	BstNode* root = BstNode::ConstructBst();

	cout << "PreOrder" << endl;
	root->PreOrderPrint();

	cout << "InOrder" << endl;
	root->InOrderPrint();

	cout << "PostOrder" << endl;
	root->PostOrderPrint();

	system("PAUSE");
}