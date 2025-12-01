#include <iostream>
#include "graph.h"


void Graph::add_edge(int nodeOne, int nodeTwo, int weight) {
	adjList[nodeOne].push_back({ nodeTwo, weight });
	//nodes.insert(nodeOne);
	//nodes.insert(nodeTwo);
}
void Graph::print() {

	for (auto l : adjList) {
		std::cout << l.first;
		for (auto e : l.second) {
			std::cout << " | -> " << e.destinationNode << " (" << e.weight << ")";
		}
		std::cout << '\n';
	}
};