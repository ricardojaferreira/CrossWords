//
// Created by Ricardo Ferreira on 05/05/2018.
//

#include "Console.h"

void Console::gotoxy(int x, int y) {
    ostringstream oss;
    oss << "\033[" << y << ";" << x << "H";
    cout << oss.str();
}

void Console::clrscr(void) {
    cout << "\033[2J";
    gotoxy(0, 0);
}

// Set text color
void Console::setcolor(string color) {
    cout << color;
}

// Set text color & background
void Console::setcolor(string color, string background_color) {
    cout << color << background_color;
}

void Console::printLine(string color, string backgroundColor, string text) {
    cout << color << backgroundColor << text << NO_COLOR << endl;
}

void Console::begin(){
    clrscr();
    cout << "WELCOME TO CROSSWORDS PUZZLE" << endl;
    cout << "=============================================" << endl;
}