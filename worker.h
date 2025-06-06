#include <iostream>
#include <string>
#pragma once

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