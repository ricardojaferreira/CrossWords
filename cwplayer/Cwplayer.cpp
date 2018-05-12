//
// Created by Ricardo Ferreira on 04/05/2018.
//

#include <iomanip>
#include "GameBoard.h"
#include "Player.h"

#include "dirent.h"

bool gameStart = false;

void welcome(Player *p){
    string name;
    Console console;
    bool validName = false;
    cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
    cout << setfill('=') << setw(COUT_SIZE) << '=' << endl;
    cout << "What is your name ? : ";
    while(!validName){
        getline(cin, name);
        if(name.length() > 0 && !cin.fail()){
            for(int i=0; i<name.length(); i++){
                if((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '){
                    validName = true;
                } else {
                    validName = false;
                    console.clrNgoTo(0,0);
                    cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
                    //cout << "=============================================" << endl;
                    cout << setfill('=') << setw(COUT_SIZE) << '=' << endl;
                    cerr << RED << "Please use only letters." << NO_COLOR << endl;
                    cout << RED << setfill('-') << setw(COUT_SIZE) << '-' << NO_COLOR << endl;
                    cout << "Please enter your name ? : ";
                    break;
                }
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            console.clrNgoTo(0,0);
            cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
            cout << setfill('=') << setw(COUT_SIZE) << '=' << endl;
            cerr << RED << "The name cannot be empty." << NO_COLOR << endl;
            cout << RED << setfill('-') << setw(COUT_SIZE) << '-' << NO_COLOR << endl;
            cout << "Please enter your name ? : ";
        }
        if(validName){
            p->setName(name);
        }
    }

    cout << "Welcome " << p->getName() << endl;
}

void printHeader(Player *p, string puzzle = "", char op='a'){
    cout << "CROSSWORDS PUZZLE - GAME" << endl;
    cout << setfill('=') << setw(COUT_SIZE) << '=' << endl;
    cout << "Player: " << p->getName() << endl;
    if(puzzle != ""){
        cout << "Puzzle: " << puzzle;
    }

    if(op == 'y'){
        cout << "  |  " << "Clear Console: Yes";
    }

    if(op == 'n'){
        cout << "  |  " << "Clear Console: No";
    }
    cout << endl;

    cout << "Started at: "; p->printStartTime();
    cout << "  |  " << "Time: "; p->updateElapsedTime();
    p->printElapsedInSeconds(); cout << endl;
    if(gameStart){
        p->printAlternativeClues();
        cout << BROWN << "(At any time: p->print board; c->print clues)" << endl;
    }
    cout << BLUE << setfill('-') << setw(COUT_SIZE) << '-' << NO_COLOR << endl;
}

int showAvailablePuzzles(vector<string> &v){
    cout << "Please choose one of the available Puzzles" << endl;
    cout << endl;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("puzzles/")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string s = ent->d_name;
            //print only the puzzle files
            if(s[0] == 'b'){
                cout << "  --> " << s << endl;
                v.push_back(s);
            }
        }
        closedir (dir);
        cout << endl;
        return 1;
    } else {
        return 0;
    }
}

bool abandonGame(){
    char answer = ' ';
    while(answer != 'y' && answer != 'n'){
        cout << "Are you Sure? (y/n) ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> answer;
        if(!cin.fail() && !cin.eof() && answer == 'y'){
            cout << endl;
            cout << "Goodbye";
            cout << endl;
            cout << endl;
            return true;
        }

        if(!cin.fail() && !cin.eof() && answer == 'n'){
            return false;
        }

        cout << "Invalid option." << endl;
    }
    return false;
}

