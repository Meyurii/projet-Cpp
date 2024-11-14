#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <map>

class Color{
    private:
        std::string colorName;
    public:
        std::map<std::string, std::string> allColors; //dictionnaire
        void showColorizedText(std::string text);
        Color();
        void askColor();
        void initColors();
        std::string getColorName();
        ~Color();
};


Color::Color(){
    initColors();
};

Color::~Color(){
    std::cout<< colorName <<" plus utlisise, destruction" << std::endl;
};

void Color::askColor(){
    std::cout << "choisi une couleur entre sapin, rouge, vert, jaune, bleu, rose, cyan, blanc, magenta  " << std::endl;
    std::cin >> colorName;
} //nom de la couleur stock


void Color::initColors() {
    allColors["sapin"] = "32";
    allColors["bleu"] = "34";
    allColors["rouge"] = "31";
    allColors["vert"] = "92";
    allColors["jaune"] = "93";
    allColors["rose"] = "95";
    allColors["blanc"] = "37";
    allColors["magenta"]="35";
    allColors["cyan"]="96";
}

void Color::showColorizedText(std::string text){
    std::string message = "\033[" + allColors[colorName] + "m" + text +"\033[0m";
    std::cout << message << std::endl;
}

std::string Color::getColorName() {
    return colorName;
}


// "\033[" + allColors[colorName] + "m" + message +"\033[0m";
#endif // COLOR_H_INCLUDED
