#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Color.hpp"

class Player{
    private:
        int tileExchange; //Coupon d'échange
        int stone; // Carre cailloux
        int robbery; //Vole la case
        std::string name;
        Color color;

    public:
        Player();
        void displayPlayerInfo();
        ~Player();
        std::string getPlayerName();
        void show_text(std::string text);
};

Player::Player() {
    std::cout << "Bonjour ! Quel est votre nom de joueur ?" << std::endl;
    std::cin >> name ;
    std::cout << "Tres bien " << name << ". ";
    color.askColor();
    tileExchange = 1;
    stone = 0;
    robbery = 0 ;

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
