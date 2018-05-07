//
// Created by Ricardo Ferreira on 07/05/2018.
//

#ifndef CROSSWORDS_FILEMANAGER_H
#define CROSSWORDS_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Console.h"

using namespace std;

class FileManager {
    private:
        fstream file;
        string line;
        Console console;
    public:
        FileManager(string fileName);
        //fstream getFile();
        void setFile(string fileName);
        bool isOpen();
        void printOnScreen();
        void printBoard();
        void closeFileStream();
};


#endif //CROSSWORDS_FILEMANAGER_H
