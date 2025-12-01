#pragma once
#include <map>
#include <vector>
#include <set>

struct edge {
	int destinationNode = 0;
	int weight = 0;
};

class Graph {
	std::map<int, std::vector<edge>> adjList;
	//std::set<int> nodes;
	public:
	void add_edge(int nodeOne, int nodeTwo, int weight);
	void print();
};
