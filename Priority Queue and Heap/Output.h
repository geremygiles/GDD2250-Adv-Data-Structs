#pragma once
#include <string>
#include "Node.h"

class Output
{
public:
	void PrintHeapIntro();
	void PrintQueueIntro();
	void PrintArray(int[], int size);
	void PrintQueue(Node*[]);

	int PromptInt(std::string prompt) const;
};

