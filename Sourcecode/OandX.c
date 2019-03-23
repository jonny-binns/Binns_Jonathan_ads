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


void initialize(char* board)
{
      int idx;
      for(idx=0; idx < 9; idx++)
      {
          board[idx] = NULL;
      }
}

void display(char* board)
{
    printf("\n\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[0], board[1], board[2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[3], board[4], board[5]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[6], board[7], board[8]);
    return;
}

void insert(char* board, int pos, char move)
{
    int idx;
    if(move == 'X' || move == 'O')
    {
        for(idx = 8; idx>= pos; idx--)
        {
            board[idx] = board[idx];
        }
            board[idx] = move;
    }
    else
    {
        printf("Error: Invalid Character\n");
        return;
    }
}

void addMove(char* board)
{
    int position;
    char move;

    printf("Enter a position and a move: ");
    scanf("%d%c", &position, &move);
    printf("\n");

    if(board[position-1] == NULL)
    {
		    insert(board, position, move);
        display(board);
    }
    else
    {
        printf("Error: Space Already Taken \n");
        return;
    }
}

void checkWinner(char* board, int* winner, char* winningPlayer)
{
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
    {
        *winner = 1;
        *winningPlayer = 'X';
    }
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
    {
        *winner = 1;
        *winningPlayer = 'O';
    }
    else
    {
        *winner = 0;
    }
}

void checkFullBoard(char* board, int* fullBoard)
{
      int idx;
      int movesMade = 0;


      for(idx=0; idx<9; idx++)
      {
          if(board[idx] != NULL)
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
        display(allBoards->board[idxColumn]);
        idxColumn++;
    }
}

void push(struct stack *allBoards, char* board)
{
    //printf("%d\n", allBoards->top);
    allBoards->top++;
    int idxRow;
    for(idxRow=0;idxRow<9;idxRow++)
    {
        allBoards->board[allBoards->top][idxRow] = board[idxRow];
    }
}

void pop(struct stack *allBoards, char *board)
{
    int idxRow;
    allBoards->top--;
    for(idxRow=0;idxRow<9;idxRow++)
    {
        board[idxRow] = allBoards->board[allBoards->top][idxRow];
    }
    display(board);
    //allBoards->top--;
}

void writeFile(struct stack *allBoards)
{
      FILE * file;
      file = fopen("game.txt", "w");
      int idxColumn;

      fprintf(file, "Game test\n");
      for(idxColumn = 0; idxColumn<9; idxColumn++)
      {
          fprintf(file, "Board %d\n", idxColumn);
          fprintf(file, "\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][0], allBoards->board[idxColumn][1], allBoards->board[idxColumn][2]);
          fprintf(file, "\t\t\t--------------\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][3], allBoards->board[idxColumn][4], allBoards->board[idxColumn][5]);
          fprintf(file, "\t\t\t--------------\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][6], allBoards->board[idxColumn][7], allBoards->board[idxColumn][8]);
          fprintf(file, "\n");
      }
      fclose(file);
}

void readFile()
{
    FILE * file;
    char s;

    file = fopen("game.txt", "r");

    if(file==NULL)
    {
        printf("Cant open file\n");
    }
    else
    {
        while(s!=EOF)
        {
            s = getc(file);
            printf("%c", s);
        }
    }
    fclose(file);
}

int main()
{
    char board[8];
    struct stack allBoards;
    int winner = 0;
    char winningPlayer;
    int fullBoard = 0;
    int mainMenu = 0;
    int gameMenu = 0;
    initialize(board);
    initStack(&allBoards);

    printf("****MAIN MENU****\n");
    printf("To See Instructions, Enter 1.\n");
    printf("To Play The Game, Enter 2.\n");
    printf("To Replay An Old Game. Enter 3\n");
    printf("To Exit Enter Any Other Character\n");
    scanf("%d", &mainMenu);

    if(mainMenu == 1)
    {
        instructions();
        printf("****MAIN MENU****\n");
        printf("To See Instructions, Enter 1.\n");
        printf("To Play The Game, Enter 2.\n");
        printf("To Replay An Old Game. Enter 3\n");
        printf("To Exit Enter Any Other Character\n");
        scanf("%d", &mainMenu);
    }

    if(mainMenu == 2)
    {
        while(winner == 0 && fullBoard == 0)
        {
            printf("****GAME MENU****\n");
            printf("To Add A Move, Press 1\n");
            printf("To Undo A Move, Press 2\n");
            printf("To See The Instructions, Press 3\n");
            scanf("%d", &gameMenu);

            if(gameMenu == 1)
            {
                addMove(board);
                push(&allBoards, board);
                //display(board);
                checkFullBoard(board, &fullBoard);
                checkWinner(board, &winner, &winningPlayer);
            }
            else if(gameMenu == 2)
            {
                pop(&allBoards, board);
            }
            else if(gameMenu == 3)
            {
                instructions();
            }
            else
            {
                return;
            }

        }

        if(winner == 1 && fullBoard == 0)
        {
            printf("%c Wins\n", winningPlayer);
            writeFile(&allBoards);
        }
        else if(winner == 0 && fullBoard == 1)
        {
            printf("Match has Been a Draw\n");
            writeFile(&allBoards);
        }
        else if(winner == 1 && fullBoard == 1)
        {
            printf("%c Wins\n", winningPlayer);
            writeFile(&allBoards);
        }
        else
        {
          return;
        }
    }

    if(mainMenu == 3)
    {
        readFile();
    }
    else
    {
      return;
    }

    return 0;
}
