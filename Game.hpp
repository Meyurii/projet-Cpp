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
        Player posibleWinner;
        std::vector<int> exchangeCoupons;
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
        void displayTiles();
        void printPossiblePositions(int idPlayer);
        int getBiggestSquare(int idPlayer);
        int getBiggestPlace(int idPlayer);
        void Winner();
        bool isStoneSquareActivated(int x, int y, int idPlayer);
        void placeStoneTile();
        void initExchangeCoupons();
        bool useExchangeCoupon(int playerId);
        void reorganizeTiles(int chosenTileIndex);
        
    };

int Game::getNumbersOfPlayer(){
    return numberOfPlayer;
}

void Game::firstTile(int idPlayerBoard) {
    int column;
    int line;
    board.displayBoard(listOfPlayer);
    std::cout << "Ou voulez-vous commencer ? ";
    std::cout << "La colonne : ";
    std::cin >> column;
    std::cout << "La ligne : ";
    std::cin >> line;
    board.board[line][column] = idPlayerBoard;
}

void Game::displayTiles() {
    std::cout << "Tuile actuelle :" << std::endl;
    DisplayCurrentTile();
    int size = tile.GetTiles().size();
    std::cout << "\nProchaines tuiles :" << std::endl;
    for (int i = 1; i < std::min(6, size); ++i) {
        for (const auto& row : tile.GetTiles()[i]) {
            for (int cell : row) {
                std::cout << (cell ? "#" : " ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void Game::run() {
    // placement starting tuiles
    for (int i = 0; i < numberOfPlayer; i++) {
        firstTile(listOfPlayer[i].getIdPlayer());
    }

    board.displayBoard(listOfPlayer);
    char answer;
    int tour = 0;
    bool canPlace;
    initExchangeCoupons();
    while (tour < 9) {
        std::cout << "tour : " << tour << std::endl;
        for (int player = 0; player < numberOfPlayer; player++) {
            std::cout << "player : " << listOfPlayer[player].getPlayerName() << std::endl;
            currentTile = tile.GetTiles()[0];
            displayTiles(); // affichage tuile actuelle et prochaines tuiles
            
            char exchangeAnswer;
            std::cout << "Voulez-vous utiliser un coupon echange? (nombre de coupons echange " 
                      << exchangeCoupons[player] << ") (y/n) ";
            std::cin >> exchangeAnswer;

            if (exchangeAnswer == 'y' && useExchangeCoupon(player)) {
                displayTiles();
                
                int chosenTileIndex;
                std::cout << "Choisissez une tuile parmi les 5 prochaines (1-5): ";
                std::cin >> chosenTileIndex;
                chosenTileIndex = std::max(1, std::min(5, chosenTileIndex)) - 1; 

                reorganizeTiles(chosenTileIndex); 
                currentTile = tile.GetTiles()[0]; 
                
                std::cout << "Tuile actuelle et les prochaines tuiles apres reorganisation :\n";
                displayTiles(); // Rremontrer les tuiles apres coupon 
            }

            std::cout << "Voulez-vous modfier la piece ? (y/n) ";
            std::cin >> answer;
            if (answer == 'y') {
                std::cout << "Pour tourner a droite taper d, pour la retourner taper r, pour la tourner a gauche taper g: ";
                std::cin >> answer;
                if (answer == 'd') {
                    rotate90();
                } else if (answer == 'r') {
                    rotate90();
                    rotate90();
                } else {
                    rotate90();
                    rotate90();
                    rotate90();
                }
            }

            printPossiblePositions(listOfPlayer[player].getIdPlayer());
            int x, y;
            std::cout << listOfPlayer[player].getPlayerName() << ", entrer les coordonnees pour placer votre tuile en x: ";
            std::cin >> x;
            std::cout << "Et en y: ";
            std::cin >> y;

            canPlace = canPlaceTile(x, y, listOfPlayer[player].getIdPlayer());
            if (canPlace) {
                PlaceTile(x, y, listOfPlayer[player].getIdPlayer());
                board.displayBoard(listOfPlayer);

                tile.popFirstTile(); 
                if (!tile.GetTiles().empty()) {
                    currentTile = tile.GetTiles()[0]; 
                } else {
                    std::cout << "Plus de tuile disponible.\n";
                }
            } else {
                std::cout << "Placement invalide. Reesayer.\n";
                player--; 
            }
        }
        tour += 1;
    }
    std::cout << "fin de la partie" << std::endl;
    Winner();
    std::cout << "Le gagnant est " << posibleWinner.getPlayerName() << " ! Felicitation !";
}



void Game::printPossiblePositions(int idPlayer) {
    int boardHeight = board.board.size();
    int boardWidth = board.board[0].size();
    std::cout << "Voici les positions possibles: " << idPlayer << ":\n";

    for (int x = 0; x < boardHeight; ++x) {
        for (int y = 0; y < boardWidth; ++y) {
            if (canPlaceTile(x, y, idPlayer)) {
                std::cout << "Position: (" << x << ", " << y << ")\n";
            }
        }
    }
}

bool Game::isStoneSquareActivated(int x, int y, int idPlayer) {
    if (x < 0 || x >= board.board.size() || y < 0 || y >= board.board[0].size()) 
        return false;

    // verifier si la cas est entourer
    return (x > 0 && board.board[x - 1][y] == idPlayer) &&
           (x < board.board.size() - 1 && board.board[x + 1][y] == idPlayer) &&
           (y > 0 && board.board[x][y - 1] == idPlayer) &&
           (y < board.board[0].size() - 1 && board.board[x][y + 1] == idPlayer);
}

void Game::placeStoneTile() {
    int x, y;

    do {
        std::cout << "Choose a location to place your stone tile (x y): ";
        std::cin >> x >> y;
    } while (x < 0 || x >= board.board.size() || y < 0 || y >= board.board[0].size() || board.board[x][y] != 0);

    board.board[x][y] = -1; 
    std::cout << "Stone tile placed at (" << x << ", " << y << ")." << std::endl;
}

void Game::initExchangeCoupons() {
    exchangeCoupons.resize(numberOfPlayer, 1); // chaque joueur commence avec un coupon 
}

bool Game::useExchangeCoupon(int playerId) {
    if (exchangeCoupons[playerId] > 0) {
        exchangeCoupons[playerId]--;
        return true;
    }
    return false;
}

void Game::reorganizeTiles(int chosenTileIndex) {
    std::vector<std::vector<std::vector<int>>> tilesQueue = tile.GetTiles();
    std::vector<std::vector<int>> chosenTile = tilesQueue[chosenTileIndex];
    
    tilesQueue.erase(tilesQueue.begin() + chosenTileIndex);
    tilesQueue.insert(tilesQueue.begin(), chosenTile);
    
    for (int i = 1; i < chosenTileIndex; i++) {
        tilesQueue.push_back(tilesQueue[1]);
        tilesQueue.erase(tilesQueue.begin() + 1);
    }
    
    tile.SetTiles(tilesQueue);
}
Game::Game() {
    std::cout << "Bienvenue dans ce jeu ! Combien de joueurs etes vous ? ";
    std::cin >> numberOfPlayer;
    board = Board(numberOfPlayer);
    initGamePlayer(numberOfPlayer);
    tile = Tile();
    posibleWinner = Player();
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



void Game::initGamePlayer(int numberOfPlayer) {
    for (int i = 0; i < numberOfPlayer; i++) {
        Player player(i);
        listOfPlayer.push_back(player);
        std::cout << player.getPlayerName() << " a été ajouté à la liste des joueurs.\n";
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

                if (board.board[x][y] == 1 || (board.board[x][y] >= 10)) { // verifie si case est deja occupée par une autre forme ou par un id player different de celui du player actuel
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

void Game::Winner(){
    posibleWinner = listOfPlayer[0];
    int idPosibleWinner = listOfPlayer[0].getIdPlayer();
    listOfPlayer[0].setSquareMax(getBiggestSquare(idPosibleWinner));
    for (int player = 0; player < listOfPlayer.size(); player++){
        int idPlayer = listOfPlayer[player].getIdPlayer();
        listOfPlayer[player].setSquareMax(getBiggestSquare(idPlayer));
        if(listOfPlayer[player].getSquareMax() > posibleWinner.getSquareMax()){
            posibleWinner = listOfPlayer[player];
            idPosibleWinner = idPlayer;
        } else if (listOfPlayer[player].getSquareMax() == posibleWinner.getSquareMax()){
            listOfPlayer[player].setMaxSize(getBiggestPlace(idPlayer));
            posibleWinner.setMaxSize(getBiggestPlace(idPosibleWinner));
            if(listOfPlayer[player].getMaxSize() > posibleWinner.getMaxSize()){
                posibleWinner = listOfPlayer[player];
                idPosibleWinner = idPlayer;
            }
        }
    }
}

int Game::getBiggestSquare(int idPlayer){
    int squarePosX;
    int squareY;
    int sizeOfSquare = 1;
    int sizeOfTempSquare = 0;
    bool coorectSquare = true;
    for(int line = 0; line < board.board.size(); line++){
        for(int colonne = 0; colonne < board.board.size(); colonne++){
            if(board.board[line][colonne] == idPlayer){
                do
                {
                    sizeOfTempSquare = sizeOfSquare;
                    if (line + sizeOfSquare >= board.board.size() || colonne + sizeOfSquare >= board.board[0].size()) {
                        coorectSquare = false;
                        break;
                    }
                    coorectSquare = true;
                    for (int tempLine = 0 ; tempLine != sizeOfSquare ; tempLine++) {
                        for (int tempColonne = 0 ; tempColonne != sizeOfSquare ; tempColonne++) {
                            if (board.board[line + tempLine][colonne + tempColonne] != idPlayer)
                                coorectSquare = false;
                        }
                    }
                    if (coorectSquare == true) {
                        sizeOfSquare += 1;
                    }
                } while (sizeOfTempSquare < sizeOfSquare);
            }
        }
    }
    return sizeOfSquare;
}

int Game::getBiggestPlace(int idPlayer){
    int maxSize;
    for(int line = 0; line < board.board.size(); line++){
        for(int colonne = 0; colonne < board.board.size(); colonne++){
            if(board.board[line][colonne] == idPlayer){
                maxSize += 1;
            }
        }
    } 
    return maxSize;   
}
Game::~Game() {

}

#endif // GAME_H_INCLUDED