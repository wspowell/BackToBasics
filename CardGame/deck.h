// Defines a deck of playing cards

#pragma once

#include <deque>
#include "card.h"

const std::deque<const Card> standardDeck{
	Card{ ACE, SPADES }, Card{ ACE, HEARTS }, Card{ ACE, DIAMONDS }, Card{ ACE, CLUBS },
	Card{ TWO, SPADES }, Card{ TWO, HEARTS }, Card{ TWO, DIAMONDS }, Card{ TWO, CLUBS },
	Card{ THREE, SPADES }, Card{ THREE, HEARTS }, Card{ THREE, DIAMONDS }, Card{ THREE, CLUBS },
	Card{ FOUR, SPADES }, Card{ FOUR, HEARTS }, Card{ FOUR, DIAMONDS }, Card{ FOUR, CLUBS },
	Card{ FIVE, SPADES }, Card{ FIVE, HEARTS }, Card{ FIVE, DIAMONDS }, Card{ FIVE, CLUBS },
	Card{ SIX, SPADES }, Card{ SIX, HEARTS }, Card{ SIX, DIAMONDS }, Card{ SIX, CLUBS },
	Card{ SEVEN, SPADES }, Card{ SEVEN, HEARTS }, Card{ SEVEN, DIAMONDS }, Card{ SEVEN, CLUBS },
	Card{ EIGHT, SPADES }, Card{ EIGHT, HEARTS }, Card{ EIGHT, DIAMONDS }, Card{ EIGHT, CLUBS },
	Card{ NINE, SPADES }, Card{ NINE, HEARTS }, Card{ NINE, DIAMONDS }, Card{ NINE, CLUBS },
	Card{ TEN, SPADES }, Card{ TEN, HEARTS }, Card{ TEN, DIAMONDS }, Card{ TEN, CLUBS },
	Card{ JACK, SPADES }, Card{ JACK, HEARTS }, Card{ JACK, DIAMONDS }, Card{ JACK, CLUBS },
	Card{ QUEEN, SPADES }, Card{ QUEEN, HEARTS }, Card{ QUEEN, DIAMONDS }, Card{ QUEEN, CLUBS },
	Card{ KING, SPADES }, Card{ KING, HEARTS }, Card{ KING, DIAMONDS }, Card{ KING, CLUBS },
};

class Deck {
	private:
	std::deque<const Card> deck;

	public:
	Deck();
	~Deck();
	
	// Returns the number of cards in the Deck
	unsigned int count() const;
	// Shuffles the current deck of cards
	void shuffle();
	// Resets the deck to its orginial ordered state (non-shuffled)
	void reset();
	// Draws one card from the Deck
	const Card draw();
	// Adds the given card to the bottom of the Deck
	void discard(const Card card);
};
