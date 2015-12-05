
#include <iostream>
#include "game.h"

GoFish::GoFish(unsigned int numberOfPlayers) : deck(Deck()), players(std::vector<PlayerData>(numberOfPlayers)), currentTurn(0) {}
GoFish::~GoFish() {}

// Deals cards to players
void GoFish::deal() {
	this->deck.shuffle();
	for (auto iter = this->players.begin(); iter != this->players.end(); ++iter) {
		std::cout << "Drawing for player " << iter - this->players.begin() << std::endl;
		for (unsigned int count = 0; count < 5; ++count) {
			Card card = this->deck.draw();
			std::cout << "Drew ";
			card.print();
			std::cout << std::endl;
			// check for pairs
			if (iter->player.hasCardValue(card.value)) {
				++iter->pairsMatched;
				iter->player.removeCardValue(card.value);
			} else {
				iter->player.addCard(card);
			}
		}
	}
}

// Executes one turn for a player
// Return true if the game is over
bool GoFish::doPlayerTurn() {
	unsigned int player = -1;
	unsigned int value = -1;
	value_t cardValue;
	do {
		player = -1;
		value = -1;

		std::cout << "Turn for Player " << this->currentTurn << ", Pairs Matched " << this->players[currentTurn].pairsMatched << std::endl;
		std::cout << "Hand:" << std::endl;
		for (auto iter = this->players[currentTurn].player.getHand().begin(); iter != this->players[currentTurn].player.getHand().end(); ++iter) {
			iter->print();
			std::cout << " ";
		}
		std::cout << std::endl;

		while (player < 0 || player > this->players.size() || player == currentTurn) {
			std::cout << "Pick a player: ";
			std::cin >> player;
			if (player < 0 || player >= this->players.size() || player == currentTurn) {
				std::cout << "Invalid player." << std::endl;
			}
		}

		while (value < 1 || value > 13) {
			std::cout << "Guess a card value(1-13): ";
			std::cin >> value;
			if (value < 1 || value > 13) {
				std::cout << "Invalid card value." << std::endl;
			}
		}

		cardValue = static_cast<value_t>(value);

		if (!this->players[currentTurn].player.hasCardValue(cardValue)) {
			std::cout << "You do not have that card value." << std::endl;
		}

	} while (!this->players[currentTurn].player.hasCardValue(cardValue));
	
	if (this->players[player].player.hasCardValue(cardValue)) {
		this->players[player].player.removeCardValue(cardValue);
		this->players[currentTurn].player.removeCardValue(cardValue);
		++this->players[currentTurn].pairsMatched;
		std::cout << "Match! Go again!" << std::endl;
		if (this->players[currentTurn].player.countCards() == 0 && this->deck.count() != 0) {
			// draw a new card and go again
			Card card = this->deck.draw();
			this->players[currentTurn].player.addCard(card);
		}
	} else {
		std::cout << "GO FISH!" << std::endl;
		bool matchDrawn = false;
		if (this->deck.count() != 0) {
			Card card = this->deck.draw();
			if (card.value == cardValue) {
				std::cout << "Got what you asked for! Go again!" << std::endl;
				this->players[currentTurn].player.removeCardValue(cardValue);
				++this->players[currentTurn].pairsMatched;
				// go again
				matchDrawn = true;
			} else {
				if (this->players[currentTurn].player.hasCardValue(card.value)) {
					this->players[currentTurn].player.removeCardValue(card.value);
					++this->players[currentTurn].pairsMatched;
					if (this->players[currentTurn].player.countCards() == 0 && this->deck.count() != 0) {
						// draw a new card and go again
						Card card = this->deck.draw();
						this->players[currentTurn].player.addCard(card);
					}
				} else {
					this->players[currentTurn].player.addCard(card);
				}
			}
		}

		if (!matchDrawn) {
			// go to the next player
			if (currentTurn == this->players.size() - 1) {
				currentTurn = 0;
			} else {
				++currentTurn;
			}
		}
	}

	std::cout << std::endl;

	// check if the game is over
	if (this->deck.count() == 0) {
		for (auto iter = this->players.begin() + 1; iter != this->players.end(); ++iter) {
			if (iter->player.countCards() != 0) {
				return false;
			}
		}
		return true;
	}
	return false;
}
// Returns the index of the player who won the game
void GoFish::getWinner() const {
	std::vector<unsigned int> winners(this->players.size());
	winners.push_back(0);
	for (auto iter = this->players.begin() + 1; iter != this->players.end(); ++iter) {
		// check if the current player has more pairs matched than the one(s) in the winners vector
		if (iter->pairsMatched > this->players[winners[0]].pairsMatched) {
			winners.clear();
			winners.push_back(iter - this->players.begin());
		} else if (iter->pairsMatched == this->players[winners[0]].pairsMatched) {
			// tie, more than one winner
			winners.push_back(iter - this->players.begin());
		}
	}

	if (winners.size() != 1) {
		std::cout << "Tie!" << std::endl;
	}
	for (auto iter = winners.begin(); iter != winners.end(); ++iter) {
		std::cout << "Winner: " << iter - winners.begin() << std::endl;
	}
}