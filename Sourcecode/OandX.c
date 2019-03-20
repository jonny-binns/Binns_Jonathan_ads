#include <stdio.h>

void instructions()
{
    printf("Board positions are as follows: \n");

    printf("\t\t\t  1 |  2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");

    printf("To make a move type in the board position followed by your character\n");
    printf("For Example: 1X\n");

    return;
}


void initialize(char* array)
{
      int idx;
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

void checkWinner(char* array, int* winner, char* winningPlayer)
{
    if(array[0] == 'X' && array[1] == 'X' && array[2] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[0] == 'O' && array[1] == 'O' && array[2] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[3] == 'X' && array[4] == 'X' && array[5] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[3] == 'O' && array[4] == 'O' && array[5] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[6] == 'X' && array[7] == 'X' && array[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[6] == 'O' && array[7] == 'O' && array[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[0] == 'X' && array[3] == 'X' && array[6] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[0] == 'O' && array[3] == 'O' && array[6] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[1] == 'X' && array[4] == 'X' && array[7] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[1] == 'O' && array[4] == 'O' && array[7] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[2] == 'X' && array[5] == 'X' && array[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[2] == 'O' && array[5] == 'O' && array[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[0] == 'X' && array[4] == 'X' && array[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[0] == 'O' && array[4] == 'O' && array[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(array[2] == 'X' && array[4] == 'X' && array[6] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(array[2] == 'O' && array[4] == 'O' && array[6] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else
    {
        *winner = 0;
    }
}

void checkFullBoard(char* array, int* fullBoard)
{
      int idx;
      int movesMade = 0;


      for(idx=0; idx<9; idx++)
      {
          if(array[idx] != NULL)
          {
              movesMade++;
          }
          else
          {
              return;
          }
      }


      if(movesMade == 9)
      {
          *fullBoard = 1;
      }
      else
      {
          *fullBoard = 0;
      }

      return;
}

void decideFirstGo(int* firstGo)
{
    *firstGo = 1;
}

struct stack
{
      char board[9][9];
      int top;
};

void initStack(struct stack *allBoards)
{
    int idxColumn=0;
    while(idxColumn<9)
    {
      int idxRow=0;
      while(idxRow<9)
        {
            allBoards->board[idxColumn][idxRow] = NULL;
            idxRow++;
        }
        idxColumn++;
    }
    allBoards->top = -1;
}

void displayStack(struct stack *allBoards)
{
    int idxColumn;
    for(idxColumn=0; idxColumn<9;)
    {
        display(&allBoards->board[idxColumn]);
        idxColumn++;
    }
}

void push(struct stack *allBoards, char* board)
{
    allBoards->top++;
    int idxRow;
    for(idxRow=0;idxRow<9;idxRow++)
    {
        allBoards->board[allBoards->top][idxRow] = board[idxRow];
    }
}

int main()
{
    instructions();

    char board[8];
    int winner = 0;
    char winningPlayer;
    int fullBoard = 0;
    initialize(board);

    struct stack allBoards;
    initStack(&allBoards);

    while(winner == 0 && fullBoard == 0)
    {


      insert(board, 1, 'O');
      push(&allBoards, &board);
      insert(board, 2, 'X');
      push(&allBoards, &board);
      insert(board, 3, 'O');
      push(&allBoards, &board);
      insert(board, 4, 'O');
      push(&allBoards, &board);
      insert(board, 5, 'X');
      push(&allBoards, &board);
      insert(board, 6, 'X');
      push(&allBoards, &board);
      insert(board, 7, 'X');
      push(&allBoards, &board);
      insert(board, 8, 'O');
      push(&allBoards, &board);
      insert(board, 9, 'X');
      push(&allBoards, &board);
      display(board);



      //addMove(board);
      //display(board);
      checkFullBoard(board, &fullBoard);
      checkWinner(board, &winner, &winningPlayer);

    }

    printf("Stack Boards: \n");
    displayStack(&allBoards);

    if(winner == 1 && fullBoard == 0)
    {
      printf("%c Wins\n", winningPlayer);
    }
    else if(winner == 0 && fullBoard == 1)
    {
        printf("Match has Been a Draw\n");
    }
    else if(winner == 1 && fullBoard == 1)
    {
      printf("%c Wins\n", winningPlayer);
    }
    else
    {
        return;
    }


    return 0;
}
