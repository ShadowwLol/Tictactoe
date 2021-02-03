#include <stdio.h>
#include <stdlib.h>

int player = 1; // 1 or 2
char symbols[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char obj = 'X';
int choice;
int i = 0;

void display(char sym[9]){
	printf("Tic Tac Toe\nPlayer 1: [X]\nPlayer 2: [O]\n");
	printf("\t\t +-----+-----+-----+\n");
	printf("\t\t |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |\n", sym[0], sym[1], sym[2]);
	printf("\t\t +-----+-----+-----+\n");
	printf("\t\t |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |\n", sym[3], sym[4], sym[5]);
	printf("\t\t +-----+-----+-----+\n");
	printf("\t\t |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |  \033[1;31m%c\033[0m  |\n", sym[6], sym[7], sym[8]);
	printf("\t\t +-----+-----+-----+\n");
}

void run();
void checkPatterns(int num1, int num2, int num3);

void game(){
	int InvalidRound = 0;
	while (i < 9){
		printf("\nPlayer %d > ", player);
		scanf("%d", &choice);
		if (choice > 0 && choice < 10){
			if (symbols[choice - 1] != 'X' && symbols[choice - 1] != 'O'){
				symbols[choice - 1] = obj;
			} else {
			InvalidRound = 1;
			}
		} else {
		run();
		}
	if (InvalidRound == 0){
		// Check for patterns
		checkPatterns(0, 1, 2);
		checkPatterns(3, 4, 5);
		checkPatterns(6, 7, 8);

		checkPatterns(0, 3, 6);
		checkPatterns(1, 4, 7);
		checkPatterns(2, 5, 8);

		checkPatterns(0, 4, 8);
		checkPatterns(2, 4, 6);

		// Switch Players
		switch(player){
			case 1:
				player = 2;
				obj = 'O';
				break;
			case 2:
				player = 1;
				obj = 'X';
				break;
		}

		i++;
	}
		break;
	}
	run();
}

void checkPatterns(int num1, int num2, int num3){
	if (symbols[num1] == obj && symbols[num2] == obj && symbols[num3] == obj){
		system("clear");
		printf("Player %d won!", player);
		exit(0);
	}
}

void run(){
	system("clear");
	display(symbols);
	if (i < 9){
		game();
	}
}

int main() {
	run();
	return 0;
}
