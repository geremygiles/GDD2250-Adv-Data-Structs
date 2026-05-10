#pragma once

enum Suit
{
	Heart,
	Diamond,
	Club,
	Spade
};

enum Value
{
	Ace,
	One,
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
public:
	Card(Suit, Value);

private:
	Suit suit;
	Value value;
};

