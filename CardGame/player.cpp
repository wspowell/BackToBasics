
#include "player.h"

Player::Player() : hand(std::vector<const Card>()), maxCardsInHand(0) {
	this->hand.reserve(13);
}

// Provides a hand limit
Player::Player(const unsigned int maxCardsInHand) : hand(std::vector<const Card>()), maxCardsInHand(maxCardsInHand) {
	this->hand.reserve(maxCardsInHand);
}

Player::~Player() {}

// Adds one card to the players hand
void Player::addCard(const Card card) {
	// only insert card if maximum has not been reached
	if (this->maxCardsInHand != 0 && this->countCards() == this->maxCardsInHand) {
		throw std::length_error("player's hand is at the maximum hand limit");
	}
	this->hand.push_back(card);
}

// Returns the number of cards in the Players hand
unsigned int Player::countCards() const {
	return this->hand.size();
}

// Searches the players hand for a card
// Returns true if player has the card
bool Player::hasCard(const Card search) const {
	return this->search(search) == -1 ? false : true;
}

bool Player::hasCardValue(const value_t search) const {
	return this->searchValue(search) == -1 ? false : true;
}

// Removes the card from the players hand
// The card must be included or throws std::invalid_argument
void Player::removeCard(const Card card) {
	int location = this->search(card);
	if (location == -1) {
		throw std::invalid_argument("card not found in player's hand");
	}
	// swap card with the end of the vector
	this->hand[location] = this->hand.back();
	// remove the card that is now at the end
	this->hand.pop_back();
}

void Player::removeCardValue(const value_t card) {
	int location = this->searchValue(card);
	if (location == -1) {
		throw std::invalid_argument("card not found in player's hand");
	}
	// swap card with the end of the vector
	this->hand[location] = this->hand.back();
	// remove the card that is now at the end
	this->hand.pop_back();
}

// Returns the players hand
const std::vector<const Card>& const Player::getHand() const {
	return this->hand;
}

// Finds the index of the search card
// Return the index or -1 if not found
int Player::search(const Card search) const {
	int location = 0;
	for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter, ++location) {
		if (iter->value == search.value && iter->suit == search.suit) {
			return location;
		}
	}
	return -1;
}

int Player::searchValue(const value_t search) const {
	int location = 0;
	for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter, ++location) {
		if (iter->value == search) {
			return location;
		}
	}
	return -1;
}