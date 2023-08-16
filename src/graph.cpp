#include "graph.h"

Graph::Graph(std::string* allowed)
{
	this->entry = nullptr;
	this->allowed = allowed;
	this->nodes = new std::vector<Node*>();
}

bool Graph::ConnectNodes(Node* to, Node* from, char c)
{
	if (allowed->find(c) == std::string::npos) return false;
	return (from->AddConnection(to, c));
}

bool Graph::AddNode(Node* node)
{
	if (std::find(nodes->begin(), nodes->end(), node) != nodes->end()) return false;
	nodes->push_back(node);
	return true;
}

void Graph::SetEntry(Node* node)
{
	if (entry == node) return;
	else if (entry != nullptr) entry->SetIsEntry(false);
	entry = node;
}

Node* Graph::GetEntry()
{
	return entry;
}
