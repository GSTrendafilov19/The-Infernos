#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

void startQuiz();

struct NODE {
	std::string val;
	NODE* next;
};