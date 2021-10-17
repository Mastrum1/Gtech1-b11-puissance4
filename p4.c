#include <stdio.h>
#define num_line 6
#define num_col 7

char tabl[num_line][num_col];

void init(void){
  int i, j;
  for(i=0; i<num_line; i++){
    for(j=0; j<num_col; j++){
      tabl[i][j] = '.';
    }
  }
}



int main(void){
  int num_turns = 22;
  int actual_turn = 1;
  int i, j;
  int col_chosen = 0;
  init();
  while(actual_turn < num_turns){
    for(i=0; i<num_line; i++){
      printf("\n");
      for(j=0; j<num_col; j++){
        printf("%c ", tabl[i][j]);
      }
    }
    printf("\nTURN NUMBER %d\n", actual_turn);
    do{
      printf("Please enter a column number between 1 and %d : ", num_col);
      scanf("%d", &col_chosen);
    }
    while(col_chosen < 1 || col_chosen > 7);
      printf("The value you have written isn't a number between 1 and 7, please retry : ");
      scanf(" %d", &col_chosen);

    actual_turn++;
  }
}
