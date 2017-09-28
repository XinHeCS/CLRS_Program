//
// CLRS
// Exercise: 22.2.7
//		DFS loop version
//
#include "ListGraph.h"

using namespace std;

void e22_3_7()
{
	ListGraph graph(VertexArray{
		{1, 3}, {4}, {4, 5}, {1}, {3}, {5}
	});

	graph.DFStravel();
	cout << endl;
	graph.DFSStack(nullptr);
}