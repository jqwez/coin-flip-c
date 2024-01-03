#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GameStatus {
	int quit;
	int flips;
	int player_wins;
	int player_losses;
	char* coin_history;
} GameStatus;

GameStatus createGameStatus(int quit, int flips, int player_wins, int player_losses, char* coin_history);
GameStatus initGameStatus();
void game_loop(GameStatus gs);
GameStatus please_guess(GameStatus gs);
GameStatus flip_coin(GameStatus gs, int choice);
void print_coin_history(GameStatus gs, int index);
void print_stats(GameStatus gs);

#endif
