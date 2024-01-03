
#include <stdio.h>
#include <stdlib.h>
#include "./Game/Game.h"

int main(int argc, int argv) {
	
	printf("\n\nWelcome to the coin flipping game!\n\n");

	GameStatus initial = initGameStatus();
	game_loop(initial);

	return 0;
}

