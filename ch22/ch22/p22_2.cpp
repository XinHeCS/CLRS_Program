//
// CLRS
// Problem: 22.2
//		Cut node, bridge, and BCC
//
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <utility>

using namespace std;
using Vertex = int;

#define NULLNODE -1

enum Color {
	WHITE,
	GRAY,
	BLACK
};

struct Edge
{
	Vertex _endNode;	
	int BCC;

	Edge(int v) : _endNode(v), BCC(-1) {}
};

using Graph = vector<vector<Edge>>;

// g must be a UCG(undirect connected graph)
Graph g{
	{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3, 5, 6}, {4, 7}, {4, 7}, {5, 6, 8}, {7}
};

// if isCut[v] is true, then node v is a cut node
vector<bool> isCut(g.size(), false);
// record the color of node v
vector<Color> visited(g.size(), WHITE);
// Record the low value of each vertex
vector<int> low(g.size(), 0);
// timestamp in DFS
int time = 0;
vector<int> dTime(g.size(), 0);
// Record current BCC
int BCCCount = 0;

vector<pair<Vertex, Edge>> bridge;
stack<pair<Vertex, Edge*>> S;

// return the low value of u
int BCC(Vertex u, Vertex father)
{	
	int childCount = 0;
	++time;
	dTime[u] = time;
	low[u] = time;
	visited[u] = GRAY;
	for (auto &edge : g[u]) {		
		auto v = edge._endNode;
		if (visited[v] == WHITE) {
			S.push({ u, &edge });
			++childCount;
			low[v] = BCC(v, u);
			low[u] = low[v] < low[u] ? low[v] : low[u];
			if (dTime[u] <= low[v]) {
				isCut[u] = true;	
				// Bridge dosen't belong to any BCC
				if (dTime[u] < low[v]) {
					bridge.push_back(make_pair(u, edge));
					S.pop();
				}
				// There is some trick here
				// Since the low of root is the minimum in the graph, 
				// it will always be regarded as a cut node
				// Then the else-switch will act correctly although 
				// there might be no cut when we trace back in the last 
				// BCC
				else {
					++BCCCount;
					do
					{
						auto e = S.top();
						S.pop();
						e.second->BCC = BCCCount;
						if (e.first == u&& e.second->_endNode == v) {
							break;
						}
					} while (true);
				}
			}
		}
		else if (v != father && visited[v] == GRAY) {
			S.push({ u, &edge });
			low[u] = low[u] < dTime[v] ? low[u] : dTime[v];
		}
	}

	visited[u] = BLACK;
	// We should correct the result if the root is not a cut node
	if (father == NULLNODE && childCount < 2) {
		isCut[u] = false;
	}

	return low[u];
}

void p22_2()
{
	BCC(0, NULLNODE);

	// print cut nodes
	cout << "Cut node: ";
	for (int v = 0; v < isCut.size(); ++v) {
		if (isCut[v]) {
			cout << v << ' ';
		}
	}
	cout << endl;

	// print bridge
	cout << "Bridge: ";
	for (auto &e : bridge) {
		cout << "(" << e.first << ", " << e.second._endNode << ")" << ' ';
	}
	cout << endl;
}

