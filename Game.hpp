#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Player.hpp"
#include "Board.hpp"
#include <vector>


class Game{
    private:
        int numberOfPlayer;
        std::vector<Player> listOfPlayer;
        Board board;
    public:
        int getNumbersOfPlayer();
        void run();
        void initGamePlayer(int numberOfPlayer);
        Game();
        void firstTile(int idPlayerBoard);
        ~Game();

    };

int Game::getNumbersOfPlayer(){
    return numberOfPlayer;
}

void Game::firstTile(int idPlayerBoard){
    int column;
    int line;
    std::cout << "Ou voulez-vous commencer ? ";
    std::cout << "La colonne : ";
    std::cin >> column;
    std::cout << "La ligne : ";
    std::cin >> line;
    board.board[line][column] = idPlayerBoard;
}


void Game::run(){
    int tour = 0;
    board.displayBoard();
    while (tour < 9 ){
        for ( int playerTour = 0 ; playerTour < numberOfPlayer; playerTour++){ //chaque tour des player

            
        }
        
        tour += 1;
    }
}


Game::Game() {
    std::cout<< "Bienvenue dans ce jeu ! Combien de joueurs etes vous ? ";
    std::cin >> numberOfPlayer ;
    board = Board(numberOfPlayer);
    initGamePlayer(numberOfPlayer);
}

void Game::initGamePlayer(int numberOfPlayer){
    
    for (int i = 0 ; i < numberOfPlayer; i++)
    {
        Player player(i);
        listOfPlayer.push_back(player);
        std::cout << player.getPlayerName() << " bien ajouter a la liste des joueurs\n";
    }
     for (int i = 0 ; i < numberOfPlayer; i++)
    {
        firstTile(listOfPlayer[i].getIdPlayer());
    }
    
}

Game::~Game() {

}

#endif // GAME_H_INCLUDED
