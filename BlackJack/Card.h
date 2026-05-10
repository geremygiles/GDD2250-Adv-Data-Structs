#pragma once
#include <string>

enum Suit
{
	Hearts,
	Diamonds,
	Clubs,
	Spades
};

enum Value
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten, Jack, Queen, King
};

class Card
{
private:
	static const std::string CARD_SUITS[4];
	static const std::string CARD_VALUES[13];

public:
	Card(Suit, Value);
	Card(Suit, Value, bool faceUp);
	void SetNextCard(Card*);
	Card* GetNextCard() const;
	Value GetValue() const;
	int GetValueInt() const;
	Suit GetSuit() const;
	std::string GetCardString() const;
	bool GetFaceUp() const;
	void SetFaceUp(bool);

private:
	Suit suit;
	Value value;
	Card* nextCard;
	bool faceUp;
};

