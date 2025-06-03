#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
#include <vector>

// need to fix errors with game constructor 

class Game {
public:
    Game(const Player& player, const std::vector<Worker>& workers, int currentHour, int currentDayHour);
    int getCurrentHour();
    int getCurrentDayHour();
    void displayGameInfo();
    void setGameTime(int newTime);
    void resetCurrentDayHour();
private:
    Player mainUser;
    std::vector<Worker> collectedWorkers;
    int gameTime;
    int dayHour;
};

class Player {
public:
    Player(std::string name, int currentMoney);
    std::string getName();
    int getMoney();
    void addMoney(int amount);
private:
    std::string playerName;
    int playerMoney;
};

class Worker {
public:
    Worker(std::string name, int level, int start, int end, int money);
    void getWorkerInfo();
private:
    std::string workerName;
    int workerLevel;
    int startTime;
    int endTime;
    int moneyPerHour;
};

#endif
