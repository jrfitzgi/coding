#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge(Vertex* from, Vertex* to, int weight=1)
{
	Edge::from = from;
	Edge::to = to;
	Edge::weight = weight;
}