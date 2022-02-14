#include "Quiz.h"
#include "UserInput.h"
#include "grand.h"

void clearScreen();

NODE* head = new NODE;
string answers[4];

/// <summary>
/// A member function that handles the input of questions
/// </summary>
/// <param name="head">the head of the linked list</param>
void NODE::inputQuestion(NODE* head) {
	system("cls");
	string historicalEvent;
	int day, month, year;
	cout << "Input an event:\n";
	//handle residual input
	cin.ignore();
	getline(cin, historicalEvent, '\n');
	cout << "When did the event happen? (dd/mm/yyyy, 0 if it's unknown)\n";
	cin >> day >> month >> year;

	//check date validity
	if (day < 0 || day > 31 || month < 0 || month > 12 || year < 1 || year > 2022) {
		cout << "Incorrect date\n";
		system("pause");
		inputQuestion(head);
	}
	else
		head->appendNode(head, historicalEvent, day, month, year);
}

/// <summary>
/// A function that appends an element to a given linked list
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <param name="val">the event to be appended</param>
/// <param name="day">the day to be appended</param>
/// <param name="month">the month to be appended</param>
/// <param name="year">the year to be appended</param>
void NODE::appendNode(NODE* head, string val, int day, int month, int year) {
	if (head->next == NULL) {
		head->next = new NODE;
		head->next->data = val;
		head->next->day = day;
		head->next->month = month;
		head->next->year = year;
		head->next->next = NULL;
	}
	else
		appendNode(head->next, val, day, month, year);
}

/// <summary>
/// A member function that handles the removal of questions
/// </summary>
/// <param name="head">the head of the linked list</param>
void NODE::removeQuestion(NODE* head) {
	system("cls");
	int index, length = lengthOfList(*head);;
	//check quiz eligibility
	if (length == 1) {
		cout << "You cannot remove all events\n";
		system("pause");
	}
	else {

		head->displayList(*head);
		cout << "Which event do you want to remove?\n";
		cin >> index;

		//check for proper index
		if (index <= length) {
			if (index == 1)
				*head = *head->removeFirstNode(head);
			else
				head->removeSpecialNode(head, index);
		}
		else {
			cout << "Incorrect event index\n";
			system("pause");
			removeQuestion(head);
		}
	}
}


/// <summary>
/// A function that removes an element to a given linked list
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <param name="i">the index of the element to be removed</param>
/// <param name="prev">a temporary node, used to hold the previous node's information</param>
void NODE::removeSpecialNode(NODE* head, int i, NODE* prev) {
	if (i == 1) {
		prev->next = head->next;
		delete head;
	}
	else
		removeSpecialNode(head->next, i-1, head);
}

/// <summary>
/// A memeber function that removes the last node of a list
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <returns>returns the new head</returns>
NODE* NODE::removeFirstNode(NODE* head) {
	return head->next;
}


/// <summary>
/// A function that returns the lenght of a linked list
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <returns>returns the length of the list</returns>
int NODE::lengthOfList(NODE head) {
	if (head.next != NULL)
		return lengthOfList(*(head.next)) + 1;
	return 1;
}

/// <summary>
/// Outputs a given list
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <param name="i">the index of the item</param>
void NODE::displayList(NODE head, int i) {
	cout << i << ": " << head.data << " " << head.day << "/" << head.month << "/" << head.year << endl;
	if (head.next != NULL)
		displayList(*(head.next), i + 1);
}

/// <summary>
/// Displays a given node
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <param name="i">the index of the node to be displayed</param>
/// <param name="year">a boolean value which indicate whether to display the date or the event</param>
void NODE::displayNode(NODE head, int i, bool year) {
	if (i == 0) {
		if (year)
			cout << head.day << "/" << head.month << "/" << head.year;
		else
			cout << head.data;
	}
	else
		head.displayNode(*(head.next), i - 1, year);
}


/// <summary>
/// A simple function that returns the requested data from a node
/// </summary>
/// <param name="head">the head of a linked list</param>
/// <param name="i">the index of the node</param>
/// <param name="year">a boolean value which indicate whether to return the date or the event</param>
/// <returns>a string value of the event or year</returns>
string NODE::returnData(NODE head, int i, bool year) {
	//return the date or event
	if (i != 0)
		return head.returnData(*(head.next), i - 1, year);
	else {
		if (year)
			return (to_string(head.day) + '/' + to_string(head.month) + '/' + to_string(head.year));
		else
			return head.data;
	}
}

/// <summary>
/// Constructor to the class NODE
/// </summary>
NODE::NODE() {
	next = NULL;
}

/// <summary>
/// Displays the menu for adding questions
/// </summary>
/// <param name="arrow">the highliter that shows which item has been selected</param>
/// <param name="arrowPos">the position of the highlited</param>
void addQuestionMenu(string arrow, int arrowPos) {
	cout << "*-------------------------------*                        " << endl;
	cout << ":                               :                        " << endl;
	cout << ":   ______ _____ _____ _______  :                        " << endl;
	cout << ":  |  ____|  __ \\_   _|__   __| :                       " << endl;
	cout << ":  | |__  | |  | || |    | |    :" << endl;
	cout << ":  |  __| | |  | || |    | |    :" << endl;
	cout << ":  | |____| |__| || |_   | |    :" << endl;
	cout << ":  |______|_____/_____|  |_|    :" << endl;
	cout << ":                               :" << endl;
	cout << ":                               :" << endl;
	if (arrowPos == 0)
		cout << ":     " << arrow << "  Add question         :" << endl;
	else
		cout << ":          Add question         :" << endl;
	cout << ":                               :" << endl;
	if (arrowPos == 1)
		cout << ":     " << arrow << "  Remove question      :" << endl;
	else
		cout << ":          Remove question      :" << endl;
	cout << ":                               :" << endl;

	if (arrowPos == 2)
		cout << ":     " << arrow << "  Back                 :" << endl;
	else
		cout << ":          Back                 :" << endl;
	cout << ":                               :" << endl;
	cout << ":     / Use Enter to choose /   :" << endl;
	cout << ":                               :" << endl;
	cout << "*-------------------------------*" << endl;
}

