//
// Created by Ricardo Ferreira on 08/05/2018.
//

#ifndef CROSSWORDS_DICTIONARY_H
#define CROSSWORDS_DICTIONARY_H


#include <map>
#include "FileManager.h"

class Dictionary {
    private:
        map< string, vector<string> > matchedWords;
        FileManager dictionary;
        string trimSpaces(string s);
        string getHeader(string s);
        vector< string > getSynonyms(size_t begin, string s);
    public:
        Dictionary(string fileName);
        map< string, vector<string> > getMatchedWord(string word);
        bool isOpen();
        void open();
        void close();


};


#endif //CROSSWORDS_DICTIONARY_H
