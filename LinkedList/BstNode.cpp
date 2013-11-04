#include <iostream>
#include "BstNode.h"

using namespace std;

BstNode::BstNode(int value)
{
	this->value = value;
}


BstNode::~BstNode()
{
	delete this->left;
	delete this->right;
}

BstNode::BstNode* ConstructBst()
{
	BstNode* root = new BstNode(1);
	root->left = new BstNode(2);
	root->right = new BstNode(3);
	root->left->left = new BstNode(4);
	root->left->right = new BstNode(5);

	//pre:  1,2,4,5,3
	//in:   4,2,5,1,3
	//post: 4,5,2,3,1

	return root;
}


void BstNode::PreOrderPrint()
{
	cout << this->value << endl;

	if (this->left != NULL)
	{
		this->left->PreOrderPrint();
	}

	if (this->right != NULL)
	{
		this->right->PreOrderPrint();
	}
}

