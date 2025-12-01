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
}

void Graph::read_form_file(std::string fileName) {
	if (std::ifstream inputFile{ fileName }) {
		std::string s = "";
		std::vector<std::string> edgesText;
		int startingEdge = 0;
		int destinationEdge = 0;
		int weight = 0;
		int minusPos = 0;
		int greaterPos = 0;
		int leftBracketPos = 0;
		int rightBracketPos = 0;

		while (getline(inputFile, s, ',')) {
			minusPos = s.find('-');
			greaterPos = s.find('>');
			leftBracketPos = s.find('(');
			rightBracketPos = s.find(')');
			if (minusPos >= s.size() || greaterPos >= s.size() || leftBracketPos >= s.size() || rightBracketPos >= s.size()) {
				throw std::invalid_argument("");
			}
			startingEdge = std::stoi(s.substr(0, minusPos));
			destinationEdge = std::stoi(s.substr(greaterPos + 1, leftBracketPos - greaterPos));
			weight = std::stoi(s.substr(leftBracketPos + 1, rightBracketPos - leftBracketPos));
			
			add_edge(startingEdge, destinationEdge, weight);
		}
		inputFile.close();
	}
	else {
		throw std::system_error(errno, std::generic_category(), fileName);
	}
}