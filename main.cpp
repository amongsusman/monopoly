/*
Name: Tyler Zhang
Program Name: Monopoly Simulator
Date: 5/30/25
Extra: None
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
    std::cout << "Press 'b' to hire a worker and 'd' to display the workers you have. Have fun!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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
                break;
            }
            case 'd': { 
                newGame.displayWorkers();
                std::cout << "Press any button to return to Game Info." << std::endl;
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