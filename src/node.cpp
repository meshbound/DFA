#include "Node.h"
#include <string>

Node::Node()
{
	this->isEnd = false;
	this->isEntry = false;
	this->outgoing = new std::map<char, Node*>();
}

Node* Node::GetConnection(char c)
{
	std::map<char, Node*>::iterator it = outgoing->find(c);
	return it != outgoing->end() ? it->second : nullptr;
}

bool Node::AddConnection(Node* node, char c)
{
    std::map<char, Node*>::iterator it = outgoing->find(c);
	if (it != outgoing->end())
		return (it->second == node);
	outgoing->insert(std::make_pair(c, node));
	return true;
}

bool Node::RemoveConnection(char c)
{
	return outgoing->erase(c) > 0;
}

size_t Node::RemoveAllConnections()
{
	size_t removed = outgoing->size();
	delete outgoing;
	outgoing = new std::map<char, Node*>();
	return removed;
}

bool Node::GetIsEnd()
{
	return isEnd;
}

bool Node::GetIsEntry()
{
	return isEntry;
}

void Node::SetIsEnd(bool isEnd)
{
	this->isEnd = isEnd;
}

void Node::SetIsEntry(bool isEntry)
{
	this->isEntry = isEntry;
}
