//
// CLRS
// Exercise: 22.2.7
//		Print the label of each edge
//
#include "ListGraph.h"

using namespace std;

void e22_3_10()
{
	ListGraph graph(VertexArray{
		{ 1, 3 },{ 4 },{ 4, 5 },{ 1 },{ 3 },{ 5 }
	});

	graph.DFSEdge();
}