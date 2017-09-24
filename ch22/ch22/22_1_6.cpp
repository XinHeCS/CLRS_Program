//
// CLRS
// Exercise: 22.1.6
//		Find a sink vertice in a graph
//		Note: we don't use the adjacency list to represent the graph
//		since the complexity of linear time are required here.
//		So, we will use adjacency matrix instead of list.
//
#include <vector>
#include <iostream>
#include <utility>

using namespace std;
using Matrix = vector<vector<int>>;
using Vertex = int;
using Edge = pair<int, int>;

void e22_1_6()
{
	Matrix g{
		{0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1},
		{0, 1, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};

	Vertex i = 0, j = 0;
	while (i < g.size() && j < g.size()) {
		if (g[i][j] == 1) {
			++i;
		}
		else if (g[i][j] == 0) {
			++j;
		}
	}

	// Check for the sink vertex
	// out degree equals to zero
	for (Vertex v = 0; v < g.size(); ++v) {
		if (g[i][v] != 0) {
			cout << "There is no such sink vertice" << endl;
			return;						   
		}								   
	}									   
	// and ub degree are |V| - 1		   
	for (Vertex v = 0; v < g.size(); ++v) {
		if (i != v && g[v][i] != 1) {
			cout << "There is no such sink vertice" << endl;
			return;
		}
	}

	cout << "Sink vertex is " << i << endl;
}
