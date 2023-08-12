#ifndef DFAITER_H
#define DFAITER_H

#include "node.h"
#include "dfaiter.h"

struct DFAIter
{
public:
	Node* node;
	bool noPath;
	bool endOfInput;
};

#endif