#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int value=0)
{
	Vertex::value = value;
}

void Vertex::AddAjacentVertex(Vertex* adjacentVertex)
{
	Edge* edge = new Edge(this, adjacentVertex, 1);

	if (this->nextEdge == NULL)
	{
		this->nextEdge = edge;
		return;
	}

	Edge* lastEdge = this->nextEdge;
	while (lastEdge->next != NULL)
	{
		lastEdge = lastEdge->next;
	}

	lastEdge->next = edge;
}