//
// CLRS
// Exercise: 22.4.2
//		Vount the number of paths between v1 and v2
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

// we use DFS here to find a 
// topological sort of graph
/**
 * @param [list<Vertex>] sort
 *		a list to stroe the result of sort
 * @param [Vertex] v
 *		Run DFS algorithm from this vertice
 * @param [vector<bool>] visited
 *		an array to record if vertice v has been visited
*/
static void _DFS(Graph &graph, Vertex v, list<Vertex> &sort, vector<bool> &visited)
{
	/*static int timeTick = 0;*/
	visited[v] = true;

	for (auto &vtx : graph[v]) {
		if (!visited[vtx]) {
			_DFS(graph, vtx, sort, visited);
		}
	}

	sort.push_front(v);
}

vector<Vertex> topologicalSort(Graph &graph)
{
	vector<Vertex> ret;
	list<Vertex> result;
	vector<bool> visited(graph.size(), false);

	for (Vertex v = 0; v < graph.size(); ++v) {
		if (!visited[v]) {
			_DFS(graph, v, result, visited);
		}
	}

	for (auto iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	ret.assign(result.begin(), result.end());

	return ret;
}

// Return the number of paths from v1 to v2
int countPaths(Graph &graph, vector<int> &paths, Vertex v1, Vertex v2)
{
	if (v1 == v2) {
		return 1;
	}
	else if (paths[v1] != 0) {
		return paths[v1];
	}
	else {
		for (auto vtx : graph[v1]) {
			paths[v1] += countPaths(graph, paths, vtx, v2);
		}

		return paths[v1];
	}
}

// DAG only
int pathCount(Graph &graph, Vertex v1, Vertex v2)
{
	// Stroe the result of topological sort
	//vector<Vertex> tSort = topologicalSort(graph);
	vector<int> paths(graph.size(), 0);

	return countPaths(graph, paths, v1, v2);
}

void e22_4_2()
{
	//Graph graph{
	//	{1, 2}, {2, 4}, {3, 5}, {4, 5}, {}, {}
	//};
	Graph graph{
		{ 1, 2 },{ 5 },{ 5 },{ 2, 4 },{ 5 },{}
	};

	cout << pathCount(graph, 0, 5) << endl;

	auto sort = topologicalSort(graph);

	for (auto &item : sort) {
		cout << item << ' ';
	}
	cout << endl;
}
