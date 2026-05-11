#pragma once
#include <string>

class Output
{
public:
	// Print intro
	void PrintIntro() const;
	// Print game start
	void PrintGameStart(
		std::string playersHand, 
		std::string dealersHand) const;
	// Print dealer card flip
	void PrintFlip(std::string dealersHand) const;
	// Print player' summary's cards and final value
	void PrintPlayerSummary(
		std::string hand, 
		int value) const; 
	// Print dealer summary
	void PrintDealerSummary(std::string hand, int value) const;
	// Print the results of the game
	void PrintResults(int result) const;
	// Print goodbye
	void PrintOutro() const;

	// Prompt for rules
	void PromptRules() const;
	// Prompt for play again
	bool PromptPlayAgain() const;
	// Prompt for player decision
	int PromptDecision() const;
	// Prompt player for ace value(s)

private:
	// Prompt for a y/n char
	bool PromptYN(std::string prompt) const;

	// Prompt for an int within a range
	int PromptInt(std::string prompt, int min, int max) const;
};

