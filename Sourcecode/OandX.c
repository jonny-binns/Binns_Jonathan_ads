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
    if(move == 'X' || move == 'O')
    {
        for(idx = 8; idx>= pos; idx--)
        {
            array[idx] = array[idx];
        }
            array[idx] = move;
    }
    else
    {
        printf("Error: Invalid Character\n");
        return;
    }
}

void addMove(char* array)
{
    int position;
    char move;

    printf("Enter a position and a move: ");
    scanf("%d%c", &position, &move);
    printf("\n");

    //random char insertion
    if(array[position-1] == NULL)
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

void checkWinner(char* array, int* winner)
{
    if(array[0] == 'X' && array[1] == 'X' && array[2] == 'X')
    {
        *winner = 1;
    }
    else if(array[0] == 'O' && array[1] == 'O' && array[2] == 'O')
    {
        *winner = 1;
    }
    else if(array[3] == 'X' && array[4] == 'X' && array[5] == 'X')
    {
        *winner = 1;
    }
    else if(array[3] == 'O' && array[4] == 'O' && array[5] == 'O')
    {
        *winner = 1;
    }
    else if(array[6] == 'X' && array[7] == 'X' && array[8] == 'X')
    {
        *winner = 1;
    }
    else if(array[6] == 'O' && array[7] == 'O' && array[8] == 'O')
    {
        *winner = 1;
    }
    else if(array[0] == 'X' && array[3] == 'X' && array[6] == 'X')
    {
        *winner = 1;
    }
    else if(array[0] == 'O' && array[3] == 'O' && array[6] == 'O')
    {
        *winner = 1;
    }
    else if(array[1] == 'X' && array[4] == 'X' && array[7] == 'X')
    {
        *winner = 1;
    }
    else if(array[1] == 'O' && array[4] == 'O' && array[7] == 'O')
    {
        *winner = 1;
    }
    else if(array[2] == 'X' && array[5] == 'X' && array[8] == 'X')
    {
        *winner = 1;
    }
    else if(array[2] == 'O' && array[5] == 'O' && array[8] == 'O')
    {
        *winner = 1;
    }
    else if(array[0] == 'X' && array[4] == 'X' && array[8] == 'X')
    {
        *winner = 1;
    }
    else if(array[0] == 'O' && array[4] == 'O' && array[8] == 'O')
    {
        *winner = 1;
    }
    else if(array[2] == 'X' && array[4] == 'X' && array[6] == 'X')
    {
        *winner = 1;
    }
    else if(array[2] == 'O' && array[4] == 'O' && array[6] == 'O')
    {
        *winner = 1;
    }
    else
    {
        *winner = 0;
    }
}

int main()
{
    instructions();

    char board[8];
    int winner = 0;
    initialize(board);
    //display(board);

    while(winner == 0)
    {
      addMove(board);
      checkWinner(board, &winner);
    }

    printf("%d\n", winner);


    return 0;
}
