#include <stdio.h>
#include <stdbool.h>

#define num_line 6
#define num_col 7

int tabl[num_line][num_col];

/*Init function to setup the puissance4 table*/
void init_tabl(void){
  int i, j;
  for(i=0; i<num_line; i++){
    for(j=0; j<num_col; j++){
      tabl[i][j] = 0;
    }
  }
}

/*Display the table*/
void print_tabl(void){
  int i, j;
  const char displays[] = ".ox";
  for(i=0; i<num_line; i++){
      printf("\n");                                                                                                       
      for(j=0; j<num_col; j++){                                                                                             
        printf("%c ", displays[tabl[i][j]]);
    }
  }
  printf("\n");
}

/*ask the column to play*/
int ask_column(int player){
  int col_chosen;
  char col_chosen_char[10];
  printf("Player %d, please enter a column number between 1 and %d : ", player, num_col);
  scanf("%d", &col_chosen);
  
  while(col_chosen < 1 || col_chosen > 7){
    printf("The value you have written isn't a number between 1 and %d, please retry : ", num_col);
    scanf(" %d", &col_chosen);
  }
  return col_chosen-1;
}
/* search the lowest line where a token can be put in the given column and returns it's number*/
int search_lowest_available(int column){
  int line;
  for (line = 0; line<num_line; line++) {
    if (tabl[line][column] != 0){
      return line-1;
    }
  }
  return num_line-1;
}
/*puts a token in the given column at the lowest line possible*/
void place_token(int player, int column){
  int line_to_place_on = search_lowest_available(column);
  tabl[line_to_place_on][column] = player;
}
/*counts the number of successive token in the direction given starting from the position given*/
int numb_successive_token(int player, int start_line, int start_col, int direc_line, int direc_col){
  int numb_tokens = 0;
  int actual_line = start_line + direc_line;
  int actual_col = start_col + direc_col;

  while (actual_line >= 0 && actual_line < num_line && actual_col >= 0 && actual_col < num_col){

    if(tabl[actual_line][actual_col] != player){
      return numb_tokens;
    }
    numb_tokens++;
    actual_line = actual_line + direc_line;
    actual_col = actual_col + direc_col;
  }
  return numb_tokens;
}

/*tests if there is a 4-token alignement from a certain position*/
bool victory_test(int player, int line, int col){
  if(numb_successive_token(player, line, col, 1, 0) + numb_successive_token(player, line, col, -1, 0) >= 3 /* veritcal axis*/
  || numb_successive_token(player, line, col, 0, 1) + numb_successive_token(player, line, col, 0, -1) >= 3 /* horizontal axis*/
  || numb_successive_token(player, line, col, -1, 1) + numb_successive_token(player, line, col, 1, -1) >= 3 /*diagonal from bottom left to top right*/
  || numb_successive_token(player, line, col, -1, -1) + numb_successive_token(player, line, col, 1, 1) >= 3) /* diagonal from top left to bottom right*/ 
  {
    return true;
  }
  return false;
}

/*switches between the different players*/
int change_player(int player){
  return player == 1 ? 2 : 1;
}

/*Main founction of the game*/
int main(void){
  int max_tokens = num_col * num_line;
  int tokens_placed = 0;
  int actual_player = 1;
  bool victory = false;
  init_tabl();
  while(victory == false && tokens_placed < max_tokens){
    print_tabl();
    int actual_turn = tokens_placed/2 +1;
    printf("\nTURN NUMBER %d\n", actual_turn);
    int col_chosen = ask_column(actual_player);
    int line_token_placed = search_lowest_available(col_chosen);
    place_token(actual_player, col_chosen);
    if (victory_test(actual_player, line_token_placed, col_chosen)){
      print_tabl();
      printf("Player %d won in %d turns, congratulations !! \n", actual_player, actual_turn);
      victory = true;
    }

    tokens_placed++;
    actual_player = change_player(actual_player);
  }
  if (victory == false){
    printf("Draw : no one managed to align 4 tokens !\n");
  }
}
