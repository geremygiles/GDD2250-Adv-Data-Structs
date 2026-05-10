#pragma once
#include <string>

class Output
{
public:
	// Print intro
	void PrintIntro();
	// Prompt for rules
	void PromptRules();
	// Prompt for play again
	bool PromptPlayAgain();
	// Print game start
	void PrintGameStart();

	// Print goodbye
	void PrintOutro();

private:
	// Prompt for a y/n char
	bool PromptYN(std::string);
};

