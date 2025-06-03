/*
Name: Tyler Zhang
Program Name: Monopoly Simulator
Date: 5/30/25
Extra: ?
*/
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "classes.h"
#include "classes.cpp"
int main() {
    std::cout << "~~~~~~~~MONOPOLY SIMULATOR~~~~~~~~" << std::endl;

    std::string name;
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin, name);

    Game newGame{Player(name, 0), {}, 0, 1};
    bool run = true;

    while (run) {
        newGame.displayGameInfo();
        std::cout << "\033[2J" << std::endl;
    }
    return 0;
}
