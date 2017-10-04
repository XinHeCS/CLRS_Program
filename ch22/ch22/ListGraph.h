//
// Graph in adjacency list representation
// auther: XinHe
// version: 1.0.0
//
#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using VertexArray = std::vector<std::set<int>>;
using VisitedArray = std::vector<bool>;
using Vertex = int;
using Edge = std::pair<Vertex, Vertex>;

class ListGraph
{
public:
	// THe color of the vertex
	enum Color {
		WHITE,
		GRAY,
		BLACK
	};

	ListGraph() = default;		
	explicit ListGraph(VertexArray &v) :
		_vtx(v), _BFStree(_vtx.size()), _parent(_vtx.size()), _vst(_vtx.size(), false), 
		_dTime(_vtx.size(), 0), _fTime(_vtx.size(), 0), _color(_vtx.size(), WHITE),
		_conponent(_vtx.size(), 0), _SCC(_vtx.size(), 1) {};

	void display() { doDisplay(); }
	void display() const { doDisplay(); }
	int getVertexNumber() const { return _vtx.size(); }
	int outDegree(Vertex v) const { return _vtx[v].size(); }
	bool isAdjacent(Vertex v1, Vertex v2) const 
	{ 
		return _vtx[v1].find(v2) != _vtx[v1].end();
	}
	bool isAdjacentInTree(Vertex v1, Vertex v2) const 
	{ 
		return _BFStree[v1].find(v2) != _BFStree[v1].end() ||
			_BFStree[v2].find(v1) != _BFStree[v2].end(); 
	}

	bool isBipartite();
	void doublePath(Vertex v);
	int inDegree(Vertex v) const;
	void DFStravel();
	void DFSStack(void(*pfun)(Vertex v));
	void DFSEdge();
	void printDFEEdge(Vertex v);
	void BFStravel(Vertex v, void(*pfun)(Vertex v));	
	int connectedConponent();
	VertexArray transforn() const;
	VertexArray getSquareGraph() const;
	std::vector<Vertex> topologicalSort();
	VertexArray conponentGraph();	

private: 
	VertexArray _vtx;
	VertexArray _BFStree;
	std::vector<int> _parent;
	std::vector<int> _conponent;
	VisitedArray _vst;
	// Reco	rd time tick in DFS
	int _time = 0;
	std::vector<int> _dTime;
	std::vector<int> _fTime;
	std::vector<Color> _color;	
	std::vector<Vertex> _sort;
	std::vector<int> _SCC;

	bool isValidVertex(Vertex v) const
	{
		return v >= 0 && v < _vtx.size();
	}
	void doDisplay() const;
	void makePath(Vertex v);
	void DFSVisit(Vertex v, void(*pfun)(Vertex v));
	void visitDFS(Vertex v);
	void doSort(Vertex v);
	void findComponentByDFS(Vertex v, std::vector<Vertex> &cpnt, VertexArray &G);
};

#endif

