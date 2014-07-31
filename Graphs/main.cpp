#include <iostream>
#include <queue>
#include "mGraph.h"

using namespace std;

void DFSRecursive(mGraph g, int startNode, int* visited)
{
	visited[startNode] = 1;

	int* adjacentVertices = g.getAdjacentVertices(startNode);
	for (int i=0; i<mGraph::numVertices; i++)
	{
		if (adjacentVertices[i] == 0)
		{
			// Not an adjacent vertex
			continue;
		}

		if (visited[i] != 0)
		{
			// Already visited
			continue;
		}

		// Print edge
		cout << startNode << "->" << i << endl;
		DFSRecursive(g, i, visited);
	}
}

void DFS(mGraph g, int startNode)
{
	int visited[mGraph::numVertices];
	for (int i=0; i<mGraph::numVertices; i++)
	{
		visited[i] = 0;
	}

	DFSRecursive(g, startNode, visited);
}


void BFS(mGraph g, int startNode)
{
	int visited[mGraph::numVertices];
	for (int i=0; i<mGraph::numVertices; i++)
	{
		visited[i] = 0;
	}

	queue<int> q = queue<int>();
	q.push(startNode);
	visited[startNode] = 1; 

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		// mark as visited


		// Print edge
		cout << "visit " << vertex << endl;

		int* adjacentVertices = g.getAdjacentVertices(vertex);
		for (int i=0; i<mGraph::numVertices; i++)
		{
			if (adjacentVertices[i] != 0 && visited[i] == 0)
			{
				//cout << " queue " << i << endl;
				q.push(i);
				visited[i] = 1; 
			}
		}

	}
}

int main(int argc, char** argv)
{
	mGraph g = mGraph();

	g.addEdge(0, 1);
	g.addEdge(1, 0);
	g.addEdge(0, 4);
	g.addEdge(4, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(4, 3);
	g.addEdge(1, 3);
	g.addEdge(3, 1);
	g.addEdge(1, 4);
	g.addEdge(4, 1);

	g.printGraph();

	int* adjacentEdges = g.getAdjacentVertices(2);
	g.printArray(mGraph::numVertices, adjacentEdges);


	//DFS(g, 0);
	BFS(g, 0);

	system("PAUSE");
}