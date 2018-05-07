//
// Created by Ricardo Ferreira on 07/05/2018.
//

#include "FileManager.h"

FileManager::FileManager(string fileName) {
    FileManager::file.open(fileName);
}

//passar por referência
/*fstream FileManager::getFile(){
    return FileManager::file;
}*/

void FileManager::setFile(string fileName) {
    if(FileManager::file.is_open()){
        FileManager::file.close();
    }
    FileManager::file.open(fileName);
}

bool FileManager::isOpen() {
    if(FileManager::file.is_open()){
        return true;
    }
    return false;
}

void FileManager::printOnScreen(){
    while(!FileManager::file.eof()){
        getline(FileManager::file, line);
        cout << line << endl;
    }
}

void FileManager::printBoard(){
    while(!FileManager::file.eof()){
        getline(FileManager::file, line);
        for(int i = 0; i< line.length(); i++){
            if(line[i] == '#'){
                for(int i=0; i<line.length(); i++){
                    if(line[i] != '#'){
                        line[i] = ' ';
                    }
                }
                console.printLine(RED, BLACK_B, line);
                goto cnt;
            }
        }
        cnt:;
    }

}

void FileManager::closeFileStream() {
    FileManager::file.close();
}