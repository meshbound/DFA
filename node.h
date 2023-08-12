#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>

class Node {
public:
	Node ();
	Node* GetConnection(char c);
	bool AddConnection(Node* node, char c);
	bool RemoveConnection(char c);
	size_t RemoveAllConnections();
	bool GetIsEnd();
	bool GetIsEntry();
	void SetIsEnd(bool isEnd);
	void SetIsEntry(bool isEntry);
private:
	bool isEnd;
	bool isEntry;
	std::map<char, Node*>* outgoing;
};

#endif