#ifndef EDGE_H
#define EDGE_H

class Vertex;

class Edge
{
public:
	Edge(Vertex* from, Vertex* to, int weight);
	Edge* next;

	int weight;
	Vertex* from;
	Vertex* to;


};
#endif