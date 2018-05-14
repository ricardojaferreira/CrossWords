//
// Created by Ricardo Ferreira on 07/05/2018.
//

#ifndef CROSSWORDS_FILEMANAGER_H
#define CROSSWORDS_FILEMANAGER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Console.h"

using namespace std;

class FileManager {
    private:
        fstream file;
        string line;
        Console console;
        vector< string > fileLines;
        int actualLine;
        bool endOfLines;

    public:
        FileManager();
        FileManager(string fileName);
        void convFileToVector();
        bool hasMoreLines();
        string getNextLine();
        vector<string> getAllLines();
        void setFile(string fileName);
        bool isOpen();
        void printOnScreen();
        //void printBoard();
        void closeFileStream();
        //aux functions
        string trimSpaces(string s);
        vector<string> explode(char c, string s);
        int save(string filename, string playerScore);
};


#endif //CROSSWORDS_FILEMANAGER_H
