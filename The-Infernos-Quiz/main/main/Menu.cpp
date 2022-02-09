#include <iostream>

#include "Menu.h"
#include "UserInput.h"
// #define is used to allow us to give a name to a constant value before the program is compiled
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void chooseMenu(string arrow, int arrowPos = 0);
void chooseOptions(string arrow, int arrowPos = 0);

//Used to replace 'system("cls")' in order to reduce flickering
void clearScreen()
{
	COORD cursorPosition;

	cursorPosition.X = 0;
	cursorPosition.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

}

//Prints Main menu
void menu(string arrow, int arrowPos) {
	cout << "*------------------------------------------*" << endl;
	cout << ":                                          :" << endl;
	cout << ":   *******      **     **   **   ******** :" <<  endl;
	cout << ":  **/////**    /**    /**  /**  //////**  :" << endl;
	cout << ": **     //**   /**    /**  /**       **   :" << endl;
	cout << ":/**      /**   /**    /**  /**      **    :" << endl;
	cout << ":/**    **/**   /**    /**  /**     **     :" << endl;
	cout << "://**  // **    /**    /**  /**    **      :" << endl;
	cout << ": //******* **  //*******   /**   ******** :" << endl;
	cout << ":  /////// //    ///////    //   ////////  :" << endl;
	cout << ":                                          :" << endl;

	if (arrowPos == 0)
	cout << ":            " << arrow << "  Play                     :" << endl;
	else
	cout << ":                 Play                     :" << endl;
	cout << ":                                          :" << endl;
	if (arrowPos == 1)
	cout << ":            " << arrow << "  Options                  :" << endl;
	else
	cout << ":                 Options                  :" << endl;
	cout << ":                                          :" << endl;
	if (arrowPos == 2)
	cout << ":            " << arrow << "  Exit                     :" << endl;
	else
	cout << ":                 Exit                     :" << endl;
	cout << ":                                          :" << endl;
	cout << ":        / Use Enter to choose /           :" << endl;
	cout << ":                                          :" << endl;
	cout << "*------------------------------------------*" << endl;
}

