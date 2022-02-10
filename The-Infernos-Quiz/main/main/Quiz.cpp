#include "Quiz.h"
#include "UserInput.h"

NODE* head = new NODE;

void NODE::inputQuestion(NODE* head) {
	system("cls");
	string historicalEvent;
	int day, month, year;
	cout << "Input an event:\n";
	cin.clear();
	getline(cin, historicalEvent, '\n');
	cout << "When did the event happen? (dd/mm/yy, 0 if it's unknown)\n";
	cin >> day >> month >> year;
	cin.ignore();

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
	int index, length = lengthOfList(head);;

	if (length == 1) {
		cout << "You cannot remove all events\n";
		system("pause");
	}
	else {

		head->displayList(head);
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

int NODE::lengthOfList(NODE* head) {
	if (head->next != NULL)
		return lengthOfList(head->next) + 1;
	return 1;
}

void NODE::displayList(NODE* head, int i) {
	cout << i << ": " << head->data << " " << head->day << "/" << head->month << "/" << head->year << endl;
	if (head->next != NULL)
		displayList(head->next, i + 1);
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


bool NODE::searchElement(NODE* head, string val) {
	if (head->data == val)
		return true;
	if (head->next == NULL)
		return false;
	return searchElement(head->next, val);
}

NODE::NODE() {
	next = NULL;
}

void addQuestionMenu(string arrow, int arrowPos) {
	cout << "*-------------------------------*" << endl;
	cout << ":                               :" << endl;
	cout << ":   ______ _____ _____ _______  :" << endl;
	cout << ":  |  ____|  __ \\_   _|__   __| :" << endl;
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
		head->displayList(head);

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
				break;
			}
		}
		system("cls");
	}

}