#pragma once

class TicTacToeGame {
public:
	TicTacToeGame();
	void playGame();									// Contains the game loop
private:
	char board[3][3];

	int getXCoord();									// Gets the X coordinate from the user
	int getYCoord();									// Gets the Y coordinate from the user
	bool placeMarker(int x, int y, char currentPlayer);	// Places a marker at the entered coordinate if it's empty
	bool checkForVictory(char currentPlayer);			// Checks to see if either player has won the game
	void clearBoard();									// Empties the board
	void printBoard();									// Prints the board to the screen
};