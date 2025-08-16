#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER_OF_MOVES 10

void printBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i < 3) {
      printf("---|---|---\n");
    }
  }
  printf("\n\n");
}

void updateBoard(char board[3][3], char *input) {
  const char sign = input[0];
  const char position = (char)input[1];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == position) {
        board[i][j] = sign;
      }
    }
  }
}

bool validSign(char *sign, char *startSign, int *counter){
  if (*counter % 2 == 0) {
    return (*sign == 'o' || *sign == 'x') && (*sign == *startSign);
  }
  return (*sign == 'o' || *sign == 'x') && (*sign != *startSign);
}

bool validPosition(char *position){
  int pos = (int) *position - '0';
  return pos > 0 && pos < 10;
}
bool validInput(char *input, char *startSign, int *counter){
char sign = input[0];
char position = input[1];
return validSign(&sign,startSign,counter) && validPosition(&position);
}

char victory(char board[3][3]){
for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; // Return the sign of the winner
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i]; // Return the sign of the winner
        }
    }

    // Check diagonals for a win
    // Top-left to bottom-right
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    // Top-right to bottom-left
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // If no winner is found after all checks
    return ' ';}

char signToStart(void){
  srand(time(0));
 int x = rand();
 if (x % 2 == 0) {
   return 'x';
} else {
  return 'o';
}
}


int main(void) {
  char input[2]; // user input, can either be O o X along with the position
  char board[3][3] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
  };
  int counter = 0;
  char startSign = signToStart();
  printf("\n\n");
  printBoard(board);
  printf("Player %c make your start move", startSign);
  while (counter < MAX_NUMBER_OF_MOVES) {
    int *pCounter = &counter;
    printf("\n\n");
    printf("Insert Your move (Your sign and then your position): ");
    scanf("%s", input);
    if (validInput(input,&startSign, pCounter) == true) {
      printf("You have Chosen %s \n", input);
      updateBoard(board, input);
      printBoard(board);
      char winner = victory(board);
      if (winner != ' ') {
        printf("The winner is %c\n",winner);
        return 0;
      }
      counter++;
    } else {
    printf("Invalid Input please insert a valid input (es x2 for an x on the second position) :)\n");
    }
  }
  printf("Is a draw\n");
  return 0;
}
