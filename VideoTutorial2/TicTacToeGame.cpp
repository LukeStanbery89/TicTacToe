#include "TicTacToeGame.h"
#include <iostream>

using namespace std;

// CONSTRUCTOR:
TicTacToeGame::TicTacToeGame() {
}

// PUBLIC:
void TicTacToeGame::playGame() {
	char player1 = 'X';
	char player2 = 'Y';

	char currentPlayer = 'X';
	bool isDone = false;

	int x, y;
	int turn = 0;

	clearBoard();	// Clear the board

	while(!isDone) {
		printBoard();

		x = getXCoord();
		y = getYCoord();

		if(!placeMarker(x, y, currentPlayer)) {
			cout << "That spot is occupied!\n";
		} else {
			turn++;

			if(checkForVictory(currentPlayer)) {
				cout << "The game is over! Player " << currentPlayer << " wins!\n";
				isDone = true;
			} else if(turn == 9) {
				cout << "Tied game!";
				isDone = true;
			} else {
				// Switch players
				if(currentPlayer == player1) {
					currentPlayer = player2;
				} else {
					currentPlayer = player1;
				}
			}
		}

	}
}

// PRIVATE:
int TicTacToeGame::getXCoord() {
	bool isInputBad = true;
	int x;

	while(isInputBad) {
		cout << "Enter the X coordinate: ";
		cin >> x;

		if(x < 1 || x > 3) {
			cout << "Invalid Coordinate!\n";
		} else {
			isInputBad = false;
			return x - 1;
		}
	}
}

int TicTacToeGame::getYCoord() {
	bool isInputBad = true;
	int y;

	while(isInputBad) {
		cout << "Enter the Y coordinate: ";
		cin >> y;

		if(y < 1 || y > 3) {
			cout << "Invalid Coordinate!\n";
		} else {
			isInputBad = false;
			return y - 1;
		}
	}
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) {
	if(board[y][x] != ' ') {
		return false;
	}

	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory(char currentPlayer) {
	// Check the board rows
	for(int i = 0; i < 3; i++) {
		if(board[i][1] == currentPlayer && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;	// We won!
		}
	}

	// Check the board columns
	for(int i = 0; i < 3; i++) {
		if(board[0][i] == currentPlayer && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;	// We won!
		}
	}

	// Check top left diagonal
	if(board[0][0] == currentPlayer && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return true;	// We won!
	}

	// Check the top right diagonal
	if(board[2][0] == currentPlayer && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
		return true;	// We won!
	}

	return false;	// No one won...
}

void TicTacToeGame::clearBoard() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToeGame::printBoard() {
	cout << endl;
	cout << " |1 2 3|\n";
	for(int i = 0; i < 3; i++) {
		cout << " -------\n";
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	cout << " -------\n";
}