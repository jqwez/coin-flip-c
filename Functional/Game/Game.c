#include "./Game.h"


GameStatus createGameStatus(int quit, int flips, int player_wins, int player_losses, char* coin_history)
{
	GameStatus newGame = {
		quit,
		flips,
		player_wins,
		player_losses,
		coin_history
	};
	return newGame;
}

GameStatus initGameStatus()
{
	GameStatus gs = {
		0,
		0,
		0,
		0,
		0 
	};
	return gs;
}


void game_loop(GameStatus gs)
{
	if ( gs.quit == 1 ) {
		print_stats(gs);
		return;
	}
	GameStatus newGame = please_guess(gs);
	game_loop(newGame);
}

char* add_history(GameStatus gs, char letter) 
{
	char* newArr = (char*)malloc((gs.flips+1)*sizeof(char));
	memcpy(newArr, gs.coin_history, gs.flips*sizeof(char));
	newArr[gs.flips] = letter;
	return newArr;
}

GameStatus please_guess(GameStatus gs) 
{
		printf("\nPlease guess!\n");
		char *guess=malloc(sizeof(char)*10);
		scanf("%s", guess);
		
		// Value of H & h
		if (guess[0] == 72 || guess[0] == 104) {
			free(guess);
			 int choice = 104;
			 return flip_coin(gs, choice);
			 
		}
		// Value of T & t
		else if (guess[0] == 84 || guess[0] == 116) {
			free(guess);
			int choice = 116; 
			return flip_coin(gs, choice);
		}
		else if (guess[0] == 83 || guess[0] == 115) {
			free(guess);
			print_stats(gs);
			return gs;
		}
		// Value of Q & q 
		else if (guess[0] == 81 || guess[0] == 113) {
			free(guess);
			GameStatus end = {
				1,
				gs.flips,
				gs.player_wins,
				gs.player_losses,
				gs.coin_history
			};
			return end;
		} else {
			printf("\nPlease choose from H(eads), T(ails), S(tats) or Q(uit)\n");
			free(guess);
			return gs;
		}
	}

GameStatus flip_coin(GameStatus gs, int choice) {
	int flips = gs.flips+1;
	int wins;
	int losses;
	char* newHistory;
	int random_choice = (rand() > RAND_MAX/2) ? 104 : 116;
	if (random_choice == 104) {
		newHistory = add_history(gs, 104);
	}
	else {
		newHistory = add_history(gs, 116);
	}

	char *chosen_letter = choice==104? "H": "T";
	char *not_chosen = choice==104? "T": "H";

	if (choice == random_choice) {
		losses = gs.player_losses;
		wins = gs.player_wins+1;
		printf("Correct! You picked %s and the result was %s\n", chosen_letter, chosen_letter);
	}
	else {
		wins = gs.player_wins;
		losses = gs.player_losses+1;
		printf("Wrong! You picked %s and the result was %s\n", chosen_letter, not_chosen);
	}
	free(gs.coin_history);
	GameStatus newGame = { .quit = 0, .flips = flips, .player_wins = wins, .player_losses = losses, .coin_history = newHistory } ;
	return newGame;
}

void print_coin_history(GameStatus gs, int index) {
	int size = gs.flips;
	if (index >= size) {
		return;
	}
	if (index == 0) {
		printf("[");
	}
	if (index < size) {
		printf("%s", gs.coin_history[index]==104?" H":" T");
	}
	if (index < size-1) {
		printf(",");
	} else {
		printf(" ]\n");
	}
	print_coin_history(gs, index+1);
}
	
void print_stats(GameStatus gs){
	printf("\n Your statistics are:\n");
	printf("Player wins: %i\n", gs.player_wins);
	printf("Player losses: %i\n", gs.player_losses);
	printf("Coin history: ");
	print_coin_history(gs, 0);
}
