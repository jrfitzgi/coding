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

void BstNode::LevelOrderPrintLines_TwoQueues(BstNode* node)
{
	queue<BstNode*> q0 = queue<BstNode*>(); 
	queue<BstNode*> q1 = queue<BstNode*>();

	if (NULL == node) {return;}

	// Do some initial steps
	q0.push(node);
	queue<BstNode*>* activeQ = &q0;
	queue<BstNode*>* nonActiveQ = &q1;

	while (true)
	{
		while (activeQ->empty() == false)
		{
			BstNode* poppedNode = activeQ->front();
			cout << poppedNode->value << " ";
			activeQ->pop();

			if (NULL != poppedNode->left) {nonActiveQ->push(poppedNode->left);}
			if (NULL != poppedNode->right) {nonActiveQ->push(poppedNode->right);}
		}

		// Once we get here, either we are done or we switch queues. Either way, print a new line.
		cout << endl;

		// No more nodes so we quit
		if (nonActiveQ->empty() == true) {return;}

		// There are more nodes. Swap active and nonActive and continue.
		queue<BstNode*>* tempQ = activeQ;
		activeQ = nonActiveQ;
		nonActiveQ = tempQ;
	}
}

void BstNode::LevelOrderPrintLines_TwoCounters(BstNode* node)
{
	if (NULL == node) {return;}

	queue<BstNode*> q = queue<BstNode*>();

	// Initial setup
	q.push(node);
	int nodesOnCurrentLevel = 1;
	int nodesOnNextLevel = 0;

	while (!q.empty())
	{
		for (int i=nodesOnCurrentLevel; i>0; i--)
		{
			BstNode* poppedNode = q.front();
			q.pop();
			cout << poppedNode->value << " ";

			if (NULL != poppedNode->left)
			{
				q.push(poppedNode->left);
				nodesOnNextLevel++;
			}

			if (NULL != poppedNode->right)
			{
				q.push(poppedNode->right);
				nodesOnNextLevel++;
			}
		}

		cout << endl;

		nodesOnCurrentLevel = nodesOnNextLevel;
		nodesOnNextLevel = 0;
	}
}

void BstNode::LevelOrderPrintLines_Markers(BstNode* node)
{
	if (NULL == node) {return;}

	queue<BstNode*> q = queue<BstNode*>();

	// Initial setup
	q.push(node);
	q.push(NULL);

	while (!q.empty())
	{
		BstNode* poppedNode = q.front();
		q.pop();

		if (NULL == poppedNode)
		{
			cout << endl;

			// If we popped off the last marker, then don't push another one on
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << poppedNode->value << " ";
			if (NULL != poppedNode->left) {q.push(poppedNode->left);}
			if (NULL != poppedNode->right) {q.push(poppedNode->right);}
		}
	}

}

void BstNode::LevelOrderPrintFlat(BstNode* node)
{
	if (NULL == node) {return;}

	queue<BstNode*> q = queue<BstNode*>();

	// Initial setup
	q.push(node);

	while (q.empty() == false)
	{
		BstNode* poppedNode = q.front();
		cout << poppedNode->value << " ";
		q.pop();

		if (NULL != poppedNode->left) {q.push(poppedNode->left);}
		if (NULL != poppedNode->right) {q.push(poppedNode->right);}
	}

	cout << endl;
}
