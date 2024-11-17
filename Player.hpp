#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Color.hpp"
#include <string>
#include <iostream>


class Player{
    private:
        int tileExchange; //Coupon d'échange
        int stone; // Carre cailloux
        int robbery; //Vole la case
        std::string name;
        Color color;
        int idPlayerBoard;
        int squareSize;
        int maxSize;

    public:
        void setMaxSize(int max);
        int getMaxSize();
        void setSquareMax(int max);
        int getSquareMax();
        Player() : tileExchange(0), stone(0), robbery(0), idPlayerBoard(0), squareSize(0), maxSize(0) {};
        Player(int id);
        Player(const Player& other);
        ~Player();
        int getIdPlayer();
        std::string getPlayerName();
        void displayPlayerInfo();
        void show_text(std::string text);
        Color getColor();
};

int Player::getMaxSize(){
    return maxSize;
}

int Player::getSquareMax(){
    return squareSize;
}
void Player::setMaxSize(int max){
    maxSize = max;
}

void Player::setSquareMax(int max){
    squareSize = max;
}

Color Player::getColor() {
    return color;
}

int Player::getIdPlayer(){
        return idPlayerBoard;
 }
Player::Player(int id) {
    std::cout << "Bonjour ! Quel est votre nom de joueur ?" << std::endl;
    std::cin >> name ;
    std::cout << "Tres bien " << name << ". ";
    color.askColor();
    tileExchange = 1;
    stone = 0;
    robbery = 0 ;
    idPlayerBoard = id + 11;

}

Player::Player(const Player& other) {
    name = other.name;
    color = other.color;
    tileExchange = other.tileExchange;
    stone = other.stone;
    robbery = other.robbery;
    idPlayerBoard = other.idPlayerBoard;
    squareSize = other.squareSize;
    maxSize = other.maxSize;
}

std::string Player::getPlayerName(){
    return name;
}

Player::~Player() {}

void Player::show_text(std::string text) {
    color.showColorizedText(text);
}

void Player::displayPlayerInfo(){
    std::cout << "Pseudo : " << name << std::endl;
    std::cout << "Couleur : " << color.getColorName() << std::endl;
    std::cout << "Nombre de Coupon d'echange : " << tileExchange << std::endl;
    std::cout << "Nombre de carre en pierre : " << stone << std::endl;
    std::cout << "Vol de case restant: " << robbery << std::endl;
}



#endif // JOUEUR_H_INCLUDED
