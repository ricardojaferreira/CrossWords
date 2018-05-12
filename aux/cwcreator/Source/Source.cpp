#include "header.h"
#include <fstream>

using namespace std;

//Save current Board, its user inputs, and the dictionary used to a text file
void save(vector<vector<char> > v1, vector<vector<string> > v2, string dicName) {

	ofstream txtFile;
	string filename;

	cout << "Board save filename ? ";
	cin >> filename;
	cout << endl << "Saving board into file " << endl;
	txtFile.open(filename);

	txtFile << dicName << endl << endl; //Print dictionary name

	//Print Board
	for (size_t i = 1; i < v1.size(); i++) {
		for (size_t j = 1; j < v1.at(i).size(); j++)
			txtFile << v1.at(i).at(j) << ' ';
		txtFile << endl;
	}
	txtFile << endl;

	//Print user inputs
	for (size_t i = 0; i < v2.size(); i++)
		txtFile << v2.at(i).at(0) << ' ' << v2.at(i).at(1) << endl;
	txtFile.close();
}

//Remove entry from userInputs
bool del(vector<vector <string> > &userInputs, string posDir) {
	int line = -1;
	//Find the correct index on the vector
	for (size_t i = 0; i < userInputs.size(); i++) {
		if (posDir == userInputs.at(i).at(0)) {
			line = i;
			break;
		}
	}
	//If the position and direction given is not found in user inputs return false
	if (line == -1)
		return false;

	//if the entry is the most recent one remove from the top of the userInputs Vector
	if (line + 1 == userInputs.size()) {
		userInputs.pop_back();
		return true;
	}


	//Remove entry from vector
	for (size_t i = line; i < userInputs.size() - 1; i++) {
		userInputs.at(i).at(0) = userInputs.at(i + 1).at(0);
		userInputs.at(i).at(1) = userInputs.at(i + 1).at(1);
	}
	userInputs.resize(userInputs.size() - 1);
	return true;
}

