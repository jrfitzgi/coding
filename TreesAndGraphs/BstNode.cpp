#include <iostream>
#include "BstNode.h"
#include <queue>

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

void BstNode::Insert(BstNode* node)
{
	if (NULL == node)
	{
		return;
	}

	if (node->value < this->value)
	{
		if (NULL == this->left)
		{
			this->left = node;
		}
		else
		{
			this->left->Insert(node);
		}
	}
	else //(node->value >= this->value)
	{
		if (NULL == this->right)
		{
			this->right = node;
		}
		else
		{
			this->right->Insert(node);
		}
	}
}

BstNode* BstNode::ConstructBst()
{
	BstNode* root = new BstNode(3);
	root->Insert(new BstNode(1));
	root->Insert(new BstNode(2));
	root->Insert(new BstNode(4));
	root->Insert(new BstNode(5));
	return root;
}

void BstNode::InOrderPrint(BstNode* node)
{
	if (NULL == node)
	{
		return;
	}

	InOrderPrint(node->left);
	cout << node->value << endl;
	InOrderPrint(node->right);
}