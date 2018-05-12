//
// Created by Ricardo Ferreira on 07/05/2018.
//

#include <iomanip>
#include "FileManager.h"

FileManager::FileManager(){

}

FileManager::FileManager(string fileName) {
    FileManager::file.open(fileName);
}

string FileManager::trimSpaces(string s) {
    string aux="";
    for(int i=0; i<s.length();i++){
        if(s[i] != ' '){
            aux+=s[i];
        }
    }
    return aux;
}

vector<string> FileManager::explode(char c, string s) {
    vector<string> result;
    string str="";
    for(int i = 0; i < s.length(); i++){
        if(s[i] != c){
            str+=s[i];
        } else {
            if(str.length() > 0){
                result.push_back(str);
                str="";
            }
        }
    }

    return result;
}

void FileManager::convFileToVector() {
    if(FileManager::isOpen()){
        while(!FileManager::file.eof()){
            getline(FileManager::file, line);
            FileManager::fileLines.push_back(FileManager::trimSpaces(line));

        }
    }
}

bool FileManager::hasMoreLines() {
    return !FileManager::endOfLines;
}

string FileManager::getNextLine() {
    string aux;
    if(!FileManager::file.eof()){
        endOfLines = false;
        getline(FileManager::file, line);
        aux=line;
        FileManager::actualLine++;
    } else {
        //endOfLines = true;
        //Reset eof flag
        FileManager::file.clear();
        FileManager::file.seekg(0, ios::beg);
        actualLine = 0;
    }
    return aux;
}

vector<string> FileManager::getAllLines() {
    return FileManager::fileLines;
}

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

void FileManager::closeFileStream() {
    FileManager::file.close();
}

int FileManager::save(string filename, string playerScore) {
    ifstream check(filename);
    ofstream scoreBoard(filename, ios::app);
    if(!check.good()){
      scoreBoard << setfill('-') << setw(60) << '-' << endl;
      scoreBoard << "| " << setfill(' ') << setw(57) << left << "SCORE BOARD - PUZZLE b001";
      scoreBoard << "|";
      scoreBoard << endl;
      scoreBoard << setfill('-') << setw(60) << '-' << endl;
    }

    scoreBoard << "| " << setfill(' ') << setw(57) << left << playerScore;
    scoreBoard << "|";
    scoreBoard << endl;
    scoreBoard << setfill('-') << setw(60) << '-' << endl;
    check.close();
    scoreBoard.close();
    return 1;
}