//Build new or reloaded Board
void boardBuilding(string dictFilename, board b1, dictionary d1, int x, int y) {

	vector<vector <string> >		dictionaryWordList = d1.returnWordList();
	vector<vector <string> >		userInputs = b1.returnUserInputs();
	vector<vector <char> >		boardContents;
	char fullUserAnswer;

	//Keep asking for position/direction and word until user finishes the board or enters (CTRL-Z)
	while (!b1.full()) {
		string posDir;
		string word = " ";
		vector <string> temp;

		//Get position/direction
		while (!correctPosDir(posDir, x, y)) {
			char userAnswer;
			cout << endl << "Position ( LCD / CTRL-Z = stop )  ? ";
			cin >> posDir;

			//When user enters (CTRL-Z) / (CTRL-D)
			if (cin.eof()) {
				cout << "Enter 'S' to save and continue later, 'F' to finish this board or 'D' to discard it: " << endl;
				cin.clear();
				cin >> userAnswer;
				userAnswer = toupper(userAnswer);
				if (userAnswer == 'D')
					return;
				while (cin.fail() || (userAnswer != 'S' && userAnswer != 'F' && userAnswer != 'D')) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl << "Invalid input, try again" << endl;
					cout << "Enter 'S' to save and continue later, 'F' to finish this board or 'D' to discard it: " << endl;
					cin >> userAnswer;
					if (userAnswer == 'D')
						return;
				}
				//Save board as is to continue later
				if (userAnswer == 'S') {
					boardContents = b1.returnWordTable();
					save(boardContents, userInputs, dictFilename);
					cout << endl << "The Board has been saved." << endl;
					cin.clear();
					cin.ignore();
					cout << "Press 'Enter' to continue" << endl;
					getchar();
				}
				//Fill board with black cells and save
				else {
					b1.finish();
					boardContents = b1.returnWordTable();
					save(boardContents, userInputs, dictFilename);
					cout << endl << "The Board has been saved." << endl;
					cin.clear();
					cin.ignore();
					cout << "Press 'Enter' to continue" << endl;
					getchar();
				}
				return;
			}

			//Position/direction error message
			if (!correctPosDir(posDir, x, y))
				cout << "Incorrect position and direction entry, read instructions and try again" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//Get word
		while (!simpleWord(word) || !dictionaryWord(word, dictionaryWordList) || existingWord(userInputs, word) || !wordFitsBoard(x, y, posDir, word.length())) {

			cout << "Word ( - = remove / ? = help )  ? ";
			cin >> word;

			//Deleting a word
			if (word == "-") {
				if (del(userInputs, posDir)) {
					b1.del(userInputs);
					cout << endl << "The selected word has been removed from the board" << endl;
					break;
				}
				else {
					cout << endl << "No word with STARTING position, and direction: '" << posDir << "' found." << endl;
					cout << "To delete a word enter its starting position and direction, and then enter '-' when asked for a word" << endl;
					break;
				}
			}

			for (size_t i = 0; i < word.length(); i++)
				word[i] = toupper(word[i]);

			//Word error messages
			if (!simpleWord(word))
				cout << endl << "Word is not simple (a-Z), try again" << endl;
			else if (!dictionaryWord(word, dictionaryWordList))
				cout << endl << "Word does not exist in the dictionary, try again" << endl << endl;
			else if (existingWord(userInputs, word))
				cout << endl << "Word already exists on the board, try again" << endl;
			else if (!wordFitsBoard(x, y, posDir, word.length()))
				cout << endl << "Word does not fit the board, try again" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//If the word is added to board, show updated board and save the user inputs to a 2D vector
		if (b1.alter(posDir, word)) {
			b1.show();
			temp.push_back(posDir);
			temp.push_back(word);
			userInputs.push_back(temp);
		}
	}

	//When board is full, ask if user wants to save
	cout << "The board is full, to save the board enter 'S' , or to discard it 'N' ? ( S/D ) ";
	cin >> fullUserAnswer;
	fullUserAnswer = toupper(fullUserAnswer);

	while (cin.fail() || (fullUserAnswer != 'S' && fullUserAnswer != 'D')) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input, try again" << endl;
		cout << "The board is full, do you with to save the board ( Y ) , or discard it ( N ) ? ( Y/N) ";
		cin >> fullUserAnswer;
	}

	if (fullUserAnswer == 'S') {
		//Final verification if all inputs are valid	
		if (!correctUserInputs(userInputs, d1)) {
			cout << "Invalid words found, cannot save board" << endl;
		}
		else {
			boardContents = b1.returnWordTable();
			save(boardContents, userInputs, dictFilename);
			cout << endl << "The Board has been saved " << endl;
		}
	}

	cout << "Press 'Enter' to continue" << endl;
	getchar();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Start a new, empty board
void newPuzzle() {

	string dictFilename;
	unsigned int x = 0, y = 0;

	cout << endl << "---------------------------------------------------" << endl << "CREATE PUZZLE" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Dictionary file name ? ";

	//Create dictionary
	getline(cin, dictFilename);
	dictionary d1(dictFilename);
	d1.buildList();

	//Create Board
	while (cin.fail() || x > 25 || x < 1 || y < 1 || y > 25) {
		cout << "Board size (lines columns) ? ";
		cin >> y >> x;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	board b1(x, y);
	b1.create();
	//Show empty board
	b1.show();
	//Start building the board
	boardBuilding(dictFilename, b1, d1, x, y);
}

//Reload saved board
void reloadPuzzle() {

	string dictFilename;
	string boardFilename;
	string line;

	vector<string> reloadContents;
	ifstream txtFile;

	//Get save Filename
	cout << endl << "---------------------------------------------------" << endl << "RELOAD PUZZLE" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << endl << "Board save file name? ";
	cin >> boardFilename;
	txtFile.open(boardFilename);
	while (!txtFile.is_open()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Board save file not found, board save file name ? ";
		cin >> boardFilename;
		txtFile.open(boardFilename);
		cout << endl;
	}

	//Save all the contents of the file to a string vector
	while (getline(txtFile, line)) {
		reloadContents.push_back(line);
	}

	//Rebuild dictionary
	dictFilename = reloadContents.at(0);
	dictionary d1(dictFilename);
	d1.buildList();

	//Reload the board and its user inputs
	board rb1(reloadContents);
	rb1.reloadUserInputs();
	rb1.reloadBoard();
	if (rb1.full()) {
		cout << endl << "This board is already full" << endl;
		cin.clear();
		cin.ignore();
		cout << "Press 'Enter' to continue" << endl;
		getchar();
		return;
	}
	//Start building the board again
	int x = rb1.retX();
	int y = rb1.retY();

	boardBuilding(dictFilename, rb1, d1, x, y);
}

//Initial interface(Main menu and instructions)
int main() {

	while (true) {
		clrscr();
		cout << "CROSSWORDS PUZZLE CREATOR" << endl << "==================================================" << endl;
		cout << endl << "INTRUCTIONS:" << endl << "Creating a puzzle:" << endl;
		cout << " Position ( LCD / CTRL-Z = stop )" << endl;
		cout << "  LCD stands for Line Column and Direction" << endl;
		cout << "  Enter 3 letters only:" << endl;
		cout << "   Uppercase letter for lines, lowercase letter for columns and uppercase V(vertical) or H(horizontal)" << endl;
		cout << "   Example: AcV" << endl;
		cout << " Words must:" << endl;
		cout << "  be simple(a - Z)" << endl;
		cout << "  match with other words on the board" << endl;
		cout << "  not exist on the board already" << endl;
		cout << "  fit the board" << endl;
		cout << " To delete a word from the board, enter its starting position and direction, and then enter '-', when asked for a word" << endl;
		cout << "---------------------------------------------------" << endl << "OPTIONS:" << endl;
		cout << endl << "1 - Create puzzle" << endl << "2 - Resume puzzle" << endl << "0 - Exit" << endl;
		cout << endl << "Option ? ";

		int menuChoice = -1;

		while (cin.fail() || menuChoice < 0 || menuChoice > 2) {
			cin >> menuChoice;
			if (cin.fail() || menuChoice < 0 || menuChoice > 2)
				cout << "Invalid value, choose a menu option (0 , 1 or 2)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (menuChoice) {
		case 0:
			return 0;
		case 1:
			newPuzzle();
			break;
		case 2:
			reloadPuzzle();
			break;
		}
	}
}