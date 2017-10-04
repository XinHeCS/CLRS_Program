//
// CLRS
// Exercise: 22.4.3
//		Determine whether exists a cycle in
//		a UG(undirected graph)
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;
using Graph = vector<set<int>>;
using Vertex = int;
using Edge = pair<Vertex, Vertex>;

// We use dfs to count the number of edges
// if the the edgeCount exceeds graph.size() - 1
// then we stop the algorithm abd clains that there is cycle
// in the graph
bool _findCycle(Graph &graph, Vertex v, vector<Vertex> &visited, int &edgeCount, vector<Vertex> &parent)
{
	visited[v] = true;

	for (auto &vertice : graph[v]) {
		if (parent[v] != vertice) {
			++edgeCount;
		}
		if (!visited[vertice]) {
			parent[vertice] = v;
			if (edgeCount > graph.size() - 1) {
				return true;
			}
			if (!_findCycle(graph, vertice, visited, edgeCount, parent)) {
				continue;
			}
			else {
				return true;
			}
		}
	}

	return false;
}

bool containsCycle(Graph &graph)
{
	int edgeCount = 0;
	vector<Vertex> visited(graph.size(), false);
	vector<Vertex> parent(graph.size(), -1);
	bool hasCycle = false;

	for (Vertex v = 0; v < graph.size(); ++v) {
		if (!visited[v]) {
			hasCycle = _findCycle(graph, v, visited, edgeCount, parent);
			if (hasCycle) {
				return true;
			}
			else {
				continue;
			}
		}
	}

	return false;
}

void e22_4_3()
{
	//Graph graph{
	//	{1}, {0, 2, 3}, {1, 4, 5}, {1}, {2, 5}, {2, 4}
	//};
	Graph graph{
		{1, 2}, {0}, {0}
	};

	cout << (containsCycle(graph) ? "Graph contains cycle" :
		"Graph doesn't contain cycle") << endl;
}