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
        Game();
        ~Game();

    };

int Game::getNumbersOfPlayer(){
    return numberOfPlayer;
}

Game::Game() {
    std::cout<< "Bienvenue dans ce jeu ! Combien de joueurs etes vous ? ";
    std::cin >> numberOfPlayer ;
    board = Board(numberOfPlayer);

    for (int i = 0 ; i < numberOfPlayer; i++)
    {
        Player player;
        listOfPlayer.push_back(player);
        std::cout << player.getPlayerName() << " bien ajouter a la liste des joueurs\n";
    }
}

Game::~Game() {

}

#endif // GAME_H_INCLUDED
