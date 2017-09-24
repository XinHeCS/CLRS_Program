//
// CLRS
// Exercise: 22.1.3
//		Transform a adjacency list
//
#include "ListGraph.h"

using namespace std;

void e22_1_3()
{
	ListGraph graph(VertexArray{
		{ 1 ,3 },{ 4 },{ 5, 4 },{ 1 },{ 3 },{ 5 }
	});
	ListGraph graph_T(graph.transforn());

	cout << (graph.isAdjacent(0, 1) ? "ture" : "false") << endl;
	cout << (graph_T.isAdjacent(0, 1) ? "true" : "false") << endl;

	graph.display();
	graph_T.display();
}