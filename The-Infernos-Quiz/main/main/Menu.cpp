#include <iostream>

#include "Menu.h"
#include "UserInput.h"
#include "Quiz.h"

// #define is used to allow us to give a name to a constant value before the program is compiled
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void chooseMenu(string arrow, int arrowPos = 0);
void chooseOptions(string arrow, int arrowPos = 0);


/// <summary>
/// Used to replace 'system("cls")' in order to reduce flickering
/// </summary>
void clearScreen()
{
	COORD cursorPosition;

	cursorPosition.X = 0;
	cursorPosition.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

}

/// <summary>
/// Prints the main menu and handles selection of options
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
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


/// <summary>
/// Prints the options menu and handles selection of settings
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
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
		cout << ":                       " << arrow << "  Add questions                     :" << endl;
	else
		cout << ":                            Add questions                     :" << endl;
	cout << ":                                                              :" << endl;

	if (arrowPos == 1)
		cout << ":                       " << arrow << "  Color                             :" << endl;
	else
		cout << ":                            Color                             :" << endl;
	cout << ":                                                              :" << endl;

	if (arrowPos == 2)
		cout << ":                       " << arrow << "  Back                              :" << endl;
	else
		cout << ":                            Back                              :" << endl;
	cout << ":                                                              :" << endl;
	cout << ":                   / Use Enter to choose /                    :" << endl;
	cout << ":                                                              :" << endl;
	cout << "*--------------------------------------------------------------*" << endl;
}


/// <summary>
/// Prints the colors menu and handles their selection
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
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


/// <summary>
/// Handles the logic of the color menu
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
void chooseColor(string arrow, int arrowPos = 0) {
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

		clearScreen();
	}
}

/// <summary>
/// Handles the logic of the options menu
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
void chooseOptions(string arrow, int arrowPos) {
	while (1) {
		options(arrow, arrowPos);
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
				system("cls");
				addQuestion(arrow);
				break;
			case 1:
				system("cls");
				chooseColor(arrow);
				break;
			case 2:
				system("cls");
				chooseMenu(arrow);
				break;
			}
		}

		clearScreen();
	}
}


/// <summary>
/// Handles the logic of the main menu
/// </summary>
/// <param name="arrow">the highliter which shows you that you've selected an option</param>
/// <param name="arrowPos">the position of the highliter</param>
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
				system("cls");
				startQuiz();
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