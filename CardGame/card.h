
#pragma once

#include <iostream>;

enum value_t {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13
};

enum suit_t {
	SPADES = 1,
	HEARTS = 2,
	DIAMONDS = 3,
	CLUBS = 4
};

struct Card {
	value_t value;
	suit_t suit;

	void print() const {
		std::cout << "[" << value << "," << suit << "]";
	}
};
