#include "UserInput.h"

int userInput() {
	//take user input
	int input = _getch();

	switch (input) {
		//up arrow
		case 72:
			return 0;
			break;
		//right arrow
		case 77:
			return 1;
			break;
		//down arrow
		case 80:
			return 2;
			break;
		//left arrow
		case 75:
			return 3;
			break;
		//esc
		case 27:
			return -1;
			break;
		//enter
		case '\r':
			return -2;
			break;
		default:
			return -3;
	}
}