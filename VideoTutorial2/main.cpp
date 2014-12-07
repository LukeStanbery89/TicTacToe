#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

int main() {
	char input;
	bool isDone = false;
	TicTacToeGame game;

	while(!isDone) {
		game.playGame();
		cout << "Would you like to play again? (Y/N)";
		cin >> input;
		if(input != 'Y' && input != 'y') {
			isDone = true;
		}
	}

	system("PAUSE");
	return 0;
}
