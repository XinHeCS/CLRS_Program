//
// CLRS
// Exercise: 22.4.5
//		Jusdge whether a graph is single connected
//
#include "ListGraph.h"

using namespace std;

void e22_5_7()
{
	ListGraph graph(VertexArray{
		{ 1, 2 },{ 5 },{ 5 },{ 2, 4 },{ 5 },{}
	});

	ListGraph cpntGraph(graph.conponentGraph());

	graph.display();
	cpntGraph.display();

	auto sortResult = cpntGraph.topologicalSort();
	for (Vertex v = 0; v < sortResult.size() - 1; ++v) {
		if (!cpntGraph.isAdjacent(sortResult[v], sortResult[v + 1])) {
			cout << "Graph is not single connected!!" << endl;
			return ;
		}
	}

	cout << "Graph is single connected!!" << endl;
	return ;
}

// { 1 },{ 2, 4, 5 },{ 3, 6 },{ 2, 7 },{ 0, 5 },{ 6 },{ 5, 7 },{ 7 }
// { 1, 2 },{ 5 },{ 5 },{ 2, 4 },{ 5 },{}