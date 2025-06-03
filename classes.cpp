#include "classes.h"
#include <iostream>
#include <string>
#include <vector> 

Game::Game(Player player, std::vector<Worker> workers, int currentHour, int currentDayHour) {
    mainUser = player;
    collectedWorkers = workers;
    gameTime = currentHour;
    dayHour = currentDayHour;
}
int Game::getCurrentHour() {
    return gameTime;
}
int Game::getCurrentDayHour() {
    return dayHour;
}
void Game::displayGameInfo() {
    std::cout << "~~~~~~~~GAME INFO~~~~~~~~~" << std::endl;
    std::cout << "Player Name: " << mainUser.getName() << std::endl;
    std::cout << "Player Money: " << mainUser.getMoney() << std::endl;
    std::cout << "Time Elapsed: " << getCurrentHour() << " hours" << std::endl;
    std::cout << "Current Day Hour: " << getCurrentDayHour() << std::endl;
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
std::string Player::getName() {
    return playerName;
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