int main()
{

    FileManager file;
    file.save("scoreboards/b001_p.txt", "Hello");

//    Player p1;
//    Console console;
//    welcome(&p1);
//    string aux;
//    p1.updateStartTime();
//    console.clrscr();
//    printHeader(&p1);
//    vector<string> puzzles;
//    int position = -1;
//    if(showAvailablePuzzles(puzzles)){
//        string temp = "";
//        cout << "Type the name of the file: ";
//        while(position == -1){
//            cin >> temp;
//            if(!cin.fail()){
//                for(int i=0; i<puzzles.size(); i++){
//                    if(!temp.compare(puzzles[i])){
//                        position = i;
//                        break;
//                    }
//                }
//                if(position == -1){
//                    cout << endl;
//                    cout << "Invalid file name, please choose another: ";
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                }
//            } else {
//                cout << endl;
//                cout << "Something went wrong, please try again: ";
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            }
//        }
//    }
//
//    GameBoard board ("puzzles/"+puzzles.at(position), "Dictionary/Dictionary.txt");
//    console.clrscr();
//    printHeader(&p1, puzzles.at(position));
//    cout << "Play in clear console mode (y/n)? ";
//    char op = 'a';
//    while(cin.fail() || true){
//        cin >> op;
//        if(op == 'y' || op =='n'){
//            break;
//        }
//        cout << "Not a valid option - (y/n): ";
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << endl;
//    }
//    //Entering the loop
//    gameStart = true;
//    console.clrscr();
//    printHeader(&p1, puzzles.at(position), op);
//    board.print();
//    board.printClues();
//    string boardPos = "";
//    string word = "";
//    bool check = true;
//    while(!board.isFull() || !board.isCorrect()){
//
//        if(board.isFull() && check){
//            // The board is full check answers
//            cout << "Your answers:";
//            board.checkAnswers();
//
//            if(board.isCorrect()) break;
//            check = false;
//        }
//
//
//        if(boardPos == ""){
//            cin.clear();
//            cin.ignore(1000, '\n');
//            cout << "Position ( LCD / CTRL-Z or e = stop )  ? ";
//            cin >> boardPos;
//        } else {
//            cin.clear();
//            cin.ignore(1000, '\n');
//            cout << LIGHTCYAN << "  > " << "Position: " << boardPos << NO_COLOR << endl;
//            cout << "Word (- / ? / + / ! / e) ? ";
//            cin >> word;
//        }
//
//        //possibility to change location without typing the word
//
//        if(cin.fail()){
//            cin.clear();
//            cin.ignore(1000,'\n');
//            boardPos = "";
//            word = "";
//            continue;
//        }
//
//        //process exit
//        if (boardPos == "e" || word == "e" || cin.eof()) {
//            if(abandonGame()){
//                return 0;
//            } else {
//                if(boardPos =="e") goto bgn;
//                if(word == "e") goto word;
//            }
//        }
//
//        //print board
//        if(boardPos == "p" || word == "p"){
//            if(boardPos =="p") goto bgn;
//            if(word == "p") goto word;
//        }
//
//        //print clues
//        if(boardPos == "c" || word == "c"){
//            board.printClues();
//            if(boardPos =="c") boardPos="";
//            if(word == "e") word="";
//            continue;
//        }
//
//        if(word == "!"){
//            goto bgn;
//        }
//
//        cout << endl;
//        switch(board.validateOption(boardPos, word)){
//            case 0:     if(boardPos != "" && word == ""){
//                            continue;
//                        }
//                        check = true;
//                        goto bgn;
//
//            case 1:     cout << "That option has an unexpected size!" << endl;
//                        boardPos="";
//                        continue;
//
//            case 2:     cout << "You have chosen a line out of range!" << endl;
//                        boardPos = "";
//                        continue;
//
//            case 3:     cout << "You have chosen a column out of range!" << endl;
//                        boardPos = "";
//                        continue;
//
//            case 4:     cout << "You have chosen an invalid position on the board" << endl;
//                        boardPos = "";
//                        continue;
//
//            case 5:     continue;
//
//            case 6:     p1.incrementAltClues();
//                        continue;
//
//            case 7:     cout << "The word typed doesnt fit on that location!" << endl;
//                        word = "";
//                        continue;
//
//            case 8:     cout << "There is no word to remove there!" << endl;
//                        word = "";
//                        continue;
//
//            case 9:     cout << "Your word doesnt match with one of the letters already on the board!" << endl;
//                        word = "";
//                        continue;
//        }
//
//        bgn:
//            boardPos="";
//        word:
//            word = "";
//            if(op=='y'){
//                console.clrscr();
//            } else {
//                cout << setfill('*') << setw(COUT_SIZE) << '*' << endl;
//            }
//            printHeader(&p1, puzzles.at(position), op);
//            board.print();
//            cout << endl;
//            cout << setfill('-') << setw(COUT_SIZE) << '-' << endl;
//    }
//
//
//    cout << endl;
//    cout << endl;
//    cout << "Fucking Great";
//    cout << endl;
//    cout << endl;

    return 0;

}

