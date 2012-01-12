/**
* This is a more object-oriented edition of my Tic Tac Toe game from C++ Programming II class.
* Author - Darin Beaudreau
* Last Update - 09/19/2011
* Status: [COMPLETE]
**/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Board.h"

int main(int argc, char** argv) {
    Board * game = new Board();

    bool gameOver = false;
    bool validChoice = false;
    int choice = 0;
    bool playAgain = false;
    bool validTurn = false;
    int turn = PLAYER_ONE;
    int x = 0;
    int y = 0;

    // Main Game Loop
    do {
        while(!gameOver) {
            if(turn == PLAYER_ONE) {
                cout << endl;
                game->showBoard();
                cout << endl;

                do {
                    cout << "Player One's Turn: ";
                    cin >> x >> y;
                    if(((x > 0)&&(x <= 3))&&((y > 0)&&(y <= 3))) {
                        if(!(game->occupied(x, y))) {
                            validTurn = true;
                        } else {
                            cout << "Those coordinates are occupied!" << endl;
                        }
                    } else {
                        cout << "Invalid coordinates. Please try again." << endl;
                    }
                } while(!validTurn);
                game->setPos(x,y,PLAYER_ONE);

                if(game->winner() == PLAYER_ONE) {
                    game->showBoard();
                    cout << "Player One Wins!" << endl;
                    gameOver = true;
                    break;
                } else if(game->winner() == DRAW) {
                    game->showBoard();
                    cout << "The game is a tie!" << endl;
                    gameOver = true;
                    break;
                } else {
                    turn = PLAYER_TWO;
                    validTurn = false;
                }
            } else if(turn == PLAYER_TWO) {
                cout << endl;
                game->showBoard();
                cout << endl;

                do {
                    cout << "Player Two's Turn: ";
                    cin >> x >> y;
                    if(((x > 0)&&(x <= 3))&&((y > 0)&&(y <= 3))) {
                        if(!(game->occupied(x, y))) {
                            validTurn = true;
                        } else {
                            cout << "Those coordinates are occupied!" << endl;
                        }
                    } else {
                        cout << "Invalid coordinates. Please try again." << endl;
                    }
                } while(!validTurn);
                game->setPos(x,y,PLAYER_TWO);

                if(game->winner() == PLAYER_TWO) {
                    game->showBoard();
                    cout << "Player Two Wins!" << endl;
                    gameOver = true;
                    break;
                } else if(game->winner() == DRAW) {
                    game->showBoard();
                    cout << "The game is a tie!" << endl;
                    gameOver = true;
                    break;
                } else {
                    turn = PLAYER_ONE;
                    validTurn = false;
                }
            } else {
                cout << "Error: turn variable encountered unexpected value." << endl;
                gameOver = true;
            }
        }

        gameOver = false;
        validChoice = false;
        playAgain = false;

        do {
            cout << "Would you like to play again? (1 - YES / 2 - NO): ";
            cin >> choice;
            if(choice == 1) {
                playAgain = true;
                validChoice = true;
            } else if(choice == 2) {
                playAgain = false;
                validChoice = true;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while(!validChoice);

        game->resetBoard();
    } while(playAgain);

    return 0;
}
