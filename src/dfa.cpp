#include "dfa.h"
#include "dfaiter.h"

DFA::DFA(Graph* graph)
{
	this->inputIndex = 0;
	this->dfaIter = new DFAIter();
	this->graph = graph;
	this->input = nullptr;
}

void DFA::Reset()
{
	delete dfaIter;
	inputIndex = 0;
	input = nullptr;
}

bool DFA::Init(std::string* input)
{
	if (!dfaIter->endOfInput) Reset();
	if (input == nullptr 
		|| input->size() == 0
		|| graph->GetEntry() == nullptr) 
		return false;
	dfaIter->node = graph->GetEntry();
	this->inputIndex = 0;
	this->input = input;
}

DFAIter* DFA::Next()
{
	// get the next char
	if (dfaIter->endOfInput || dfaIter->noPath) return dfaIter;
	char nextChar = input->at(inputIndex + 1);
	// check if we have a node to go to from the current
	Node* next = dfaIter->node->GetConnection(nextChar);
	if (next == nullptr)
	{
		dfaIter->noPath = true;
		return dfaIter;
	}
	dfaIter->node = next;
	if (inputIndex + 1 == input->size() - 1) dfaIter->endOfInput = true;
	inputIndex++;
	return dfaIter;
}
