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

		//memeber functions for adding questions
		void inputQuestion(NODE* head);
		void appendNode(NODE* head, string val, int day, int month, int year);

		//memeber functions for removing questions
		void removeQuestion(NODE* head);
		void removeSpecialNode(NODE* head, int i, NODE* prev = NULL);
		NODE* removeFirstNode(NODE* head);
		int lengthOfList(NODE head);

		//general purpouse member functions
		void displayList(NODE head, int i = 1);
		bool searchElement(NODE head, string val);
		void displayNode(NODE head, int i, bool year = 0);
		string returnData(NODE head, int i, bool year);
};

void addQuestion(string arrow);
void startQuiz();