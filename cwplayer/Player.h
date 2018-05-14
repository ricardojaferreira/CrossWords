//
// Created by Ricardo Ferreira on 08/05/2018.
//

#ifndef CROSSWORDS_PLAYER_H
#define CROSSWORDS_PLAYER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Console.h"

using namespace std;

class Player {
    private:
        string name;
        time_t start;
        time_t end;
        int altClues;
        double elapsedTime;
    public:
        Player();
        void setName(string cName);
        string getName();
        int getAlternativeClues();
        double getElapsedTime();
        void incrementAltClues();
        void printAlternativeClues();
        void updateStartTime();
        void printStartTime();
        void updateEndTime();
        void printEndTime();
        void updateElapsedTime();
        void printElapsedInSeconds();
};


#endif //CROSSWORDS_PLAYER_H
