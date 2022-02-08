#include "Menu.h"
#include "UserInput.h"

#include <iostream>
// #define is used to allow us to give a name to a constant value before the program is compiled
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;


//Used to replace 'system("cls")'
void clearScreen()
{
	COORD cursorPosition;

	cursorPosition.X = 0;
	cursorPosition.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

//Prints Main menu
void menu(string arrow, int arrowPos) {
	cout << "*--------------------------------------*" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 0)
		cout << ":            " << arrow << "  Play                 :" << endl;
	else
		cout << ":                 Play                 :" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 1)
		cout << ":            " << arrow << "  Options              :" << endl;
	else
		cout << ":                 Options              :" << endl;
	cout << ":                                      :" << endl;
	if (arrowPos == 2)
		cout << ":            " << arrow << "  Exit                 :" << endl;
	else
		cout << ":                 Exit                 :" << endl;
	cout << ":                                      :" << endl;
	cout << ":     Use Space or Enter to choose     :" << endl;
	cout << ":                                      :" << endl;
	cout << "*--------------------------------------*" << endl;
}

//Choose whether to Play, change Options or Exit
int chooseMenu(string arrow, int arrowPos) {
	while (1) {
		menu(arrow, arrowPos);
		switch (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 2) {
				exit(0);
			}
			break;
		case KEY_UP:
		case 'W':
		case 'w':
			if (arrowPos != 0)
				arrowPos--;
			break;
		case KEY_DOWN:
		case 'S':
		case 's':
			if (arrowPos != 2)
				arrowPos++;
			break;
		}
		clearScreen();
	}
}
//prints Winning text
void winningText() {
	cout << "*-----------------------------------------------------------*" << endl;
	cout << "|  __   __  _______  __   __    _     _  ___   __    _  __  |" << endl;
	cout << "| |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  | |" << endl;
	cout << "| |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  | |" << endl;
	cout << "| |       ||  | |  ||  |_|  |  |       ||   | |       ||  | |" << endl;
	cout << "| |_     _||  |_|  ||       |  |       ||   | |  _    ||__| |" << endl;
	cout << "|   |   |  |       ||       |  |   _   ||   | | | |   | __  |" << endl;
	cout << "|   |___|  |_______||_______|  |__| |__||___| |_|  |__||__| |" << endl;
	cout << "*-----------------------------------------------------------*" << endl;
}