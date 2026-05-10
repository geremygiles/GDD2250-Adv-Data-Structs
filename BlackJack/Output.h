#pragma once
#include <string>

class Output
{
public:
	// Print intro
	void PrintIntro();
	// Print game start
	void PrintGameStart(
		std::string playersHand, 
		std::string dealersHand);
	// Print dealer card flip
	void PrintFlip(std::string dealersHand);
	// Print player' summary's cards and final value
	void PrintPlayerSummary(std::string hand);
	// Print dealer summary
	void PrintDealerSummary(std::string hand);
	// Print goodbye
	void PrintOutro();

	// Prompt for rules
	void PromptRules();
	// Prompt for play again
	bool PromptPlayAgain();
	// Prompt for player decision
	int PromptDecision();

private:
	// Prompt for a y/n char
	bool PromptYN(std::string prompt);

	// Prompt for an int within a range
	int PromptInt(std::string prompt, int min, int max);
};

