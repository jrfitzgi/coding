#include <iostream>
//#include <algorithm>
#include <math.h>
#include <queue>
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

BstNode* BstNode::ConstructBalancedBst()
{
	BstNode* root = new BstNode(3);
	root->Insert(new BstNode(1));
	root->Insert(new BstNode(2));
	root->Insert(new BstNode(4));
	root->Insert(new BstNode(5));
	return root;
}

BstNode* BstNode::ConstructInvalidBst()
{
	BstNode* root = new BstNode(10);
	//root->left = new BstNode(10); // invalid
	root->Insert(new BstNode(10));
	root->Insert(new BstNode(5));
	root->Insert(new BstNode(2));
	root->Insert(new BstNode(8));
	root->Insert(new BstNode(15));
	root->Insert(new BstNode(12));
	root->Insert(new BstNode(18));

	// Invalid nodes
	//root->left->right->left = new BstNode(1);
	root->left->right->right = new BstNode(11);

	return root;
}

BstNode* BstNode::ConstructOneLevelImbalanceBst()
{
	BstNode* root = new BstNode(4);
	root->Insert(new BstNode(1));
	root->Insert(new BstNode(2));
	root->Insert(new BstNode(3));
	root->Insert(new BstNode(5));
	root->Insert(new BstNode(6));
	return root;
}

BstNode* BstNode::ConstructTwoLevelImbalanceBst()
{
	BstNode* root = new BstNode(4);
	root->Insert(new BstNode(1));
	root->Insert(new BstNode(2));
	root->Insert(new BstNode(3));
	root->Insert(new BstNode(5));
	return root;
}

bool BstNode::IsBst(BstNode* root, int min, int max)
{
	if (NULL == root)
	{
		return true;
	}

	if (root->value >= min && root->value < max)
	{
		// do nothing
	}
	else {
		cout << "Bst check failed at node " << root->value << endl;
		return false;
	}

	int rightMin = std::max(root->value, min);
	int leftMax = std::min(root->value, max);

	return BstNode::IsBst(root->left, min, leftMax) && BstNode::IsBst(root->right, rightMin, max);
}

bool BstNode::IsBalanced(BstNode* root)
{
	int depth = root->GetDepth();
	int nodeCount = root->GetNodeCount();

	// We want log(depth) in base 2. We use the formula
	// log(x) base A = log(x) / log(A) where both log(x) and log(A) have any base.
	// We only get the integer value so assign an int not double
	int expectedDepth = log(nodeCount) / log(2);

	return (depth <= expectedDepth);
}

int BstNode::GetDepth()
{
	if (NULL == this->left && NULL == this->right)
	{
		return 0;
	}
	else if (NULL == this->left)
	{
		return 1 + this->right->GetDepth();
	}
	else if (NULL == this->right)
	{
		return 1 + this->left->GetDepth();
	}
	else
	{
		return 1 + max(this->left->GetDepth(), this->right->GetDepth());
	}
}

int BstNode::GetNodeCount()
{
	int leftNodeCount = 0;
	if (NULL != this->left)
	{
		leftNodeCount = this->left->GetNodeCount();
	}

	int rightNodeCount = 0;
	if (NULL != this->right)
	{
		rightNodeCount = this->right->GetNodeCount();
	}

	return 1 + leftNodeCount + rightNodeCount;
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