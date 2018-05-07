//
// Created by Ricardo Ferreira on 04/05/2018.
//

#include <iomanip>
#include "Console.h"
#include "FileManager.h"

int main()
{
    Console console;
    FileManager file ("b002.txt");
    console.begin();
    file.printBoard();
    file.setFile("b001.txt");
    file.printBoard();
    file.closeFileStream();

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

