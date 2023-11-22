#ifndef DFA_H
#define DFA_H

#include "graph.h"
#include "dfaiter.h"
#include <string>

class DFA {
public:
	DFA (Graph* graph);
	void Reset();
	bool Init(std::string* input);
	DFAIter* Next();
private:
	unsigned long inputIndex;
	DFAIter* dfaIter;
	std::string* input;
	Graph* graph;
};

#endif
