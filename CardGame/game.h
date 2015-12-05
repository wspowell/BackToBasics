// Implements a basic game of Go-Fish

#pragma once

#include <vector>
#include "deck.h"
#include "player.h"

struct PlayerData {
	Player player;
	unsigned int pairsMatched;

	PlayerData() : player(Player()), pairsMatched(0) {}
};

class GoFish {
	private:
	Deck deck;
	std::vector<PlayerData> players;
	unsigned int currentTurn;
	
	public:
	GoFish(unsigned int numberOfPlayers);
	~GoFish();
	
	// Deals cards to players
	void deal();
	// Executes one turn for a player
	// Return true if the game is over
	bool doPlayerTurn();
	// Prints the player(s) who won
	void getWinner() const;
};