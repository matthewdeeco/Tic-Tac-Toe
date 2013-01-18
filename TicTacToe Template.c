/*
 *  Machine Problem 1 Template
 *  Tic-Tac-Toe
 *  CS180 Artificial Intelligence
 *  Tristan M. Basa
 *  Department of Computer Science 
 *  University of the Philippines, Diliman
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define PLAYER1 'x'
#define PLAYER2 'o'
#define BLANK   '-'

char **initboard(char *board[]) {
   int i,j;
   
   for (i=0; i<3; i++) 
      for (j=0; j<3; j++)
	     board[i][j]=BLANK;

   return board;
}

void displayboard(char *board[]) {
   int i,j;
   
   printf("\n");
   for (i=0; i<3; i++) {
      for (j=0; j<3; j++)
	     printf(" %c ",board[i][j]);
	  printf("\n");
   }
   printf("\n");
}

char checkwin(char *board[],char piece) {
   int i,j;
   
   for (i=0; i<3; i++)
      if ((board[i][0]==piece && board[i][1]==piece && board[i][2]==piece) || (board[0][i]==piece && board[1][i]==piece && board[2][i]==piece)) 
	     return piece;		// piece wins
		 
   if (board[1][1]==piece && ((board[0][0]==piece && board[2][2]==piece) || (board[0][2]==piece && board[2][0]==piece)))
      return piece;         // piece wins
	  	  
   for (i=0; i<3; i++)
	  for (j=0; j<3; j++)
		 if (board[i][j]==BLANK)
			return BLANK;          //there are still blank squares, game is not yet done
			   
   return ' '; /* Tie */
}

char **human_move(char **board,char piece) {
   int x,y,valid;
   
   valid=0;
   do {	  
	  printf("\nEnter your move (x,y): ");
	  scanf("%i,%i",&x,&y);
	  if (x<4 && x>0 && y>0 && y<4)
		 if (board[x-1][y-1]==BLANK)
            valid=1;
			   
	  if (!valid) {
         printf("\nINVALID MOVE. TRY AGAIN.\n");
	     displayboard(board);
	  }   
   } while (!valid);
   
   board[x-1][y-1]=piece;
   
   return board;
}

int computer_move(char **board,char piece1,char piece2) {

   /*
	  Your code goes here.
      Calculate the computer's move using the minimax algorithm (with alpha-beta pruning) discussed in class.
	
	  x=? 
	  y=?
	
	  board[x][y]=piece1; //computer's move
	  
   */
   
   return 1; //this means the computer made a move (computer always has to make a move, no need to change this line)
}

int main()
{
   int i,j;
   char again[2],winner,**board;
   
   board=(char**)malloc(sizeof(char*)*3);
   for (i=0; i<3; i++)
      board[i]=(char*)malloc(sizeof(char)*3);
   
   printf("\nWelcome to a game of Tic-Tac-Toe!\n");   
   do {
      board=initboard(board);
	  displayboard(board);
      do {
		 board=human_move(board,PLAYER1);
		 displayboard(board);
		 winner=checkwin(board,PLAYER1);
		 if (winner!=PLAYER1 && winner!=' ') {
		    if (computer_move(board,PLAYER2,PLAYER1))
			   winner=checkwin(board,PLAYER2);
            else
                printf("\nComputer passed\n");
		    displayboard(board);
		 }
	  } while (winner==BLANK);
	  
	  if (winner!=' ')
	     printf("THE WINNER IS %c!\n",winner);
	  else
	     printf("IT'S A TIE.\n");
		 
	  printf("\nPlay again (y)?: ");
	  scanf("%s",again);
   } while(again[0]=='y');

   for (i=0; i<3; i++)
      free(board[i]);
   free(board);
   
   printf("\nThank you for playing.\n\n");
   return 0;
}

