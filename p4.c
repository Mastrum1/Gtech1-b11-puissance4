#include <stdio.h>
#define num_line 6
#define num_col 7

char tabl[num_line][num_col];

/*Init function to setup the puissance4 table*/
void init_tabl(void){
  int i, j;
  for(i=0; i<num_line; i++){
    for(j=0; j<num_col; j++){
      tabl[i][j] = '.';
    }
  }
}

/*Display the table*/
void print_tabl(void){
  int i, j;
  for(i=0; i<num_line; i++){                                                                                            printf("\n");                                                                                                       for(j=0; j<num_col; j++){                                                                                             printf("%c ", tabl[i][j]);
    }
  }
}

/*ask the column to play*/
int ask_column(void){
  int col_chosen;
  char col_chosen_char[10];
  printf("\nPlease enter a column number between 1 and %d : ", num_col);
  scanf("%d", &col_chosen);
  
  while(col_chosen < 1 || col_chosen > 7){
    printf("The value you have written isn't a number between 1 and %d, please retry : ", num_col);
    scanf(" %d", &col_chosen);
  }
  return col_chosen;
}


/*puts a token in the given column*/
void place_token(player, column){
  int a;
}

/*Main founction of the game*/
int main(void){
  int num_turns = 22;
  int actual_turn = 1;
  int col_chosen;
  init_tabl();
  while(actual_turn < num_turns){
    print_tabl();
    printf("\nTURN NUMBER %d", actual_turn);
    col_chosen = ask_column();

    actual_turn++;
  }
}
