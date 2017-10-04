//
// CLRS
// Exercise: 22.4.5
//		Create the conponent graph of a graph
//
#include "ListGraph.h"

void e22_5_4()
{
	ListGraph graph(VertexArray{
		{ 1 },{ 2, 4, 5 },{ 3, 6 },{ 2, 7 },{ 0, 5 },{ 6 },{ 5, 7 },{ 7 }
	});

	graph.connectedConponent();

	ListGraph cpntGraph(graph.conponentGraph());

	cpntGraph.display();
}

// { 1 },{ 2, 4, 5 },{ 3, 6 },{ 2, 7 },{ 0, 5 },{ 6 },{ 5, 7 },{ 7 }
// { 1, 2 },{ 5 },{ 5 },{ 2, 4 },{ 5 },{}