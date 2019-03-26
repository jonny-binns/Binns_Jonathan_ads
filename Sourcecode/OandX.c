#include <stdio.h>
//included for the time generation in writeFile()
#include <time.h>

//function to display the instructions
void instructions()
{
    //prints the instructions
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

//function to initialize the board array
void initialize(char* board)
{
      //variable for the index of the array
      int idx;
      //loops through the array and sets it to null
      for(idx=0; idx < 9; idx++)
      {
          board[idx] = NULL;
      }
}

//function to display the board array
void display(char* board)
{
    printf("\n\n");
    //prints each element of the array in the correct position, and includes the formatting
    printf("\t\t\t  %c | %c  | %c  \n", board[0], board[1], board[2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[3], board[4], board[5]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[6], board[7], board[8]);
    return;
}

//function to insert to the board array
void insert(char* board, int pos, char move)
{
    //variable for the array index
    int idx;
    //input validation to stop any unwanted characters being added
    if(move == 'X' || move == 'O')
    {
        //loops through the array
        for(idx = 8; idx>= pos; idx--)
        {
            board[idx] = board[idx];
        }
            //adds the move to the array
            board[idx] = move;
    }
    else
    {
        //prints error if input validation is failed
        printf("Error: Invalid Character\n");
        return;
    }
}

//fuction to ask the user to add a move
void addMove(char* board)
{
    //creates variable for the position of where the move is made
    int position;
    //creates variable for the value of the position
    char move;

    //asks the user for a position and a move
    printf("Enter a position and a move: ");
    //takes in the input from the keyboard
    scanf("%d%c", &position, &move);
    printf("\n");

    //checks that the specified board position isnt null
    if(board[position-1] == NULL)
    {
        //calls the insert function to add the user input to the board array
		    insert(board, position, move);
        //calls the display function
        display(board);
    }
    else
    {
        //prints an error if the board position is not null
        printf("Error: Space Already Taken \n");
        return;
    }
}

//function to check if there has been a winner
void checkWinner(char* board, int* winner, char* winningPlayer)
{
    //checks if the first three elements are X
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the first three elements are O
    else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the middle three elements are X
    else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the middle three elements are O
    else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the last three elements are X
    else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the last three elements are O
    else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the first 'column' elements are X
    else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the first 'column' elements are O
    else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the middle 'column' elements are X
    else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the middle 'column' elements are O
    else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the final 'column' elements are X
    else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the final 'column' elements are O
    else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the diagonal elements are X
    else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the diagonal elements are O
    else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    //checks if the other diagonal elements are X
    else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to x
        *winningPlayer = 'X';
    }
    //checks if the other diagonal elements are O
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
    {
        //sets the winner variable to 1
        *winner = 1;
        //sets the winning player to O
        *winningPlayer = 'O';
    }
    else
    {
        //else keeps the winner as 0
        *winner = 0;
    }
}

//function to check weather the board is full
void checkFullBoard(char* board, int* fullBoard)
{
      //creates variables to store the index and the number of moves made
      int idx;
      int movesMade = 0;

      //loops through the board
      for(idx=0; idx<9; idx++)
      {
          if(board[idx] != NULL)
          {
              //if the element at the position idx is not null it increases moves made
              movesMade++;
          }
          else
          {
              //if the element at position idx is null return
              return;
          }
      }

      //if the moves made is 9
      if(movesMade == 9)
      {
          //set the full board variable to 1
          *fullBoard = 1;
      }
      else
      {
          //otherwise keep it at 0
          *fullBoard = 0;
      }

      return;
}

//struct for the stack
struct stack
{
      //2d array to store the list of boards
      char board[9][9];
      //int to store the top of the stack
      int top;
};

//fucntion to intitialize the stack
void initStack(struct stack *allBoards)
{
    //int to keep track of the 'layer' of the stack
    int idxColumn=0;
    //while column is less than 9
    while(idxColumn<9)
    {
      //int to loop through the elements in each row
      int idxRow=0;
      //while the row is less than 9
      while(idxRow<9)
        {
            //sets the element = to null
            allBoards->board[idxColumn][idxRow] = NULL;
            //incremenets through the row
            idxRow++;
        }
        //increments through the column
        idxColumn++;
    }
    //sets the top to -1
    allBoards->top = -1;
}

//function to display stack
void displayStack(struct stack *allBoards)
{
    //variable to keep track of layers
    int idxColumn;
    //for the column being less than 9
    for(idxColumn=0; idxColumn<9;)
    {
        //calls my display function to display the elements in that array
        display(allBoards->board[idxColumn]);
        //increments the comumn variable
        idxColumn++;
    }
}

//function to add the board to the top of the stack
void push(struct stack *allBoards, char* board)
{
    //increments the top int in the stack
    allBoards->top++;
    //creates a variable to loop through each row
    int idxRow;
    for(idxRow=0;idxRow<9;idxRow++)
    {
        //loops through each row and sets the elements in the stack to the elements in the boars
        allBoards->board[allBoards->top][idxRow] = board[idxRow];
    }
}


//function to change the board in play with the last board from the stack
void pop(struct stack *allBoards, char *board)
{
    //creates variable to keep track of elements on a row
    int idxRow;
    //decements the top variable of the stack
    allBoards->top--;
    //loops through each element in the 'layer' of the array
    for(idxRow=0;idxRow<9;idxRow++)
    {
        //loops through each rown and sets the elements in the board to the elements in the stack
        board[idxRow] = allBoards->board[allBoards->top][idxRow];
    }
    //displays the board
    display(board);
}

//function to write the stack of all board to a .txt file
void writeFile(struct stack *allBoards)
{
      //creates pointer to the file
      FILE * file;
      //creates a variable to keep track of the column of the stack
      int idxColumn;
      //creates a variable of the number of seconds since 01.01.1970
      time_t seconds;

      //sets seconds to the current time
      seconds = time(NULL);
      //creates a char array to create the fileName
      char fileName[30];
      //adds the time in seconds to game to create the fileName
      sprintf(fileName, "game%lld.txt", seconds);
      //tells the user what the game has been saved as
      printf("Game has been saved as: %s\n", fileName);
      //opens the file in write mode
      file = fopen(fileName, "w");

      //loops through each 'layer' of the stack
      for(idxColumn = 0; idxColumn<9; idxColumn++)
      {
          //writes the board number to the file
          fprintf(file, "Board %d\n", idxColumn);
          //writes the board to the file, including the same formatting as the display function
          fprintf(file, "\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][0], allBoards->board[idxColumn][1], allBoards->board[idxColumn][2]);
          fprintf(file, "\t\t\t--------------\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][3], allBoards->board[idxColumn][4], allBoards->board[idxColumn][5]);
          fprintf(file, "\t\t\t--------------\n");
          fprintf(file, "\t\t\t  %c | %c  | %c  \n", allBoards->board[idxColumn][6], allBoards->board[idxColumn][7], allBoards->board[idxColumn][8]);
          fprintf(file, "\n");
      }
      //closes the file
      fclose(file);
}

//function to display the text from a given game file
void readFile()
{
    //creates a pointer to the file
    FILE * file;
    //creates a character to display whats in the file
    char s;
    //creates a char array to allow the user to enter the filename
    char fileName[30];

    //asks the user to input a game file to be displayed
    printf("Enter The File Name Of The Game You Would Like To Replay (include .txt): ");
    //takes in the user input from the command line
    scanf("%s", fileName);
    //opens the file in read mode
    file = fopen(fileName, "r");
    //validation for if the file pointer returns null
    if(file==NULL)
    {
        printf("Cant open file\n");
    }
    //if the file pointer isnt null
    else
    {
        //while the character isnt the end of file
        while(s!=EOF)
        {
            //gets the char from the file
            s = getc(file);
            //prints the char to the screen
            printf("%c", s);
        }
    }
    //closes the file
    fclose(file);
}


//main method
int main()
{
    //creates the array for the board
    char board[8];
    //creates a stack of all the boards
    struct stack allBoards;
    //creats an int for the winner flag
    int winner = 0;
    //creates a char for the winning player
    char winningPlayer;
    //creates and int for the full board flag
    int fullBoard = 0;
    //creates an int for the main menu choice
    int mainMenu = 0;
    //creates an int for the game menu choice
    int gameMenu = 0;
    //initializes the board
    initialize(board);
    //initializes the stack
    initStack(&allBoards);

    //code for the main menu
    printf("****MAIN MENU****\n");
    printf("To See Instructions, Enter 1.\n");
    printf("To Play The Game, Enter 2.\n");
    printf("To Replay An Old Game. Enter 3\n");
    printf("To Exit Enter Any Other Character\n");
    //takes in the user input from the command line
    scanf("%d", &mainMenu);

    //if the value input is 1
    if(mainMenu == 1)
    {
        //prints the instructions
        instructions();
        //prints the main menu
        printf("****MAIN MENU****\n");
        printf("To See Instructions, Enter 1.\n");
        printf("To Play The Game, Enter 2.\n");
        printf("To Replay An Old Game. Enter 3\n");
        printf("To Exit Enter Any Other Character\n");
        scanf("%d", &mainMenu);
    }
    //if the choice entered is 2
    if(mainMenu == 2)
    {
        //while the winner int and the full board int are 0
        while(winner == 0 && fullBoard == 0)
        {
            //prints the game menu
            printf("****GAME MENU****\n");
            printf("To Add A Move, Press 1\n");
            printf("To Undo A Move, Press 2\n");
            printf("To See The Instructions, Press 3\n");
            //reads in user choice in the game menu
            scanf("%d", &gameMenu);
            //if game menu selection is 1
            if(gameMenu == 1)
            {
                //adds a move to the board
                addMove(board);
                //pushes the board to the stack of all boards
                push(&allBoards, board);
                //checks if the board is full
                checkFullBoard(board, &fullBoard);
                //checks if there has been a winner
                checkWinner(board, &winner, &winningPlayer);
            }
            //if the user inputs 2
            else if(gameMenu == 2)
            {
                //pops the last board from the stack and sets it as the game board that is in play
                pop(&allBoards, board);
            }
            //if the user inputs 3
            else if(gameMenu == 3)
            {
                //displays the instructions
                instructions();
            }
            else
            {
                //else returns
                return;
            }

        }
        //if theres a winner and not a full board
        if(winner == 1 && fullBoard == 0)
        {
            //displays the winnner
            printf("%c Wins\n", winningPlayer);
            //writes to the file
            writeFile(&allBoards);
        }
        //if theres a full board but not a winner
        else if(winner == 0 && fullBoard == 1)
        {
            //prints that match has been a draw
            printf("Match has Been a Draw\n");
            //writes to file
            writeFile(&allBoards);
        }
        //if there is both a winner and a full board
        else if(winner == 1 && fullBoard == 1)
        {
            //prints the winner
            printf("%c Wins\n", winningPlayer);
            //writes to file
            writeFile(&allBoards);
        }
        else
        {
          //else return
          return;
        }
    }
    //if the main menu is 3
    if(mainMenu == 3)
    {
        //reads in a file and prints
        readFile();
    }
    else
    {
      //else return
      return;
    }

    return 0;
}
