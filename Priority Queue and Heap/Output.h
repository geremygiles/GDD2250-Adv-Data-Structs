#pragma once
#include <string>

class Output
{
public:
	void PrintHeapIntro();
	void PrintQueueIntro();
	void PrintArray(int[], int size);

	int PromptInt(std::string prompt) const;
};

