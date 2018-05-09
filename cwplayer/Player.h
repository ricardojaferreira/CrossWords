//
// Created by Ricardo Ferreira on 08/05/2018.
//

#ifndef CROSSWORDS_PLAYER_H
#define CROSSWORDS_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {
    private:
        string name = "";
        time_t start;
        time_t end;
        double elapsedTime = 0;
    public:
        void setName(string cName);
        string getName();
        void updateStartTime();
        void printStartTime();
        void updateEndTime();
        void printEndTime();
        void updateElapsedTime();
        void printElapsedInSeconds();
};


#endif //CROSSWORDS_PLAYER_H