/// <summary>
/// The logic behind the add questions menu
/// </summary>
/// <param name="arrow">the highliter used to show which item has been selected</param>
void addQuestion(string arrow) {
	int arrowPos = 0;
	int running = true;

	//default event
	head->data = "Creation of the first bulgarian kingdom";
	head->day = 0;
	head->month = 0;
	head->year = 681;

	while (running) {
		addQuestionMenu(arrow, arrowPos);
		cout << "\n\n";
		head->displayList(*head);

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
				head->inputQuestion(head);
				break;
			case 1:
				head->removeQuestion(head);
				break;
			case 2:
				running = false;
				system("cls");
				break;
			}
		}
		clearScreen();
	}

}

/// <summary>
/// A function that highlits the requested item
/// </summary>
/// <param name="str">the string to be highlited</param>
/// <param name="chosen">a boolean value that dictates whether the string is highlited</param>
void highlightOption(string str, bool chosen) {
	//highlight the chosen text
	if (chosen)
		cout << "-->";
	cout << str << endl;
}

/// <summary>
/// Checks an array of strings for another string
/// </summary>
/// <param name="str">The string that's compared to the array</param>
/// <param name="answ">The array</param>
/// <returns>returnst a boolean value</returns>
bool checkArr(string str, string answ[]) {
	for (int i = 0; i < 4; i++) {
		if (answers[i] == str)
			return true;
	}
	return false;
}

/// <summary>
/// A function that fills an array with answers for the next rotation of questions
/// </summary>
/// <param name="head">the head of the linked list</param>
/// <param name="question">the index of the question</param>
/// <param name="rand">a random variable</param>
/// <param name="answerPos">the position of the correct answer</param>
/// <param name="year">a boolean value that dictates whether the question is about an event or a date</param>
void answerOptions(NODE head, int question, GRand rand, int answerPos, bool year = false) {
	for (int i = 0; i < 4; i++)
		answers[i] = "";

	for(int i = 0; i < 4; i++){
		//check if correct answer should be put in position
		if (i == answerPos)
			answers[i] = head.returnData(head, question, year);
		else {
			int random;
			//retry answers until a new one is recieved
			do {
				random = rand.i(head.lengthOfList(head));
				//prevents displaying of the correct answer again
				while (random == question)
					random = rand.i(head.lengthOfList(head));
			} while (checkArr(head.returnData(head, random, year), answers));
			answers[i] = head.returnData(head, random, year);
		}
	}
}

/// <summary>
/// The main menu for the quiz
/// </summary>
/// <param name="answers">an array with answers to be displayed</param>
/// <param name="answerPos">the position of the correct answer</param>
/// <param name="eventPrompt">a boolean value that dictates what type of prompt will be displayed</param>
/// <param name="head">the head of the linked list</param>
/// <param name="question">the position of the question in the list</param>
void quizMenu(string answers[], int answerPos, bool eventPrompt, NODE head, int question) {
	int arrowPos = 0;
	while (true) {

		//event prompt
		if (eventPrompt)
			cout << "When did the following event occur?\n";
		//date prompt
		else
			cout << "What event occured on the following date?\n";


		head.displayNode(head, question, !eventPrompt);
		cout << endl;

		for (int i = 0; i < 4; i++)
			highlightOption(answers[i], arrowPos == i);
		cout << "\n\n\n";

		highlightOption("Add more questions", arrowPos == 4);

		
		int input = userInput();

		//Move the arrow position
		if (input == 1 && arrowPos != 0)
			arrowPos--;
		if (input == 2 && arrowPos != 4)
			arrowPos++;


		//select an option
		if (input == 0) {
			if (arrowPos == answerPos) {
				system("cls");
				cout << "Correct!\n";
				system("pause");
				break;
			}
			else if (arrowPos == 4) {
				system("cls");
				addQuestion("-->");
			}
			else {
				system("cls");
				cout << "Incorrect. The correct answer was:\n" << answers[answerPos] << endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


/// <summary>
/// A function that kickstarts the quiz
/// </summary>
void startQuiz() {
	int length = head->lengthOfList(*head);
	
	//check if the list is eligible for a quiz
	if (length < 5) {
		cout << "You can't start a quiz with less than 5 questions.\n";
		system("pause");
		system("cls");
	}

	else {
		bool running = true;
		GRand rand;
		while (running) {
			system("cls");
			int question = rand.i(length);
			bool eventPrompt = rand.b();
			int answerPos = rand.i(4);

			answerOptions(*head, question, rand, answerPos, eventPrompt);
			quizMenu(answers, answerPos, eventPrompt, *head, question);
		}
	}
}