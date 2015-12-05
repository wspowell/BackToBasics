
#pragma once

#include <vector>
#include "card.h"

class Player {
	private:
	std::vector<const Card> hand;
	const unsigned int maxCardsInHand;

	public:
	// Defaults to no hand limit, starting hand (vector) capacity of 13 (52 cards / 4 players)
	Player();
	// Provides a hand limit
	Player(const unsigned int maxCardsInHand);
	~Player();

	// Adds one card to the players hand
	void addCard(const Card card);
	// Searches the players hand for a card
	// Returns true if player has the card
	bool hasCard(const Card search) const;
	bool hasCardValue(const value_t search) const;
	// Removes the card from the players hand
	// The card must be included or throws std::invalid_argument
	void removeCard(const Card card);
	void removeCardValue(const value_t card);
	// Returns the number of cards in the Players hand
	unsigned int countCards() const;
	// Returns the players hand
	const std::vector<const Card>& const getHand() const;

	private:
	// Finds the index of the search card
	// Return the index or -1 if not found
	int search(const Card search) const;
	int searchValue(const value_t search) const;
};