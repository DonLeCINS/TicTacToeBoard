#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
     turn = X;
  else 
     turn = X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
if (row < 0 || column < 0 || row > BOARDSIZE - 1 || column >  BOARDSIZE - 1) { //out of bounds
     return Invalid; 
  }
else
      {
          if(board[row][column] == Blank)
          {
            board[row][column] = turn;
            toggleTurn();
            return board[row][column];
          }
          else
          {
            return board[row][column];
          }
      }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{

 if (row > BOARDSIZE - 1 || column > BOARDSIZE - 1 || row < 0 || column < 0 ) 
  return Invalid; 
 else
  return board[row][column];
}


/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
for (int a=0;a<3;a++){
	if (board[a][0]==board[a][1] && board[a][0]==board[a][2] && board[a][0] != Blank)
		return board[a][0];
	if (board[0][a]==board[1][a] && board[0][a]==board[2][a] && board[0][a] != Blank)
		return board[0][a];
}
if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0] != Blank)
	return board[0][0];
if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2] != Blank)
	return board[1][1];
	
for(int i = 0; i<3; i++){
    for(int j=0; j<3; j++){
      if (board[i][j] == Blank){
        return Invalid;
      }
  }
}
  return Blank;
}
