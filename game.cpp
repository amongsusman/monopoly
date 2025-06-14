#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>
#include "player.h"
#include "worker.h"
#include "game.h"

Game::Game(Player &player, std::vector<Worker> &workers, int currentHour, int currentDayHour) {
    mainUser = player;
    collectedWorkers = workers;
    gameTime = currentHour;
    dayHour = currentDayHour;
}
void Game::setPlayer(Player player){
    mainUser = player;
}
void Game::setWorker(std::vector<Worker> workers){
    collectedWorkers = workers;
}
int Game::getGameTime() {
    return gameTime;
}
int Game::getCurrentDayHour() {
    return dayHour;
}
void Game::displayGameInfo() {
    std::cout << "~~~~~~~~GAME INFO~~~~~~~~~" << std::endl;
    std::cout << "Player Name: " << mainUser.getName() << std::endl;
    std::cout << "Player Money: " << mainUser.getMoney() << std::endl;
    std::cout << "Time Elapsed: " << getGameTime() << " hours" << std::endl;
    std::cout << "Current Day Hour: " << getCurrentDayHour() << std::endl;
}
void Game::setGameTime(int newTime) {
    gameTime = newTime;
}
void Game::setCurrentDayHour(int newHour) {
    dayHour = newHour;
}
void Game::resetCurrentDayHour() {
    if (dayHour == 25) {
        dayHour = 1;
    }
}
void Game::displayInstructions() {
    std::cout << "b: hire workers" << std::endl;
    std::cout << "d: display workers" << std::endl;
}
void Game::displayWorkers() {
    for (int i = 0; i < collectedWorkers.size(); i++) {
        Worker curWorker = collectedWorkers[i];
        curWorker.getWorkerInfo();
    }
}
void Game::updateGame() {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    simulateTermination();
    makeMoney();
    setGameTime(getGameTime() + 1);
    setCurrentDayHour(getCurrentDayHour() + 1);
    resetCurrentDayHour();
}
void Game::addWorker(Worker newWorker) {
    collectedWorkers.push_back(newWorker);
}
void Game::rollWorker() {
    if (mainUser.getMoney() >= 10000) {
        std::cout << "Rolling worker..." << std::endl;
        mainUser.addMoney(-10000);
    }
    else {
        std::cout << "Sorry, you don't have enough to hire another worker." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    srand(time(nullptr));
    int n = possibleWorkers.size();
    int rolls = rand() % (n * 2) + 5;
    int delay = 0;
    for (int i = 0; i < rolls; i++) {
        std::cout << "\033[2J" << std::endl;
        if (i == 0) {
            std::cout << possibleWorkers[n - 1] << " ";
        }
        else {
            std::cout << possibleWorkers[(i - 1) % n] << " ";
        }
        std::cout << "\e[0;32m" + possibleWorkers[i % n] + "\e[0;37m" << " ";
        std::cout << possibleWorkers[(i + 1) % n] << " ";
        std::cout << "" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        delay += (1000 / rolls);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string rolledWorkerName = possibleWorkers[(rolls - 1) % n];
    int level = rand() % 100 + 1;
    int start = rand() % 24 + 1;
    int end = rand() % (25 - start) + start;
    int money = rand() % 200 + 50;
    Worker rolledWorker(rolledWorkerName, level, start, end, money);
    addWorker(rolledWorker);
}
void Game::makeMoney() {
    mainUser.addMoney(100);
    for (Worker w: collectedWorkers) {
        if (w.getStartTime() <= getCurrentDayHour() && getCurrentDayHour() <= w.getEndTime()) {
            mainUser.addMoney(w.getWorkerLevel() * w.getMoneyPerHour());
        }
    }
}
void Game::simulateTermination() {
    srand(time(nullptr));
    int randNum = rand() % 50;
    if (randNum == 0) {
        collectedWorkers.pop_back();
    }
}