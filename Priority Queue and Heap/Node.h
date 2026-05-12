#pragma once
#include <string>

// Interface 
struct Queueable
{
	virtual std::string PrintMessage() const = 0;
};

class Node : public Queueable
{
public:
	Node();
	Node(std::string, int);
	int GetPriority();
	std::string PrintMessage() const override;
	

private:
	std::string message;
	int priority;

};

