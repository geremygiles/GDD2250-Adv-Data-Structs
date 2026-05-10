#pragma once
#include "Card.h"

class Deck
{
public:
	Deck();
	Card* Draw();
	void PrintDeck();

private:
	Card* topCard;
};

