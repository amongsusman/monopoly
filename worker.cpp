#include <iostream>
#include <string>
#include "worker.h"

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