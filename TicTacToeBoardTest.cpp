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

TEST(TicTacToeBoardTest, toggleBoard)

{
	TicTacToeBoard myBoard;
	ASSERT_EQ(myBoard.toggleTurn(), O);

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





TEST(TicTacToeBoardTest, getPieceNoPiece)

{

	TicTacToeBoard board;
	Piece result = board.getPiece(0, 0);
	ASSERT_EQ(result, Blank);
}



TEST(TicTacToeBoardTest, getPieceOutofBounds)

{

	TicTacToeBoard board;
	Piece result = board.getPiece(-1, -1);
	ASSERT_EQ(result, Invalid);

}



TEST(TicTacToeBoardTest, draw)

{

	TicTacToeBoard myBoard;
	Piece value = myBoard.getWinner();
	ASSERT_EQ(value, Invalid);

}


