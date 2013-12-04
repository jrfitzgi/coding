#include <iostream>
#include "BtNode.h"
#include <queue>

using namespace std;

BtNode::BtNode(int value)
{
	this->value = value;
}

BtNode::~BtNode()
{
	delete this->left;
	delete this->right;
}

BtNode* BtNode::ConstructBt()
{
	BtNode* root = new BtNode(1);
	root->left = new BtNode(2);
	root->right = new BtNode(3);
	root->left->left = new BtNode(4);
	root->left->right = new BtNode(5);

	//pre:  1,2,4,5,3
	//in:   4,2,5,1,3
	//post: 4,5,2,3,1

	//level:1,2,3,4,5

	return root;
}

void BtNode::PreOrderPrint(BtNode* node)
{
	if (NULL == node)
	{
		return;
	}

	cout << node->value << endl;
	BtNode::PreOrderPrint(node->left);
	BtNode::PreOrderPrint(node->right);
}

void BtNode::InOrderPrint(BtNode* node)
{
	if (NULL == node)
	{
		return;
	}

	InOrderPrint(node->left);
	cout << node->value << endl;
	InOrderPrint(node->right);
}

void BtNode::PostOrderPrint(BtNode* node)
{
	if (NULL == node)
	{
		return;
	}

	BtNode::PostOrderPrint(node->left);
	BtNode::PostOrderPrint(node->right);
	cout << node->value << endl;
}

void BtNode::LevelOrderPrintLines_TwoQueues(BtNode* node)
{
	queue<BtNode*> q0 = queue<BtNode*>(); 
	queue<BtNode*> q1 = queue<BtNode*>();

	if (NULL == node) {return;}

	// Do some initial steps
	q0.push(node);
	queue<BtNode*>* activeQ = &q0;
	queue<BtNode*>* nonActiveQ = &q1;

	while (true)
	{
		while (activeQ->empty() == false)
		{
			BtNode* poppedNode = activeQ->front();
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
		queue<BtNode*>* tempQ = activeQ;
		activeQ = nonActiveQ;
		nonActiveQ = tempQ;
	}
}

void BtNode::LevelOrderPrintLines_TwoCounters(BtNode* node)
{
	if (NULL == node) {return;}

	queue<BtNode*> q = queue<BtNode*>();

	// Initial setup
	q.push(node);
	int nodesOnCurrentLevel = 1;
	int nodesOnNextLevel = 0;

	while (!q.empty())
	{
		for (int i=nodesOnCurrentLevel; i>0; i--)
		{
			BtNode* poppedNode = q.front();
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

void BtNode::LevelOrderPrintLines_Markers(BtNode* node)
{
	if (NULL == node) {return;}

	queue<BtNode*> q = queue<BtNode*>();

	// Initial setup
	q.push(node);
	q.push(NULL);

	while (!q.empty())
	{
		BtNode* poppedNode = q.front();
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

void BtNode::LevelOrderPrintFlat(BtNode* node)
{
	if (NULL == node) {return;}

	queue<BtNode*> q = queue<BtNode*>();

	// Initial setup
	q.push(node);

	while (q.empty() == false)
	{
		BtNode* poppedNode = q.front();
		cout << poppedNode->value << " ";
		q.pop();

		if (NULL != poppedNode->left) {q.push(poppedNode->left);}
		if (NULL != poppedNode->right) {q.push(poppedNode->right);}
	}

	cout << endl;
}
