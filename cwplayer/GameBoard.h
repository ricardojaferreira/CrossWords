//
// Created by Ricardo Ferreira on 07/05/2018.
//

#ifndef CROSSWORDS_GAMEBOARD_H
#define CROSSWORDS_GAMEBOARD_H


#include <iostream>
#include <string>
#include <map>
#include "FileManager.h"
#include "Dictionary.h"

class GameBoard {
    private:
        int boardWidth = 0;
        int boardHeight = 0;
        vector<string> boardLines;
        map<string,string> solutions;
        map<string, vector<string>> synomys;
        vector<vector <char>> boardMatrix;
        FileManager file;
        Dictionary dictionary;
        bool error = false;
        void processLines();
        void addToBoard(string s);
        void addSolution(string s);
        void getSynonyms();
    public:
        GameBoard(string board, string wordFile);
        int getBoardWidth();
        int getBoardHeight();
        bool isGood();
        void printBoard();
};


#endif //CROSSWORDS_GAMEBOARD_H
