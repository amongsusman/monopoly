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
    void makeMoney();
    void simulateTermination();
private:
    Player mainUser;
    std::vector<Worker> collectedWorkers;
    const std::vector<std::string> possibleWorkers = {"Bill", "Gordon", "Joey", "Samantha", "Tyler", "Simpson", "AJ", "Joe", "Noah", "Akhil", "Shrihan", "Stephanie", "Dr. Seuss", "Jim", "Jorge", "Johnny", "Simon", "Nicole", "Kate", "Kimmy", "Bianca", "Chloe"};
    int gameTime;
    int dayHour;
};