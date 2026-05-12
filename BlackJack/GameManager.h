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
	std::string GetHandString(std::list<Card*>* hand) const;
	int GetHandValue(std::list<Card*>* hand) const;
	bool IsPlayersTurn() const;
	std::string PlayerDecision(int);
	bool CheckBust(std::list<Card*>* hand) const;
	void FlipDealersCard();
	bool GetShouldDealerHit() const;
	std::string DealerHit();
	int CalculateWin(); // 2 = Win, 1 = Tie, 0 = Lose
	bool CheckAce(std::list<Card*>* hand) const;

	bool PlayerBust = false;
	bool DealerBust = false;

private:
	Deck* currentDeck;
	std::list<Card*> dealersHand;
	std::list<Card*> playersHand;
	bool playersTurn;
	bool shouldDealerHit;
	void CheckDealerHit();
	
};

