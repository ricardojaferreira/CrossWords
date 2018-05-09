//
// Created by Ricardo Ferreira on 04/05/2018.
//

#include <iomanip>
#include "GameBoard.h"
#include "Player.h"

#include "dirent.h"

void welcome(Player *p){
    string name;
    Console console;
    bool validName = false;
    cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
    cout << "=============================================" << endl;
    cout << "What is your name ? : " << endl;
    while(!validName){
        getline(cin, name);
        if(name.length() > 0){
            for(int i=0; i<name.length(); i++){
                if((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '){
                    validName = true;
                } else {
                    validName = false;
                    console.clrNgoTo(0,0);
                    cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
                    cout << "=============================================" << endl;
                    cerr << RED << "Please use only letters." << NO_COLOR << endl;
                    cerr << RED << "----------------------------------------------" << NO_COLOR << endl;
                    cout << "Please enter your name ? : ";
                    break;
                }
            }
        } else {
            console.clrNgoTo(0,0);
            cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
            cout << "=============================================" << endl;
            cerr << RED << "The name cannot be empty." << NO_COLOR << endl;
            cerr << RED << "----------------------------------------------" << NO_COLOR << endl;
            cout << "Please enter your name ? : ";
        }
        if(validName){
            p->setName(name);
        }
    }

    cout << "Welcome " << p->getName() << endl;
}

void printHeader(Player *p){
    cout << "CROSSWORDS PUZZLE - GAME" << endl;
    cout << "=============================================" << endl;
    cout << "Player: " << p->getName() << endl;
    cout << "Started at: "; p->printStartTime(); cout << endl;
    cout << "Time Playing: "; p->updateElapsedTime();
    p->printElapsedInSeconds(); cout << endl;
    cout << BLUE << "----------------------------------------------" << NO_COLOR << endl;
}


int main()
{
    Player p1;
    Console console;
    welcome(&p1);
    string aux;
    p1.updateStartTime();
    console.clrscr();
    printHeader(&p1);


    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("puzzles/")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string s = ent->d_name;
            if(s[0] == 'b'){
                cout << s << endl;
            }
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }



    GameBoard board ("b002.txt", "Dictionary.txt");







/*    string aux;
    p1.updateStartTime();
    p1.printStartTime();

    getline(cin, aux);

    p1.printElapsedInSeconds();
    cout << endl;
    p1.printEndTime();

    getline(cin, aux);

    p1.printElapsedInSeconds();
    cout << endl;
    p1.printEndTime();*/




    return 0;


    /*
    console.clrscr();
    cout << RED << "Text in RED" << NO_COLOR << endl;
    cout << LIGHTRED << "Text in LIGHTRED" << NO_COLOR << endl;
    cout << BLUE << "Text in BLUE" << NO_COLOR << endl;
    cout << GREEN << "Text in GREEN" << NO_COLOR << endl;
    cout << RED << WHITE_B << "Text in RED on WHITE background" << NO_COLOR << endl;
    cout << RED << BLACK_B << "Text in RED on BLACK background" << NO_COLOR << endl;
    cout << "\nPress <enter> to continue ...";
    cin.get();
    cout << "Cursor is going to move to (20,3). Press <enter> to continue ...";
    cin.get(); console.gotoxy(20, 3);
    cout << "Screen is going to be cleaned. Press <enter> to continue ...";
    cin.get(); console.clrscr();
    // alternatively ...
    console.setcolor(LIGHTBLUE, WHITE_B); // OR cout << LIGHTBLUE << WHITE_B;
    cout << "From now on\n";
    cout << "everything is written LIGHTBLUE\n";
    cout << "on WHITE background\n";
    console.setcolor(NO_COLOR); // OR cout << NO_COLOR;
    cout << "End of program\n";
     */
}

