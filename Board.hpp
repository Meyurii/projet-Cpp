#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Game.hpp"
#include <vector>


class Board{
    private:
        int columns;
        int lines;
        std::vector<std::vector<int>> board;
    public:
        Board();
        Board(int numbersOfPlayers);
        ~Board();
        void initBoard(int numbersOfPlayer);
        void displayBoard();
};

Board::Board() {
 
}

Board::Board(int numbersOfPlayers) {
    initBoard(numbersOfPlayers);
}

void Board::initBoard(int numbersOfPlayer){
    if (numbersOfPlayer <= 1){
        std::cout << "Pas assez de joueurs. 2 joueurs sont necessaire. ";
    }
    else if ((numbersOfPlayer >= 2) && (numbersOfPlayer <=4)){
        columns = 20;
        lines = 20;
    }else if ((numbersOfPlayer >= 5) && (numbersOfPlayer <= 9)){
        columns = 30;
        lines = 30;
    }else {
        std::cout << "Trop de joueurs";
    }
    board.resize(columns, std::vector<int>(lines, 0));
}

void Board::displayBoard(){
    for(int line = 0; line < lines; line++){
        for(int column = 0; column < columns; column++){
            std::cout << board[line][column];
        }
        std::cout << "\n";
    }
}

Board::~Board(){
}



#endif // BOARD_H_INCLUDED
