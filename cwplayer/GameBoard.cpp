//
// Created by Ricardo Ferreira on 07/05/2018.
//

#include "GameBoard.h"

GameBoard::GameBoard(string board, string wordFile) : file(board), dictionary(wordFile) {
    GameBoard::file = FileManager(board);
    GameBoard::dictionary = Dictionary(wordFile);
    GameBoard::file.convFileToVector();
    GameBoard::boardLines = GameBoard::file.getAllLines();
    GameBoard::file.closeFileStream();
    GameBoard::processLines();
    GameBoard::getSynonyms();
    GameBoard::boardWidth = GameBoard::boardMatrix[0].size();
    GameBoard::boardHeight = GameBoard::boardMatrix.size();
}

void GameBoard::processLines() {
    string line ="";
    bool boardFlag = false;
    for(int i=0; i < GameBoard::boardLines.size(); i++){
        line = GameBoard::boardLines.at(i);

        if(line.length()==0){
            continue;
        }

        //Check if is a solution
        if((line[0] >= 'A' && line[0] <= 'Z') &&
           (line[1] >= 'a' && line[1] <= 'z') &&
           (line[2] == 'H' || line[2] == 'V') ) {
            GameBoard::addSolution(line);
            continue;
        }

        for(int j=0; j < line.length(); j++){
            if(line[j] == '#' ||
               (line[j] >= 'A' && line[j] <= 'Z')){
                boardFlag = true;
            }else{
                boardFlag = false;
                break;
            }

        }
        if(boardFlag){
            GameBoard::addToBoard(line);
        }

    }
}

void GameBoard::addSolution(string s) {
    string key = "";
    string value = "";
    key+=s[0];
    key+=s[1];
    key+=s[2];

    for(int i=3; i<s.length(); i++){
        value += s[i];
    }

    if(key.length() > 0 && value.length() > 0){
        GameBoard::solutions.insert(make_pair(key, value));
    }
}

void GameBoard::addToBoard(string s) {
    vector<char> line;
    for(int i = 0; i < s.length(); i++){
        line.push_back(s[i]);
    }
    GameBoard::boardMatrix.push_back(line);
}

void GameBoard::getSynonyms() {
    map<string, string>::iterator it = GameBoard::solutions.begin();
    if(GameBoard::dictionary.isOpen()){
        while(it != GameBoard::solutions.end()){
            map <string,vector<string>> aux = GameBoard::dictionary.getMatchedWord(it->second);
            if(!(aux.size()>0)){
                GameBoard::error = true;
                cout << "Something went wrong while reading the Dictionary..." << endl;
                cout << "The word: " << it->second << " was not found." << endl;
            }
            GameBoard::synomys.insert(make_pair(aux.begin()->first, aux.begin()->second));
            it++;
        }
    }
}

bool GameBoard::isGood(){
    return GameBoard::error;
}

void GameBoard::printBoard() {

}

int GameBoard::getBoardWidth() {
    return GameBoard::boardWidth;
}

int GameBoard::getBoardHeight() {
    return GameBoard::boardHeight;
}