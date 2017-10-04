//
// CLRS
// Problem: 22.4
//		Min label
//
#include "ListGraph.h"

using namespace std;
using Graph = vector<set<int>>;

Graph transform(Graph &G)
{
	Graph G_T(G.size());

	for (int u = 0; u < G.size(); ++u) {
		for (auto &v : G[u]) {
			G_T[v].insert(u);
		}
	}

	return G_T;
}

void transitMin(Graph &G, int u, vector<int> &minValue, int label)
{
	minValue[u] = label;
	for (auto &v : G[u]) {
		if (minValue[v] == -1) {
			transitMin(G, v, minValue, label);
		}
	}
}

vector<int> min(Graph &G)
{
	Graph G_T = transform(G);
	vector<int> minValue(G.size(), -1);
	for (int u = 0; u < G.size(); ++u) {
		if (minValue[u] == -1) {
			transitMin(G_T, u, minValue, u);
		}
	}

	return minValue;
}

void p22_4()
{
	Graph G{
		{1}, {}, {0}, {1}, {4}, {2, 3, 6}, {3, 4}
	};

	auto result = min(G);

	for (size_t i = 0; i < result.size(); ++i) {
		cout << i << ": " << result[i] << endl;
	}
}
