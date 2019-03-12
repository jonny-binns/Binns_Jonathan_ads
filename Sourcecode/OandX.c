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
    if(move = 'X' || move = 'O')
    {
      for(idx = 8; idx>= pos; idx--)
      {
          array[idx] = array[idx];
      }
        array[idx] = move;
    }
    else
    {
       return;
    }
}

void addMove(char* array)
{
    int position;
    char move;

    printf("Enter a position and a move: ");
    scanf("%d%s", &position, &move);
    printf("\n");

    //random char insertion
    if(array[position-1] = NULL)
    {
		    insert(array, position, move);
        display(array);
    }
    else
    {
        printf("Error: Space Already Taken \n");
        return;
    }
}


int main()
{
    instructions();

    char board[8];
    initialize(board);
    //display(board);

    addMove(board);
    addMove(board);

    return 0;
}
