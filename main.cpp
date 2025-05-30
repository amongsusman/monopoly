/*
Name: Tyler Zhang
Program Name: Monopoly Simulator
Date: 5/30/25
Extra: ?
*/
#include <iostream>
#include <ctime>
#include <string>
#include "classes.h"
#include "classes.cpp"
int main() {
    std::cout << "~~~~~~~~MONOPOLY SIMULATOR~~~~~~~~" << std::endl;
    std::string name;
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin, name);
    Player user(name, 0);
}