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
    std::cout << "Worker's Name: " << workerName << std::endl;
    std::cout << "Worker's Level: " << workerLevel << std::endl;
    std::cout << "Start Time: " << startTime << std::endl;
    std::cout << "End Time: " << endTime << std::endl;
    std::cout << "Money Per Hour: " << moneyPerHour << std::endl;
}
std::string Worker::getWorkerName() {
    return workerName;
}
int Worker::getWorkerLevel() {
    return workerLevel;
}
int Worker::getStartTime() {
    return startTime;
}
int Worker::getEndTime() {
    return endTime;
}
int Worker::getMoneyPerHour() {
    return moneyPerHour;
}