void options(string arrow, int arrowPos) {
	cout << "*--------------------------------------------------------------*" << endl;
	cout << ":                                                              :" << endl;
	cout << ":  _______  _______  _______  ___   _______  __    _  _______  :" << endl;
	cout << ": |       ||       ||       ||   | |       ||  |  | ||       | :" << endl;
	cout << ": |   _   ||    _  ||_     _||   | |   _   ||   |_| ||  _____| :" << endl;
	cout << ": |  | |  ||   |_| |  |   |  |   | |  | |  ||       || |_____  :" << endl;
	cout << ": |  |_|  ||    ___|  |   |  |   | |  |_|  ||  _    ||_____  | :" << endl;
	cout << ": |       ||   |      |   |  |   | |       || | |   | _____| | :" << endl;
	cout << ": |_______||___|      |___|  |___| |_______||_|  |__||_______| :" << endl;
	cout << ":                                                              :" << endl;
	cout << ":                                                              :" << endl;
	if (arrowPos == 0)
		cout << ":                       " << arrow << "  Color                             :" << endl;
	else
		cout << ":                            Color                             :" << endl;
	cout << ":                                                              :" << endl;
	if (arrowPos == 1)
		cout << ":                       " << arrow << "  Back                              :" << endl;
	else
		cout << ":                            Back                              :" << endl;
	cout << ":                                                              :" << endl;
	cout << ":                   / Use Enter to choose /                    :" << endl;
	cout << ":                                                              :" << endl;
	cout << "*--------------------------------------------------------------*" << endl;
}
void colorMenu(string arrow, int arrowPos) {
	cout << "*---------------------------------------------------------*" << endl;
	cout << ":                                                         :" << endl;
	cout << ":  _______  _______  ___      _______  ______    _______  :" << endl;
	cout << ": |       ||       ||   |    |       ||    _ |  |       | :" << endl;
	cout << ": |       ||   _   ||   |    |   _   ||   | ||  |  _____| :" << endl;
	cout << ": |       ||  | |  ||   |    |  | |  ||   |_||_ | |_____  :" << endl;
	cout << ": |      _||  |_|  ||   |___ |  |_|  ||    __  ||_____  | :" << endl;
	cout << ": |     |_ |       ||       ||       ||   |  | | _____| | :" << endl;
	cout << ": |_______||_______||_______||_______||___|  |_||_______| :" << endl;
	cout << ":                                                         :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 0)
		cout << ":                     " << arrow << "  Aqua                           :" << endl;
	else
		cout << ":                          Aqua                           :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 1)
		cout << ":                     " << arrow << "  Green                          :" << endl;
	else
		cout << ":                          Green                          :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 2)
		cout << ":                     " << arrow << "  Red                            :" << endl;
	else
		cout << ":                          Red                            :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 3)
		cout << ":                     " << arrow << "  Purple                         :" << endl;
	else
		cout << ":                          Purple                         :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 4)
		cout << ":                     " << arrow << "  White                          :" << endl;
	else
		cout << ":                          White                          :" << endl;
	cout << ":                                                         :" << endl;
	if (arrowPos == 5)
		cout << ":                     " << arrow << "  Back                           :" << endl;
	else
		cout << ":                          Back                           :" << endl;
	cout << ":                                                         :" << endl;
	cout << ":                 / Use Enter to choose /                 :" << endl;
	cout << ":                                                         :" << endl;
	cout << "*---------------------------------------------------------*" << endl;
}
int chooseColor(string arrow, int arrowPos = 0) {
	while (1) {
		colorMenu(arrow, arrowPos);
		int input = userInput();
		//Move the arrow position
		if (input == 1 && arrowPos != 0)
			arrowPos--;
		if (input == 2 && arrowPos != 5)
			arrowPos++;

		//select an option
		if (input == 0) {
			switch (arrowPos) {
			case 0:
				system("color 3");
				break;
			case 1:
				system("color 2");
				break;
			case 2:
				system("color 4");
				break;
			case 3:
				system("color 5");
				break;
			case 4:
				system("color 7");
				break;
			case 5:
				system("cls");
				chooseOptions(arrow);
				break;
			}
		}

		/* (_getch()) {
		case 32:
		case '\r':
			if (arrowPos == 0) {
				system("color 3");
			}
			else if (arrowPos == 1) {
				system("color 2");
			}
			else if (arrowPos == 2) {
				system("color 4");
			}
			else if (arrowPos == 3) {
				system("color 5");
			}
			else if (arrowPos == 4) {
				system("color 7");
			}
			else if (arrowPos == 5) {
				system("cls");
				return 0;
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
			if (arrowPos != 5)
				arrowPos++;
			break;
		}*/
		clearScreen();
	}
}

void chooseOptions(string arrow, int arrowPos) {
	while (1) {
		options(arrow, arrowPos);
		int input = userInput();

		//Move the arrow position
		if (input == 1 && arrowPos != 0)
			arrowPos--;
		if (input == 2 && arrowPos != 1)
			arrowPos++;

		//select an option
		if (input == 0) {
			switch (arrowPos) {
			case 0:
				system("cls");
				chooseColor(arrow);
				break;
			case 1:
				system("cls");
				chooseMenu(arrow);
				break;
			}
		}

		clearScreen();
	}
}


//Choose whether to Play, change Options or Exit
void chooseMenu(string arrow, int arrowPos) {
	while (1) {
		menu(arrow, arrowPos);
		int input = userInput();

		//Move the arrow position
		if (input == 1 && arrowPos != 0)
			arrowPos--;
		if (input == 2 && arrowPos != 2)
			arrowPos++;

		//select an option
		if (input == 0) {
			switch (arrowPos) {
			case 0:
				//play quiz
				break;
			case 1:
				system("cls");
				chooseOptions(arrow);
				break;
			case 2:
				exit(0);
			}
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