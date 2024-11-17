#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Game.hpp"
#include <vector>
#include <cstdlib>
#include <utility>
#include <math.h>
#include <iomanip> 

class Board {
private:
    int columns;
    int lines;

public:
    std::vector<std::vector<int>> board;
    Board();
    Board(int numbersOfPlayers);
    ~Board();
    void initBoard(int numbersOfPlayer);
    void displayBoard(std::vector<Player> listOfPlayer);
    std::pair<int, int> randomNumber();
    void implementeCaseBonus(int numbersOfPlayer);
};

Board::Board() {}

Board::Board(int numbersOfPlayers) {
    initBoard(numbersOfPlayers);
}

void Board::initBoard(int numbersOfPlayer) {
    if (numbersOfPlayer <= 1) {
        std::cout << "Pas assez de joueurs. 2 joueurs sont necessaire. ";
    } else if ((numbersOfPlayer >= 2) && (numbersOfPlayer <= 4)) {
        columns = 20;
        lines = 20;
    } else if ((numbersOfPlayer >= 5) && (numbersOfPlayer <= 9)) {
        columns = 30;
        lines = 30;
    } else {
        std::cout << "Trop de joueurs";
    }
    board.resize(lines, std::vector<int>(columns, 0));
    implementeCaseBonus(numbersOfPlayer);
}

std::pair<int, int> Board::randomNumber() {
    int randomColumn = 2 + rand() % (this->columns - 3); // Entre 2 et columns-2
    int randomLine = 2 + rand() % (this->lines - 3);     // Entre 2 et lines-2
    return std::make_pair(randomColumn, randomLine);
}

void Board::implementeCaseBonus(int numbersOfPlayer) {
    int numberEchange = ceil(numbersOfPlayer * 1.5);
    for (int i = 0; i < numberEchange; i++) { // échange
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 2;
    }
    numberEchange = ceil(numbersOfPlayer * 0.5);
    for (int i = 0; i < numberEchange; i++) { // cailloux
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 3;
    }
    numberEchange = ceil(numbersOfPlayer * 1);
    for (int i = 0; i < numberEchange; i++) { // vol
        auto pos = this->randomNumber();
        int x = pos.first;
        int y = pos.second;
        board[y][x] = 4; // peut etre opti grace au liste
    }
}

void Board::displayBoard(std::vector<Player> listOfPlayer) {
    std::cout << "   "; 
    bool isPlayer = false;
    for (int column = 0; column < columns; column++) {
        std::cout << std::setw(3) << column; 
    }
    std::cout << "\n";

    for (int line = 0; line < lines; line++) {
        isPlayer = false;
        std::cout << std::setw(3) << line; 
        for (int column = 0; column < columns; column++) {
            isPlayer = false;
            char cell = '.';
            if (board[line][column] == 2) cell = 'E'; // échange
            else if (board[line][column] == 3) cell = 'C'; // cailloux
            else if (board[line][column] == 4) cell = 'V'; // vol

            for (int playerIndex = 0; playerIndex < listOfPlayer.size(); playerIndex++) {
                if (board[line][column] == listOfPlayer[playerIndex].getIdPlayer()) {
                    std::cout << std::setw(3);
                    listOfPlayer[playerIndex].getColor().showColorizedText("  J");
                    isPlayer = true;
                    break;
                }
            }
            if (isPlayer == false)
                std::cout << std::setw(3) << cell;
        }
        std::cout << "\n";
    }
}

Board::~Board() {}

#endif // BOARD_H_INCLUDED
