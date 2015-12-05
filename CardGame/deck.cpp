
#include <algorithm> 
#include <ctime>
#include "deck.h"

Deck::Deck() : deck(standardDeck) {}

Deck::~Deck() {}

// Returns the number of cards in the Deck
unsigned int Deck::count() const {
	return this->deck.size();
}

// Shuffles the current deck of cards
void Deck::shuffle() {
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(this->deck.begin(), this->deck.end());
}

// Resets the deck to its orginial ordered state (non-shuffled)
void Deck::reset() {
	this->deck = std::deque<const Card>(standardDeck);
}

// Draws one card from the Deck
const Card Deck::draw() {
	const Card card = this->deck.front();
	this->deck.pop_front();
	return card;
}

// Adds the given card to the bottom of the Deck
void Deck::discard(const Card card) {
	this->deck.push_back(card);
}
