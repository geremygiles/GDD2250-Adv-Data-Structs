#include "Card.h"
#include <string>

// Declaring static 
const std::string Card::CARD_SUITS[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const std::string Card::CARD_VALUES[13] = {
"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
"Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

Card::Card(Suit _suit, Value _value, bool _faceUp) : Card(_suit, _value)
{
	Card::faceUp = _faceUp;
}

Card::Card(Suit _suit, Value _value)
{
	Card::suit = _suit;
	Card::value = _value;
	Card::faceUp = true;
	Card::nextCard = nullptr;
}

void Card::SetNextCard(Card* nextCard)
{
	Card::nextCard = nextCard;
}

Card* Card::GetNextCard() const
{
	return nextCard;
}

Value Card::GetValue() const
{
	return value;
}

int Card::GetValueInt() const
{
	if (value == Value::Ace)
	{
		return 1; // TODO: 11
	}
	else if (value > Value::Ten)
	{
		return 10;
	}
	else return value + 1;
}

Suit Card::GetSuit() const
{
	return suit;
}

std::string Card::GetCardString() const
{
	return CARD_VALUES[GetValue()] + " of " + CARD_SUITS[GetSuit()];
}

bool Card::GetFaceUp() const
{
	return faceUp;
}

void Card::SetFaceUp(bool _faceUp)
{
	faceUp = _faceUp;
}