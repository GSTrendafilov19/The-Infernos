#include "Menu.h"
#include "UserInput.h"

void menuNew(string arrow, int arrowPos) {
	cout << "*--------------------------------------*" << endl;
	cout << ":                                      :" << endl;
	cout << ":  __   __  _______  _______  _______  :" << endl;
	cout << ": |  |_|  ||   _   ||       ||       | :" << endl;
	cout << ": |       ||  |_|  ||____   ||    ___| :" << endl;
	cout << ": |       ||       | ____|  ||   |___  :" << endl;
	cout << ": |       ||       || ______||    ___| :" << endl;
	cout << ": | ||_|| ||   _   || |_____ |   |___  :" << endl;
	cout << ": |_|   |_||__| |__||_______||_______| :" << endl;
	cout << ":                                      :" << endl;
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

void helpMenu() {
	cout << "placeholder for how and why this is";
	cout << "\n\npress any key to go back";
	userInput();
}

void optionsDisplay(string str, bool chosen) {
	//error handler
	HANDLE hdlOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hdlOut == INVALID_HANDLE_VALUE)
	{
		cerr << "Encountered an Error: " << GetLastError();
		system("cls");
	}
	//highlit the chosen text
	if (chosen)
		SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << str << endl;
	SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void menu() {
	int choice = 0;
	bool running = true;
	while (running) {
		system("cls");
		//options
		optionsDisplay("Play", choice == 0);
		optionsDisplay("Help", choice == 1);
		optionsDisplay("Add questions", choice == 2);
		optionsDisplay("Exit", choice == 3);

		//take user input
		int input = userInput();
		if (input == 0 && choice != 0)
			choice--;
		if (input == 2 && choice != 3)
			choice++;

		//select an option
		if (input == -2) {
			system("cls");
			switch (choice) {
				case 0:
					//start the quiz
					break;
				case 1:
					helpMenu();
					break;
				case 2:
					//add questions menu
					break;
				case 3:
					running = false;
					break;
			}
		}
	}
}