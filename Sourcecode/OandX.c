#include <stdio.h>

void instructions()
{

    printf("Board positions are as follows: \n");

    printf("\t\t\t  1 |  2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
    return;
}


void initialize(char* array)
{
      char idx;
      for(idx=0; idx < 9; idx++)
      {
          array[idx] = NULL;
      }
}

void display(char* array)
{
    printf("\n\n");

    printf("\t\t\t  %c | %c  | %c  \n", array[0], array[1], array[2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", array[3], array[4], array[5]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", array[6], array[7], array[8]);
    return;
}

void insert(char* array, int pos, char move)
{
    int idx;

    for(idx = 8; idx>= pos; idx--)
    {
        array[idx] = array[idx];
    }
    array[idx] = move;
}

void CheckWinner(char* array)
{
      if(array[0] && array[1] && array[2] == 'O' )
      {
          int winner = 1;
      }
}

int main()
{
    instructions();

    char board[8];
    int position;
    char move;

    initialize(board);


    printf("Enter a position and a move: ");
    scanf("%d %s", &position, &move);
    printf("\n");
    insert(board, position, move);



    display(board);

    return 0;
}
