#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <string>
#include <vector>

class Graph
{
public:
	Graph(std::string* allowed);
	bool ConnectNodes(Node* to, Node* from, char c);
	bool AddNode(Node* node);
	void SetEntry(Node* node);
	Node* GetEntry();
private:
	Node* entry;
	std::string* allowed;
	std::vector<Node*>* nodes;
};

#endif