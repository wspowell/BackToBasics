
#include "game.h"

int main(void) {

	GoFish game(2);
	game.deal();
	while (!game.doPlayerTurn()) {}
	game.getWinner();

	return 0;
}