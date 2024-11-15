#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Game.hpp"
#include <vector>
#include <cstdlib>
#include <utility>
#include <math.h>

class Board{
    private:
        int columns;
        int lines;
    public:
        std::vector<std::vector<int>> board;
        Board();
        Board(int numbersOfPlayers);
        ~Board();
        void initBoard(int numbersOfPlayer);
        void displayBoard();
        std::pair<int,int> randomNumber();
        void implementeCaseBonus(int numbersOfPlayer);
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
    board.implementeCaseBonus(numbersOfPlayer);
}

std::pair<int, int> Board::randomNumber() {
    int randomColumn = 2 + rand() % (this->columns - 3);  // Entre 2 et columns-2
    int randomLine = 2 + rand() % (this->lines - 3);      // Entre 2 et lines-2
    return std::make_pair(randomColumn, randomLine);
}


void Board::implementeCaseBonus(int numbersOfPlayer){
    int numberEchange = ceil(numbersOfPlayer * 1.5);
    for (int i  = 0 ; i < numberEchange ; i++){ // échange
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 2;
    }
    numberEchange = ceil(numbersOfPlayer * 0.5);
    for (int i  = 0 ; i < numberEchange ; i++){ // cailloux
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 3;
    }
        numberEchange = ceil(numbersOfPlayer * 1);
    for (int i  = 0 ; i < numberEchange ; i++){ // vol
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 4;  //peut etre opti grace au liste
    }
    
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
