#include "UserInput.h"

// #define is used to allow us to give a name to a constant value before the program is compiled

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int userInput() {
	switch (_getch()) {
	case 32:
	case '\r':
		return 0;
		break;
	case KEY_UP:
	case 'W':
	case 'w':
		return 1;
		break;
	case KEY_DOWN:
	case 'S':
	case 's':
		return 2;
		break;
	}
}