#include "Quiz.h"
#include "UserInput.h"
#include "grand.h"

void clearScreen();

NODE* head = new NODE;
string answers[4];

void NODE::inputQuestion(NODE* head) {
	system("cls");
	string historicalEvent;
	int day, month, year;
	cout << "Input an event:\n";
	cin.ignore();
	getline(cin, historicalEvent, '\n');
	cout << "When did the event happen? (dd/mm/yyyy, 0 if it's unknown)\n";
	cin >> day >> month >> year;

	if (day < 0 || day > 31 || month < 0 || month > 12 || year < 1 || year > 2022) {
		cout << "Incorrect date\n";
		system("pause");
		inputQuestion(head);
	}
	else
		head->appendNode(head, historicalEvent, day, month, year);
}


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

void NODE::removeQuestion(NODE* head) {
	system("cls");
	int index, length = lengthOfList(*head);;

	if (length == 1) {
		cout << "You cannot remove all events\n";
		system("pause");
	}
	else {

		head->displayList(*head);
		cout << "Which event do you want to remove?\n";
		cin >> index;

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

void NODE::removeSpecialNode(NODE* head, int i, NODE* prev) {
	if (i == 1) {
		prev->next = head->next;
		delete head;
	}
	else
		removeSpecialNode(head->next, i-1, head);
}

NODE* NODE::removeFirstNode(NODE* head) {
	return head->next;
}

int NODE::lengthOfList(NODE head) {
	if (head.next != NULL)
		return lengthOfList(*(head.next)) + 1;
	return 1;
}

void NODE::displayList(NODE head, int i) {
	cout << i << ": " << head.data << " " << head.day << "/" << head.month << "/" << head.year << endl;
	if (head.next != NULL)
		displayList(*(head.next), i + 1);
}

void NODE::insertAfter(NODE* head, string valSearch, int val) {
	if (head->data == valSearch) {
		NODE* ptr = head->next;
		head->next = new NODE;
		head->next->data = val;
		head->next->next = ptr;
	}
	else
		insertAfter(head->next, valSearch, val);
}

NODE* NODE::prependNode(NODE* head, int val) {
	NODE* ptr = new NODE;
	ptr->data = val;
	ptr->next = head;
	return ptr;
}


bool NODE::searchElement(NODE head, string val) {
	if (head.data == val)
		return true;
	if (head.next == NULL)
		return false;
	return searchElement(*(head.next), val);
}

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

string NODE::returnData(NODE head, int i, bool year) {
	if (i != 0)
		return head.returnData(*(head.next), i - 1, year);
	else {
		if (year)
			return (to_string(head.day) + '/' + to_string(head.month) + '/' + to_string(head.year));
		else
			return head.data;
	}
}

NODE::NODE() {
	next = NULL;
}

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

void addQuestion(string arrow) {
	int arrowPos = 0;
	int running = true;

	//example event
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


void highlightOption(string str, bool chosen) {
	//highlight the chosen text
	if (chosen)
		cout << "-->";
	cout << str << endl;
}

void answerOptions(NODE clone, int question, GRand rand, int answerPos, bool year = false) {
	for(int i = 0; i < 4; i++){
		if (i == answerPos)
			answers[i] = clone.returnData(clone, question, year);
		else {
			int random = rand.i(clone.lengthOfList(clone));
			while(random == question)
				random = rand.i();
			answers[i] = clone.returnData(clone, random, year);
		}
	}
}

void quizMenu(string answers[], int answerPos, bool eventPrompt, NODE clone, int question) {
	int arrowPos = 0;
	while (true) {

		//event prompt
		if (eventPrompt)
			cout << "When did the following event occur?\n";
		//date prompt
		else
			cout << "What event occured on the following date?\n";


		clone.displayNode(clone, question, !eventPrompt);
		cout << endl;

		for (int i = 0; i < 4; i++)
			highlightOption(answers[i], arrowPos == i);

		
		int input = userInput();

		//Move the arrow position
		if (input == 1 && arrowPos != 0)
			arrowPos--;
		if (input == 2 && arrowPos != 3)
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
				//go back
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

void startQuiz() {
	NODE clone = *head;
	int length = clone.lengthOfList(clone);
	//check if the list is eligible for a quiz
	if (length < 5) {
		cout << "You can't start a quiz with less than 5 questions.\n";
		system("pause");
		system("cls");
	}

	else {
		GRand rand;
		bool running = true;
		while (running) {
			system("cls");
			int question = rand.i(length);
			bool eventPrompt = rand.b();
			int answerPos = rand.i(4);

			answerOptions(clone, question, rand, answerPos, eventPrompt);
			quizMenu(answers, answerPos, eventPrompt, clone, question);
		}
	}
}