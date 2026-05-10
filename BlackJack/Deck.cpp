#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

Deck::Deck()
{
	// Initialize Variables
	topCard = nullptr;

	int cardCount = 0;
	// The amount of cards left to create
	int cardsRemaining[52] = {};

	for (int i = 0; i < 52; i++)
	{
		// Fill each slot with 1
		cardsRemaining[i] = 1;
	}

	// Seed random number generator
	srand(time(0));
	
	Card* currentCard = nullptr;

	while (cardCount < 52)
	{
		int randomIndex = -1;

		while (randomIndex == -1)
		{
			// Get a random number from 0 to 51
			randomIndex = rand() % 52;

			// If that card is no longer available, try again
			if (cardsRemaining[randomIndex] == 0) randomIndex = -1;
		}

		cardsRemaining[randomIndex] = 0; // Set this card as used

		// Calculate suit
		int suitIndex = randomIndex / 13;

		// Calculate value 
		int valueIndex = randomIndex % 13;

		// Add a new card
		Card* newCard = new Card(static_cast<Suit>(suitIndex), static_cast<Value>(valueIndex));

		// If this is the first card, set it as the top card
		if (cardCount == 0) topCard = newCard;
		// Otherwise, set the new card as the next card for the last
		else currentCard->SetNextCard(newCard);

		// Set this new card as the current
		currentCard = newCard;
		cardCount++;
	}
}

Card* Deck::Draw()
{
	Card* draw = topCard;
	if (topCard->GetNextCard() != nullptr)
	{
		topCard = topCard->GetNextCard();
	}
	else
	{
		// Ran out of cards
	}
	return draw;
}

void Deck::PrintDeck()
{
	Card* currentCard = topCard;
	while (currentCard->GetNextCard() != nullptr)
	{
		std::cout << currentCard->GetCardString() << std::endl;
		currentCard = currentCard->GetNextCard();
	}
	std::cout << currentCard->GetCardString() << std::endl;
}