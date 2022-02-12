#pragma once
#include <iostream>
#include <string>
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
		void appendNode(NODE* head, string val, int day, int month, int year);

		void removeQuestion(NODE* head);
		void removeSpecialNode(NODE* head, int i, NODE* prev = NULL);
		NODE* removeFirstNode(NODE* head);
		int lengthOfList(NODE head);

		void displayList(NODE head, int i = 1);

		void insertAfter(NODE* head, string valSearch, int val);
		NODE* prependNode(NODE* head, int val);
		bool searchElement(NODE head, string val);
		void displayNode(NODE head, int i, bool year = 0);
		string returnData(NODE head, int i, bool year);
};

void addQuestion(string arrow);
void startQuiz();