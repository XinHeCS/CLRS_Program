//
// CLRS 
// Exercise: 22.1.1
//		Calculate the indegrees and outdegrees of a vertex
// 
#include "ListGraph.h"

using namespace std;

void e22_1_1()
{
	ListGraph graph(VertexArray{
		{1 ,3}, {4}, {5, 4}, {1}, {3}, {5}
	});

	//cout << graph.inDegree(5) << ' ';
	cout << graph.inDegree(2) << ' ';
	cout << graph.outDegree(2) << endl;
}