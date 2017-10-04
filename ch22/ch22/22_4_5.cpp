//
// CLRS
// Exercise: 22.4.5
//		Another version of topological sort
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include "ListGraph.h"

using namespace std;
using Graph = vector<set<int>>;
using Vertex = int;
using Edge = pair<Vertex, Vertex>;

static Vertex findZeroInDegreeNode(vector<int> &inDegree)
{
	for (Vertex v = 0; v < inDegree.size(); ++v) {
		if (inDegree[v] == 0) {
			return v;
		}
	}

	return -1;
}

static void deleteNode(Graph &graph, vector<int> &inDegree, Vertex v)
{
	inDegree[v] = -1;
	for (auto &vtx : graph[v]) {
		--inDegree[vtx];
	}
}

static vector<Vertex> topologicalSort(Graph &graph)
{
	// Record the in degrees
	vector<int> inDegree(graph.size(), 0);
	vector<Vertex> sort;

	for (Vertex v = 0; v < graph.size(); ++v) {
		for (auto &vtx : graph[v]) {
			++inDegree[vtx];
		}
	}

	auto next = findZeroInDegreeNode(inDegree);
	while (next != -1) {
		sort.push_back(next);
		deleteNode(graph, inDegree, next);
		next = findZeroInDegreeNode(inDegree);
	}

	return sort;
}

void e22_4_5()
{
	Graph graph{
		{ 1, 2 },{ 5 },{ 5 },{ 2, 4 },{5},{}
	};

	auto sort = topologicalSort(graph);

	for (auto &item : sort) {
		cout << item << ' ';
	}
	cout << endl;
}