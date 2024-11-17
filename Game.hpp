#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Player.hpp"
#include "Board.hpp"
#include "Tiles.hpp"
#include <vector>



class Game{
    private:
        int numberOfPlayer;
        std::vector<Player> listOfPlayer;
        Board board;
        Tile tile;
        std::vector<std::vector<int>> currentTile;
    public:
        int getNumbersOfPlayer();
        void run();
        void initGamePlayer(int numberOfPlayer);
        void firstTile(int idPlayerBoard);
        void DisplayCurrentTile();
        void rotate90();
        bool canPlaceTile(int centerX, int centerY, int idPlayer);
        void PlaceTile(int centerX, int centerY, int idPlayer);
        Game();
        ~Game();

    };

int Game::getNumbersOfPlayer(){
    return numberOfPlayer;
}

void Game::firstTile(int idPlayerBoard) {
    int column;
    int line;
    std::cout << "Ou voulez-vous commencer ? ";
    std::cout << "La colonne : ";
    std::cin >> column;
    std::cout << "La ligne : ";
    std::cin >> line;
    board.board[line][column] = idPlayerBoard;
}


void Game::run() {
    int tour = 0;
    bool canPlace;
    board.displayBoard(listOfPlayer);
    while (tour < 9 ){
        for ( int player = 0 ; player < numberOfPlayer; player++){ //chaque tour des player
            currentTile = tile.GetTiles()[0];
            DisplayCurrentTile();
            board.displayBoard(listOfPlayer);
            int x;
            std::cin >> x;
            int y;
            std::cin >> y;
            canPlace = canPlaceTile(x, y, listOfPlayer[player].getIdPlayer());
            if (canPlace)
                PlaceTile(x, y, listOfPlayer[player].getIdPlayer());
        }
        
        tour += 1;
    }
}


Game::Game() {
    std::cout<< "Bienvenue dans ce jeu ! Combien de joueurs etes vous ? ";
    std::cin >> numberOfPlayer ;
    board = Board(numberOfPlayer);
    initGamePlayer(numberOfPlayer);
    tile = Tile();
}

void Game::DisplayCurrentTile()
{
    for (const auto& line : currentTile) {  // Utiliser 'const auto&' pour éviter la copie
        for (const auto& column : line) {  // Si 'piece' est un vecteur, nous devons l'itérer aussi
            std::cout << column;  // Afficher chaque valeur de l'élément
        }
        std::cout << std::endl;
    }
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

void Game::rotate90() {
    int size = currentTile.size();
    std::vector<std::vector<int>> rotated(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rotated[j][size - i - 1] = currentTile[i][j];
        }
    }
    currentTile = rotated;
}

bool Game::canPlaceTile(int centerX, int centerY, int idPlayer) {
    int size = currentTile.size();
    int boardHeight = board.board.size();
    int boardWidth = board.board[0].size();
    bool touchesIdPlayer = false;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // récupere l'index sur le tableau du coté haut gauche
            int x = centerX + (i - size / 2); // haut
            int y = centerY + (j - size / 2); // gauche

            if (currentTile[i][j] != 0) {
                if (x < 0 || x >= boardHeight || y < 0 || y >= boardWidth) {
                    return false;
                }

                if (board.board[x][y] == 1 || (board.board[x][y] >= 10 && board.board[x][y] != idPlayer)) { // verifie si case est deja occupée par une autre forme ou par un id player different de celui du player actuel
                    return false;
                }

                if ((x + 1 < boardHeight && board.board[x + 1][y] == idPlayer) || 
                    (x - 1 >= 0 && board.board[x - 1][y] == idPlayer) ||          
                    (y + 1 < boardWidth && board.board[x][y + 1] == idPlayer) ||  
                    (y - 1 >= 0 && board.board[x][y - 1] == idPlayer)) { // verifie si adjacent quelque part
                    touchesIdPlayer = true;
                }

                if ((x + 1 < boardHeight && board.board[x + 1][y] >= 10 && board.board[x + 1][y] != idPlayer) ||
                    (x - 1 >= 0 && board.board[x - 1][y] >= 10 && board.board[x - 1][y] != idPlayer) ||
                    (y + 1 < boardWidth && board.board[x][y + 1] >= 10 && board.board[x][y + 1] != idPlayer) ||
                    (y - 1 >= 0 && board.board[x][y - 1] >= 10 && board.board[x][y - 1] != idPlayer)) { // verifie si un des adjacent est un adversaire en prenant en compte les cas d'erreur
                    return false;
                }
            }
        }
    }

    return touchesIdPlayer;
}

void Game::PlaceTile(int centerX, int centerY, int idPlayer) {
    int size = currentTile.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int x = centerX + (i - size / 2);
            int y = centerY + (j - size / 2);

            if (currentTile[i][j] != 0) {
                board.board[x][y] = idPlayer;
            }
        }
    }
}


Game::~Game() {

}

#endif // GAME_H_INCLUDED
