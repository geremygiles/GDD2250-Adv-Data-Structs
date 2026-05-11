#include "GameManager.h"

#include <list>
#include <string>
#include "Deck.h"

GameManager::GameManager()
{
	currentDeck = new Deck();
	dealersHand = {};
	playersHand = {};
	playersTurn = true;
	shouldDealerHit = true;
}

void GameManager::DealCards()
{
	for (int i = 0; i < 2; i++)
	{
		// Deal 1 card to the player
		playersHand.push_back(currentDeck->Draw());

		// Deal 1 card to the dealer
		dealersHand.push_back(currentDeck->Draw());
	}
	dealersHand.front()->SetFaceUp(false);
}

std::list<Card*>* GameManager::GetHand(bool player)
{
	return player ? &playersHand : &dealersHand;
}

std::string GameManager::GetHandString(std::list<Card*>* hand) const
{
	std::string returnString = "";

	for (const Card* card : *hand)
	{
		if (card->GetFaceUp())
		{
			returnString += card->GetCardString();
			if (card != hand->back()) returnString += ", ";
		}
	}

	return returnString;
}

int GameManager::GetHandValue(std::list<Card*>* hand) const
{
	int handValue = 0;
	for (const Card* card : *hand)
	{
		handValue += card->GetValueInt();
	}

	return handValue;
}

bool GameManager::IsPlayersTurn() const
{
	return playersTurn;
}

std::string GameManager::PlayerDecision(int decisionIndex)
{
	switch (decisionIndex)
	{
	case 1: // Hit
		playersHand.push_back(currentDeck->Draw());
		return "You chose to hit. The dealer dealt you a " + playersHand.back()->GetCardString();
		break;
	case 2: // Stand
		playersTurn = false; // End players turn
		return "You chose to stand.";
		break;
	case 3: // Double Down
		// TODO: Double Bet
		playersTurn = false; // End players turn
		playersHand.push_back(currentDeck->Draw());
		return "You chose to double down. Your bet has been doubled to TODO. The dealer dealt you a " + playersHand.back()->GetCardString();
		break;
	case 4: // Surrender
		playersTurn = false; // End players turn
		return "You chose to surrender. You got TODO back.";
		break;
	case 5: // Split
		return "You chose to split. You now have 2 hands. TOOOODOOOO";
		break;
	default:
		break;
	}
}

bool GameManager::CheckBust(std::list<Card*>* hand) const
{
	if (GetHandValue(hand) > 21) return true;
	else return false;
}

void GameManager::FlipDealersCard()
{
	dealersHand.front()->SetFaceUp(true);
}

bool GameManager::GetShouldDealerHit() const
{
	return shouldDealerHit;
}

std::string GameManager::DealerHit()
{
	dealersHand.push_back(currentDeck->Draw());
	CheckDealerHit(); // Check if the dealer should hit again

	return "Dealer has hit. They got a " + dealersHand.back()->GetCardString();
}

int GameManager::CalculateWin()
{
	if (GetHandValue(&playersHand) > GetHandValue(&dealersHand)) return 2;
	else if (GetHandValue(&playersHand) == GetHandValue(&dealersHand)) return 1;
	else return 0;
}

bool GameManager::CheckAce(std::list<Card*>* hand) const
{
	for (const Card* card : *hand)
	{
		if (card->GetValue() == Value::Ace) return true;
	}

	return false;
}




// Private Methods

void GameManager::CheckDealerHit()
{
	if (GetHandValue(&dealersHand) <= 16) shouldDealerHit = true;
	else shouldDealerHit = false;
}

