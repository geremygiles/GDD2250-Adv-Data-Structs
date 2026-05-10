#include "Deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
	int cardCount = 0;
	// The amount of cards left in a suit (Heart - Spade)
	int availableSuits[4];
	for (int i = 0; i < 4; i++) availableSuits[i] = 13;

	// The amount of cards left of a value (Ace - King)
	int availableValues[13];
	for (int j = 0; j < 13; j++) availableValues[j] = 4;

	// Seed random number generator
	srand(time(0));


	while (cardCount < 52)
	{
		int randomSuitIndex = -1;
		Suit cardSuit;

		int randomValueIndex = -1;
		Value cardValue;

		while (randomSuitIndex == -1)
		{
			// Get a random suit from 0 to 3
			randomSuitIndex = rand() % 4;

			// If that suit is no longer available, try again
			if (availableSuits[randomSuitIndex] <= 0) randomSuitIndex = -1;
		}
		
		while (randomValueIndex == -1)
		{
			// Get a random value from 0 to 12
			randomValueIndex = rand() % 13;

			// If that value is no longer available, try again
			if (availableValues[randomValueIndex] <= 0) randomValueIndex = -1;
		}

		cardSuit = static_cast<Suit>(randomSuitIndex);
		cardValue = static_cast<Value>(randomValueIndex);
		

		// Add a new card
		Card* newCard = new Card();

		cardCount++;
	}
}