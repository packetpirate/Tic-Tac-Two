/**
* This file contains the class definition of the constructor, destructor, and functions for the Board class.
* Author - Darin Beaudreau
* Last Update - 09/19/2011
**/

#include "Board.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Board::Board() {
    // Set each position on the game board to 0.
    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < boardSize;j++) {
            gameBoard[i][j] = 0;
        }
    }
}
Board::~Board() {

}

void Board::showBoard() {
    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < boardSize;j++) {
            if(gameBoard[i][j] == PLAYER_ONE) {
                cout << "O";
            } else if(gameBoard[i][j] == PLAYER_TWO) {
                cout << "X";
            } else {
                cout << "*";
            }

            if(j < (boardSize - 1)) {
                cout << " ";
            }
        }
        if(i < (boardSize - 1)) {
            cout << endl;
        }
    }
    cout << endl;
}

void Board::setPos(int x, int y, int value) {
    int xPos = x - 1;
    int yPos = y - 1;

    gameBoard[xPos][yPos] = value;
}

int Board::winner() {
    bool filled = true;

    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < boardSize;j++) {
            if(gameBoard[i][j] == 0) {
                filled = false;
            }
        }
    }

    // Check if Player One has won.
    if(match( 0,0 , 0,1 , 0,2 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 1,0 , 1,1 , 1,2 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 2,0 , 2,1 , 2,2 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 0,0 , 1,0 , 2,0 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 0,1 , 1,1 , 2,1 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 0,2 , 1,2 , 2,2 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 0,0 , 1,1 , 2,2 , PLAYER_ONE)) {
        return PLAYER_ONE;
    } else if(match( 0,2 , 1,1 , 2,0 , PLAYER_ONE)) {
        return PLAYER_ONE;
    }

    // Check if Player Two has won.
    if(match( 0,0 , 0,1 , 0,2 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 1,0 , 1,1 , 1,2 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 2,0 , 2,1 , 2,2 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 0,0 , 1,0 , 2,0 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 0,1 , 1,1 , 2,1 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 0,2 , 1,2 , 2,2 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 0,0 , 1,1 , 2,2 , PLAYER_TWO)) {
        return PLAYER_TWO;
    } else if(match( 0,2 , 1,1 , 2,0 , PLAYER_TWO)) {
        return PLAYER_TWO;
    }

    // If no winner has been found, check to see if the board is full. If it is, it's a tie.
    if(filled) {
        return DRAW;
    }

    return NONE;
}

void Board::resetBoard() {
    // Set each position on the game board to 0.
    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < boardSize;j++) {
            gameBoard[i][j] = 0;
        }
    }
}

bool Board::occupied(int x, int y) {
    int xPos = x - 1;
    int yPos = y - 1;

    if(gameBoard[xPos][yPos] != NONE) {
        return true;
    } else {
        return false;
    }
}

bool Board::match(int xOne, int yOne, int xTwo, int yTwo, int xThree, int yThree, int player) {
    if((gameBoard[xOne][yOne] == player)&&(gameBoard[xTwo][yTwo] == player)&&(gameBoard[xThree][yThree] == player)) {
        return true;
    } else {
        return false;
    }
}
