#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

using namespace std;

class Vertex
{
public:
	Vertex(int value);
	void AddAjacentVertex(Vertex* adjacentVertex);
	int value;
	Edge* nextEdge;
};

#endif