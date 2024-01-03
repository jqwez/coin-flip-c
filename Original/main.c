
#include <stdio.h>
#include <stdlib.h>

typedef struct Game {
	int flag;
	int flips;
	int player_wins;
	int player_losses;
	char coin_history[256];
} Game;


void main_loop();
void please_guess(Game *stats);
int flip_coin(Game *stats, int choice);


void print_coin_history(Game *stats);
void print_stats(Game *stats);


int main(int argc, int argv) {
	
	printf("\n\nWelcome to the coin flipping game!\n\n");
	main_loop(1);
	return 0;
}

void main_loop() {
	
	Game *stats = malloc(sizeof(Game));
	stats->flag = 1;
	stats->flips = 0;
	while (stats->flag == 1) {
		please_guess(stats);
	
	}
	printf("\n Thanks for Playing!\n");
	print_stats(stats);

}


void please_guess(Game *stats) {
		printf("\nPlease guess!\n");
		char *guess=malloc(sizeof(char)*10);
		scanf("%s", guess);
		
		// Value of H & h
		if (guess[0] == 72 || guess[0] == 104) {
			 int choice = 104;
			 flip_coin(stats, choice);
			 stats->flips++;
			 
		}
		// Value of T & t
		else if (guess[0] == 84 || guess[0] == 116) {
			int choice = 116; 
			flip_coin(stats, choice);
			stats->flips++;
		}
		else if (guess[0] == 83 || guess[0] == 115) {
			print_stats(stats);
		}
		// Value of Q & q 
		else if (guess[0] == 81 || guess[0] == 113) {
			stats->flag = 0;
		} else {
			printf("\nPlease choose from H(eads), T(ails), S(tats) or Q(uit)\n");
		}
	}

int flip_coin(Game *stats, int choice) {
	int random_choice = (rand() > RAND_MAX/2) ? 104 : 116;
	if (random_choice == 104) {
		stats->coin_history[stats->flips] = 104;
	}
	else {
		stats->coin_history[stats->flips] = 116;
	}

	char *chosen_letter = choice==104? "H": "T";
	char *not_chosen = choice==104? "T": "H";

	if (choice == random_choice) {
		stats->player_wins++;
		printf("Correct! You picked %s and the result was %s\n", chosen_letter, chosen_letter);
		return 0;
	}
	else {
		stats->player_losses++;
		printf("Wrong! You picked %s and the result was %s\n", chosen_letter, not_chosen);
		return 1;
	}
}

void print_coin_history(Game *stats) {
	int i = 0;
	printf("[");
	for (i=0;i<stats->flips;++i) {
		printf("%s,", stats->coin_history[i]==104?"H " :"T ");
	}
	printf("]\n");
}
	
void print_stats(Game *stats){
	printf("\n Your statistics are:\n");
	printf("Player wins: %i\n", stats->player_wins);
	printf("Player losses: %i\n", stats->player_losses);
	printf("Coin history: ");
	print_coin_history(stats);
}
