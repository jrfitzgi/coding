#include <iostream>
#include "mGraph.h"

using namespace std;

mGraph::mGraph()
{
	for (int i=0; i<numVertices; i++)
	{
		for (int j=0; j<numVertices; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void mGraph::addEdge(int from, int to)
{
	matrix[from][to] = 1;
}

void mGraph::printGraph()
{
	cout << "Printing Matrix" << endl;
	for (int i=0; i<numVertices; i++)
	{
		for (int j=0; j<numVertices; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
	cout << endl;
}

int* mGraph::getAdjacentVertices(int v)
{
	return matrix[v];
}

void mGraph::printArray(int length, int* array)
{
	cout << "Printing Array:" << endl;
	for (int i=0; i<length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	cout << endl;
}