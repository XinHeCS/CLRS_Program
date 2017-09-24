//
// CLRS
// Exercise: 22.2.9
//		Build a path in which every edge visited twice
//
#include "ListGraph.h"

using namespace std;

void e22_2_9()
{
	ListGraph graph(VertexArray{
		{ 1, 4 },{ 0, 2 },{ 1, 3 },{ 2, 4 },{ 0, 3 }
	});

	graph.doublePath(0);
}