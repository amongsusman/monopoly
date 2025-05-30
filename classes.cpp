#include "classes.h"
#include <iostream>
#include <string>
Game::Game(int currentHour, int currentDayHour) {
    gameTime = currentHour;
    dayHour = currentDayHour;
}
int Game::getCurrentHour() {
    return gameTime;
}
int Game::getCurrentDayHour() {
    return dayHour;
}
void Game::setGameTime(int newTime) {
    gameTime = newTime;
}
void Game::resetCurrentDayHour() {
    if (dayHour == 25) {
        dayHour = 1;
    }
}
Player::Player(std::string name, int currentMoney) {
    playerName = name;
    playerMoney = currentMoney;
}
int Player::getMoney() {
    return playerMoney;
}
void Player::addMoney(int amount) {
    playerMoney += amount;
}
Worker::Worker(std::string name, int level, int start, int end, int money) {
    workerName = name;
    workerLevel = level;
    startTime = start;
    endTime = end;
    moneyPerHour = money;
}
void Worker::getWorkerInfo() {
    std::cout << workerName << std::endl;
    std::cout << workerLevel << std::endl;
    std::cout << startTime << std::endl;
    std::cout << endTime << std::endl;
    std::cout << moneyPerHour << std::endl;
}