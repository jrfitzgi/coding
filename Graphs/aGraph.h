#ifndef AGRAPH_H
#define AGRAPH_H

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class aGraph
{
public:
	aGraph(int numVertices);
	Vertex* AddVertex(int listIndex, int vertexValue);

	Vertex* vertices[5];
	int length;

	void DFS();
	void DFSRecursive(Vertex* v);
	void BFS();
	void PrintVertices();
private:
	Vertex* visited[5];
	bool IsVisited(Vertex* v);
	void AddToVisited(Vertex* v);

};
#endif