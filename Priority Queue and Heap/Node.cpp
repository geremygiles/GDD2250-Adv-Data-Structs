#include "Node.h"

Node::Node()
{
	Node("empty", 0);
}

Node::Node(std::string _message, int _priority)
{
	message = _message;
	priority = _priority;
}

int Node::GetPriority()
{
	return priority;
}

std::string Node::PrintMessage() const
{
	return message;
}