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
    makeMoney();
    setGameTime(getGameTime() + 1);
    setCurrentDayHour(getCurrentDayHour() + 1);
    resetCurrentDayHour();
}
void Game::addWorker(Worker newWorker) {
    collectedWorkers.push_back(newWorker);
}
void Game::rollWorker() {
    srand(time(nullptr));
    int n = possibleWorkers.size();
    int rolls = rand() % (n * 2) + 5;
    int delay = rolls * 50;
    for (int i = 0; i < rolls; i++) {
        std::cout << "\033[2J" << std::endl;
        if (i == 0) {
            std::cout << possibleWorkers[n - 1] << " ";
        }
        else {
            std::cout << possibleWorkers[(i - 1) % n] << " ";
        }
        std::cout << possibleWorkers[i % n] << " ";
        std::cout << possibleWorkers[(i + 1) % n] << " ";
        std::cout << "" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        delay -= 50;
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
    for (Worker w: collectedWorkers) {
        if (w.getStartTime() <= getCurrentDayHour() && getCurrentDayHour() <= w.getEndTime()) {
            mainUser.addMoney(w.getWorkerLevel() * w.getMoneyPerHour());
        }
    }
}
