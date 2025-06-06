#include <iostream>
#include <string>
#pragma once

class Player {  
public:
    Player();
    Player(std::string name, int currentMoney);
    std::string getName();
    int getMoney();
    void addMoney(int amount);
private:
    std::string playerName;
    int playerMoney;
};