/*                       BOARD METHODS                               */
#include "header.h"
#include <fstream>


using namespace std;

//Dictionary constructor
dictionary::dictionary(string filename) {
	file = filename;
}

//Return the valid word list
vector <vector <string>> dictionary::returnWordList() {
	return dictionary::wordList;
}

//Return capitalized word with no spaces
string dictionary::wordPrep(string word) {

	if (word == " ")
		return word;

	for (size_t i = 0; i < word.length(); i++)
		word[i] = toupper(word[i]);

	return word;
}

//Build list with all valid words from the given dictionaryk
void dictionary::buildList() {

	ifstream dict;
	ofstream saveFile;
	string line;
	string wordTemp;
	bool thefuck = true;

	dict.open(file);
	while (!dict.is_open()) {
		cout << "Dictionary not found, dictionary file name ? ";
		getline(cin, file);
		dict.open(file);
		cout << endl;
	}
	while (getline(dict, line)) {
		vector <string> temp;
		//Separate words in every line and add to list if the word is valid
		for (size_t i = 0; i < line.length(); i++) {
			if (line[i] != ':' && i != line.length() - 1)
				wordTemp += line[i];
			else {
				wordTemp = wordPrep(wordTemp);
				temp.push_back(wordTemp);
				wordTemp = "";
				i++;
			}
		}
		wordList.push_back(temp);
		thefuck = true;
	}
	dict.close();
}


/*vector<string> dictionary::suggested(std::string word) {

	//TODO palavras sugeridas
	//recebe por ex ????e??d e da list de palavras possiveis



}*/

