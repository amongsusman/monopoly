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
#include <chrono>
#include <thread>
#include <conio.h>
#include "game.h"
#include "player.h"
#include "worker.h"

int main() {
    std::cout << "~~~~~~~~MONOPOLY SIMULATOR~~~~~~~~" << std::endl;
    
    std::string name;
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin, name);
    Player newPlayer(name, 0);
    std::vector<Worker> workers = {};
    Game newGame(newPlayer, workers, 0, 1);
    bool run = true;

    while (run) {
        while (!_kbhit()) {
            newGame.displayGameInfo();
            newGame.updateGame();
            std::cout << "\033[2J" << std::endl;
        }
        char c = _getch(); 
        switch (c) {
            case 'b': {
                newGame.rollWorker();
                while (!_kbhit()) {
                    newGame.updateGame();
                }
                break;
            }
            case 'd': { 
                newGame.displayWorkers();
                while (!_kbhit()) {
                    newGame.updateGame();   
                }
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}
