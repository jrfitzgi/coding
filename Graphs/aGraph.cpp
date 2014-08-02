#include "aGraph.h"
#include <queue>
#include <iostream>

using namespace std;

aGraph::aGraph(int numVertices)
{
	aGraph::length = numVertices;
	//aGraph::vertices = new Vertex*[numVertices];
}

Vertex* aGraph::AddVertex(int listIndex, int vertexValue)
{
	Vertex* vertex = new Vertex(vertexValue);
	vertices[listIndex] = vertex;

	return vertex;
}

void aGraph::DFS()
{
	//visited = new Vertex*[aGraph::length];
	for (int i=0; i<aGraph::length; i++)
	{
		visited[i] = NULL;
	}

	// Get a start node
	Vertex* v = this->vertices[0];
	this->DFSRecursive(v);
}

void aGraph::DFSRecursive(Vertex* v)
{
	// Mark v as visited
	this->AddToVisited(v);
	cout << "Value: " << v->value << endl;

	Edge* edge = v->nextEdge;
	while (edge != NULL) // go through each edge in the list
	{
		if (IsVisited(edge->to) == false)
		{
			cout << "  Traversing edge " << v->value << "->" << edge->to->value << endl;
			DFSRecursive(edge->to);
		}

		edge = edge->next;
	}
}


void aGraph::BFS()
{
	//visited = new Vertex*[aGraph::length];
	for (int i=0; i<aGraph::length; i++)
	{
		visited[i] = NULL;
	}

	queue<Vertex*> q = queue<Vertex*>();
	q.push(this->vertices[0]);
	this->AddToVisited(vertices[0]);

	while(q.empty() == false)
	{
		Vertex* v = q.front();
		q.pop();
		cout << "Value: " <<  v->value << endl;

		Edge* e = v->nextEdge;
		while (e != NULL)
		{
			if (this->IsVisited(e->to))
			{
				// do nothing
			}
			else
			{
				q.push(e->to);
				this->AddToVisited(e->to);
			}

			e = e->next;
		}
	}

}

bool aGraph::IsVisited(Vertex* v)
{
	for (int i=0; i<aGraph::length; i++)
	{
		if (visited[i] == v)
		{
			return true;
		}
	}

	return false;
}

void aGraph::AddToVisited(Vertex* v)
{
	int i = 0;
	while (aGraph::visited[i] != NULL)
	{
		i++;
	}

aGraph:visited[i] = v;
}

void aGraph::PrintVertices()
{
	for (int i=0; i<this->length; i++)
	{
		cout << this->vertices[i] << " " << this->vertices[i]->value << endl;
	}
}

