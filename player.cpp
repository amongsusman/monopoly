#include <iostream>
#include <string>
#include <vector>
#include "player.h"

Player::Player(){
    
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