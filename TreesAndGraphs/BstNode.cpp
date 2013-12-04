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

void BstNode::Insert(BstNode* root, BstNode* node)
{
	
}

BstNode* BstNode::ConstructBst()
{
	BstNode* root = new BstNode(1);
	root->left = new BstNode(2);
	root->right = new BstNode(3);
	root->left->left = new BstNode(4);
	root->left->right = new BstNode(5);
	return root;
}

