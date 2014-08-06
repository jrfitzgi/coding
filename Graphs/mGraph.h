#ifndef MGRAPH_H
#define MGRAPH_H

using namespace std;

class mGraph
{

public:
	static const int numVertices = 5;

	mGraph();
	void addEdge(int from, int to);
	void printGraph();
	int* getAdjacentVertices(int v);
	void printArray(int length, int* array);

private:

	int matrix[numVertices][numVertices];
};

#endif