#pragma once

#include <list>
#include <string>
#include "Card.h"
#include "Deck.h"

class GameManager
{
public:
	GameManager();
	void DealCards();
	std::list<Card*>* GetHand(bool player);
	std::string GetHandString(std::list<Card*> hand) const;
	int GetHandValue(std::list<Card*> hand) const;
	bool IsPlayersTurn() const;
	std::string PlayerDecision(int);
	void FlipDealersCard();
	bool GetShouldDealerHit() const;
	std::string DealerHit();
	

private:
	Deck* currentDeck;
	std::list<Card*> dealersHand;
	std::list<Card*> playersHand;
	bool playersTurn;
	bool shouldDealerHit;
	void CheckDealerHit();
};

