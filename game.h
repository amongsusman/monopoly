#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "worker.h"
#pragma once

class Game {
public:
    Game(Player &player, std::vector<Worker> &workers, int currentHour, int currentDayHour);
    void setPlayer(Player player);
    void setWorker(std::vector<Worker> workers);
    int getGameTime();
    int getCurrentDayHour();
    void displayGameInfo();
    void setGameTime(int newTime);
    void setCurrentDayHour(int newHour);
    void resetCurrentDayHour();
    void displayInstructions();
    void displayWorkers();
    void updateGame();
    void addWorker(Worker newWorker);
    void rollWorker();
private:
    Player mainUser;
    std::vector<Worker> collectedWorkers;
    const std::vector<std::string> possibleWorkers = {"Bill", "Gordon", "Joey", "Samanatha", "Tyler", "Simpson", "AJ", "Joe", "Noah", "Akhil", "Shrihan", "Stephanie", "Dr. Seuss"};
    int gameTime;
    int dayHour;
};