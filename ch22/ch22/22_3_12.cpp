//
// CLRS
// Exercise: 22.2.7
//		Print the label of each edge
//
#include "ListGraph.h"

using namespace std;

void e22_3_12()
{
	//ListGraph graph(VertexArray{
	//	{0, 0, 0, 0},
	//	{0, 0, 0 ,0},
	//	{0, 0, 0, 0},
	//	{0, 0, 0, 0}
	//});
	ListGraph graph(VertexArray{
		{1}, {0}, {3} ,{2}
	});

	graph.connectedConponent();
}