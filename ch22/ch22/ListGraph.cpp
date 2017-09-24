#include "ListGraph.h"
#include <deque>

using namespace std;

static inline void visitVertex(Vertex v)
{
	cout << v << ' ';
}

ListGraph::ListGraph(std::size_t n, std::istream & is) : 
	_vtx(n), _BFStree(n), _parent(n), _vst(n, false)
{
	Edge tempEdge;
	Vertex v1, v2;
	while (is >> v1 >> v2) {
		if (isValidVertex(v1) && isValidVertex(v2)) {
			auto ret = _vtx[v1].insert(v2);
		}
		else {
			cerr << "Invalid input" << endl;
			_vtx.clear();
			_vst.clear();
			break;
		}
	}
}

void ListGraph::doublePath(Vertex v)
{
	BFStravel(v, nullptr);
	makePath(v);
	cout << endl;
}

bool ListGraph::isBipartite()
{
	// -1 means this vertice has not been colored yet
	// 0 means black and
	// 1 means white
	vector<int> color(_vtx.size(), -1);
	deque<int> queue;

	for (auto &v : _vst) {
		v = false;
	}

	_vst[0] = true;
	color[0] = 0;
	queue.push_back(0);

	while (!queue.empty()) {
		auto currV = queue.front();
		queue.pop_front();

		for (auto &v : _vtx[currV]) {
			if (color[v] == -1) {
				color[v] = color[currV] ? 0 : 1;
				queue.push_back(v);
				_vst[v] = true;
			}
			else if (color[v] == color[currV]) {
				return false;
			}
		}
	}

	return true;
}

int ListGraph::inDegree(Vertex v) const
{
	int inDegreeCount = 0;

	if (!isValidVertex(v)) {
		return inDegreeCount;
	}

	for (auto &edgeList : _vtx) {
		inDegreeCount += edgeList.count(v);
	}

	return inDegreeCount;
}

VertexArray ListGraph::transforn() const
{
	VertexArray _vtx_T(_vtx.size());

	for (Vertex v1 = 0; v1 < _vtx.size(); ++v1) {
		for (auto &v2 : _vtx[v1]) {
			_vtx_T[v2].insert(v1);
		}
	}

	return _vtx_T;
}

VertexArray ListGraph::getSquareGraph() const
{
	VertexArray vArray(_vtx.size());

	for (Vertex v = 0; v < _vtx.size(); ++v) {
		for (auto &v1 : _vtx[v]) {
			for (auto &v2 : _vtx[v1]) {
				vArray[v].insert(v2);
			}
		}
	}

	return vArray;
}

void ListGraph::doDisplay() const
{
	cout << "Graph:" << endl;
	for (Vertex v = 0; v < _vtx.size(); ++v) {
		cout << v << " : ";
		for (auto &v2 : _vtx[v]) {
			cout << v2 << " -> ";
		}
		cout << "null" << endl;
	}

	cout << endl;
}

void ListGraph::makePath(Vertex v)
{
	cout << v << ' ';
	for (auto &vertice : _vtx[v]) {
		if (!isAdjacentInTree(v, vertice) && v <= vertice) {
			cout << vertice << ' ' << v << ' ';
		}
	}

	for (auto &vertice : _vtx[v]) {
		if (isAdjacentInTree(v, vertice) && _parent[v] != vertice) {
			makePath(vertice);
			cout << v << ' ';
		}
	}
}

void ListGraph::BFStravel(Vertex v, void(*pfun)(Vertex v))
{
	deque<int> vertexQueue;
	
	for (Vertex i = 0; i < _vtx.size(); ++i) {
		_vst[i] = false;
		_parent[v] = -1;
	}

	_vst[v] = true;
	vertexQueue.push_back(v);

	while (!vertexQueue.empty()) {
		auto currV = vertexQueue.front();
		vertexQueue.pop_front();

		for (auto &vertice : _vtx[currV]) {
			if (!_vst[vertice]) {
				vertexQueue.push_back(vertice);
				_parent[vertice] = currV;
				_vst[vertice] = true;
				// Add edge into BFS tree
				_BFStree[currV].insert(vertice);
			}
		}
		if (pfun) {
			pfun(currV);
		}
	}
	cout << endl;
}
