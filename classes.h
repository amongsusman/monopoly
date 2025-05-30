#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>

class Game {
public:
    Game(int currentHour, int currentDayHour);
    int getCurrentHour();
    int getCurrentDayHour();
    void setGameTime(int newTime);
    void resetCurrentDayHour();
private:
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