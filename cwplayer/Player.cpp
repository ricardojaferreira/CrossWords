//
// Created by Ricardo Ferreira on 08/05/2018.
//

#include <iomanip>
#include "Player.h"

void Player::setName(string cName) {
    Player::name = cName;
}

string Player::getName() {
    return Player::name;
}

void Player::updateStartTime() {
    auto startT = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(startT);
    Player::start = start_time;
}

void Player::printStartTime() {
    cout << put_time(localtime(&(Player::start)), "%F %H:%M:%S");
}

void Player::updateEndTime() {
    auto endT = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(endT);
    Player::end = end_time;
}

void Player::printEndTime() {
    cout << put_time(localtime(&(Player::end)), "%F %H:%M:%S");
}

void Player::updateElapsedTime() {
    Player::elapsedTime = (Player::end - Player::start);
}

void Player::printElapsedInSeconds() {
    Player::updateEndTime();
    Player::updateElapsedTime();
    cout << Player::elapsedTime << "s";
}