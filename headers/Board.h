#ifndef BOARD_H
#define BOARD_H

/**
* This header file contains the class declaration for the Tic Tac Two board.
* Author - Darin Beaudreau
* Last Update - 09/19/2011
**/

const int boardSize = 3;

enum players { NONE , PLAYER_ONE , PLAYER_TWO , DRAW };

class Board {
    public:
        Board();
        ~Board();

        void showBoard();

        /*
         Set the given position to a certain value.
         The above enumerator should be used for the value parameter.
         The X coordinate and Y coordinate passed will be reduced by 1 to adhere to the base 0 index standard of arrays.
        */
        void setPos(int x, int y, int value);

        // Will return 0 if there is no winner yet, 1 if Player One has won, 2 if Player Two has won, and 3 if it is a tie.
        int winner();

        // Resets the board to 0's.
        void resetBoard();



        // This function will return false only if the specified coordinates do not contain a player token yet.
        bool occupied(int x, int y);
    private:
        int gameBoard[boardSize][boardSize];

        /*
         Checks if the three positions passed as parameters have the same player token. If so, it returns true. Otherwise, false.
         The above enumerator should be used for the player parameter.
        */
        bool match(int xOne, int yOne, int xTwo, int yTwo, int xThree, int yThree, int player);
};

#endif // BOARD_H
