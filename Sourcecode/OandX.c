#include <stdio.h>

void instructions()
{

    printf("Board positions are as follows: \n");

    printf("\t\t\t  0 |  1  | 2  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  3 | 4  | 5  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  6 | 7  | 8  \n\n");
    return;
}


void initialize(char* array)
{
      char idx;
      for(idx=0; idx < 9; idx++)
      {
          array[idx] = 'O';
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

int main()
{
    instructions();
    char board[8];
    initialize(board);
    display(board);
    char move = 'X';
    insert(board, 6, move);
    display(board);
    return 0;
}
