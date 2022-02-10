#pragma once
#include <iostream>
using namespace std;

class NODE {
	public:
		NODE();

		string data;
		int year;
		int month;
		int day;
		NODE* next;

		void inputQuestion(NODE* head);
		void removeSpecialNode(NODE* head, string val, NODE* prev = NULL);
		void appendNode(NODE* head, string val);
		void displayList(NODE* head);
		void insertAfter(NODE* head, string valSearch, int val);
		NODE* prependNode(NODE* head, int val);
		bool searchElement(NODE* head, string val);
};

void addQuestion();