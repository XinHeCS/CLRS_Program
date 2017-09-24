//
// CLRS
// Exercise: 22.1.5
//		Generate a square graph
//
#include "ListGraph.h"

using namespace std;

void e22_1_5()
{
	ListGraph graph(VertexArray{
		{ 1 ,3 },{ 4 },{ 5, 4 },{ 1 },{ 3 },{ 5 }
	});
	ListGraph squareGraph(graph.getSquareGraph());

	graph.display();
	squareGraph.display();
}