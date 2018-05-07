#pragma once

#include <vector>
#include <string>
#include <iostream>

//consolecolor.cpp
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void setcolor(unsigned int color);
void setcolor(unsigned int color, unsigned int background_color);
void gotoxy(int x, int y);
void clrscr(void);

//board.cpp
class board {
public:
	board(int xcoor, int ycoor);
	board(std::vector<std::string> v1);

	bool full();
	bool wordMatch(std::string position, std::string word);

	void create();
	void reloadBoard();
	void reloadUserInputs();
	bool alter(std::string position, std::string word);
	void del(std::vector<std::vector<std::string>> userInputs);
	void show();
	void finish();

	std::vector<std::vector<std::string>> returnUserInputs();
	std::vector<std::vector<char>> returnWordTable();
	int retX();
	int retY();

private:
	int x, y;
	std::vector <std::vector<char>> wordTable;
	std::vector<std::string> savedContents;
	std::vector<std::vector<std::string>> savedUserInputs;
};

//dictionary.cpp
class dictionary {
public:
	dictionary(std::string filename);
	void buildList();
	std::vector<std::string> suggested(std::string word);
	std::string wordPrep(std::string word);
	std::vector <std::vector<std::string>> returnWordList();
private:
	std::string file;
	std::string word;
	std::vector <std::vector<std::string>> wordList;
};

//verifications.cpp
bool correctUserInputs(std::vector<std::vector<std::string>> userInputs, dictionary d1);
bool correctPosDir(std::string posDir, int x, int y);
bool wordFitsBoard(int x, int y, std::string posDir, int wordLength);
bool existingWord(std::vector<std::vector <std::string>> v1, std::string word);
bool dictionaryWord(std::string word, std::vector<std::vector <std::string>> v1);
bool simpleWord(std::string word);