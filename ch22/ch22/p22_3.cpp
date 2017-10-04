//
// CLRS
// Problem: 22.3
//		Euler Cycle
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Edge{
	int end_vertex;
	int visited;
	Edge(int end) : end_vertex(end), visited(0) {}
};

vector<Edge> vertex[] = {
	{2}, {0, 2}, {1, 3}, {1}
};

stack<int> EulerCycle;

static void euler(int x) {
	int i;
	for (i = vertex[x].size() - 1; i >= 0; --i) {
		if (!vertex[x][i].visited) {
			vertex[x][i].visited = 1;
			euler(vertex[x][i].end_vertex);
		}
	}

	EulerCycle.push(x);
}

void p22_3() {
	euler(0);

	while (!EulerCycle.empty()) {
		cout << EulerCycle.top() << ' ';
		EulerCycle.pop();
	}

	cout << endl;
}