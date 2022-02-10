#include "Quiz.h"

NODE* head = new NODE;

void NODE::inputQuestion(NODE* head) {
	cout << "Input question:\n";
	cin >> head->data;
	cout << "What year did the event happen? (dd/mm/yy)\n";
	cin >> head->day >> head->month >> head->year;
}


void NODE::removeSpecialNode(NODE* head, string val, NODE* prev) {
	if (head->data == val)
		prev->next = head->next;
	else
		removeSpecialNode(head->next, val, head);
}

void NODE::appendNode(NODE* head, string val) {
	if (head->next == NULL) {
		head->next = new NODE;
		head->next->data = val;
		head->next->next = NULL;
	}
	else
		appendNode(head->next, val);
}

void displayList(NODE* head) {
	cout << head->data << " ";
	if (head->next != NULL)
		displayList(head->next);
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

void startQuiz() {

}

void addQuestion() {
	system("cls");
	head->inputQuestion(head);
}