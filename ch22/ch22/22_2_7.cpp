//
// CLRS
// Exercise: 22.2.7
//		whelther a graph is a bipartite graph or not
//
#include "ListGraph.h"

using namespace std;

void e22_2_7()
{
	ListGraph graph(VertexArray{
		{1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}
	});

	cout << (graph.isBipartite() ? "This graph is a bipartite" :
									"This graph is not a bipartite graph")
		<< endl;
}