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

BstNode* BstNode::ConstructBst()
{
	BstNode* root = new BstNode(1);
	root->left = new BstNode(2);
	root->right = new BstNode(3);
	root->left->left = new BstNode(4);
	root->left->right = new BstNode(5);

	//pre:  1,2,4,5,3
	//in:   4,2,5,1,3
	//post: 4,5,2,3,1

	//level:1,2,3,4,5

	return root;
}

void BstNode::PreOrderPrint(BstNode* node)
{
	if (NULL == node)
	{
		return;
	}

	cout << node->value << endl;
	BstNode::PreOrderPrint(node->left);
	BstNode::PreOrderPrint(node->right);
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

void BstNode::PostOrderPrint(BstNode* node)
{
	if (NULL == node)
	{
		return;
	}

	BstNode::PostOrderPrint(node->left);
	BstNode::PostOrderPrint(node->right);
	cout << node->value << endl;
}

void BstNode::LevelOrderPrintFlat(BstNode* node)
{


}

void BstNode::LevelOrderPrintLines(BstNode* node)
{}

