/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/



TEST(TicTacToeBoardTest, toggleTurnX)

{
	TicTacToeBoard myBoard;
	Piece thePiece = myBoard.toggleTurn();
	thePiece = myBoard.toggleTurn();
	ASSERT_EQ(thePiece, X);
}




TEST(TicTacToeBoardTest, outOfBounds)

{
	TicTacToeBoard myBoard;
	Piece value = myBoard.placePiece(5, 5);
	ASSERT_EQ(value, Invalid);
}



TEST(TicTacToeBoardTest, getPiece)

{
	TicTacToeBoard myBoard;
	myBoard.placePiece(1, 1);
	Piece value = myBoard.getPiece(1,1);
	ASSERT_EQ(value, X);

}





TEST(TicTacToeBoardTest, getNoPiece)

{
	TicTacToeBoard myBoard;
	Piece result = myBoard.getPiece(0, 0);
	ASSERT_EQ(result, Blank);
}



TEST(TicTacToeBoardTest, getPieceOUT)

{

	TicTacToeBoard myBoard;
	Piece result = myBoard.getPiece(-1, -1);
	ASSERT_EQ(result, Invalid);

}



TEST(TicTacToeBoardTest, draw)

{
	TicTacToeBoard myBoard;
	Piece value = myBoard.getWinner();
	ASSERT_EQ(value, Invalid);
}

TEST(TICTACTOEBOARDTEST, getBlankPiece)
{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.getPiece(1,1), Blank);
}



TEST(TICTACTOEBOARDTEST, placeX)

{
	TicTacToeBoard myBoard;
	myBoard.placePiece(1,1);
	ASSERT_EQ(myBoard.getPiece(1,1), X);
}



TEST(TICTACTOEBOARDTEST, getWinnerVertical)

{
	TicTacToeBoard myBoard;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		myBoard.placePiece(i,1);
		myBoard.toggleTurn();
	}
	ASSERT_EQ(myBoard.getWinner(), X);

}



TEST(TICTACTOEBOARDTEST, getWinnerHorizontal)

{
	TicTacToeBoard myBoard;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		myBoard.placePiece(1,i);
		myBoard.toggleTurn();
	}
	ASSERT_EQ(myBoard.getWinner(), X);
}



TEST(TICTACTOEBOARDTEST, getWinnerDiagonal)

{
	TicTacToeBoard myBoard;
	for (int i = 0; i < BOARDSIZE; i++)

	{
		myBoard.placePiece(i,i);
		myBoard.toggleTurn();
	}
	ASSERT_EQ(myBoard.getWinner(), X);

}