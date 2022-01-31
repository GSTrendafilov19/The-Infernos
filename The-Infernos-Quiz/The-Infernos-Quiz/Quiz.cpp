#include "Quiz.h"
#include "SFML/Graphics.hpp"
#include <iostream>

void startQuiz(sf::RenderWindow& window)
{

	sf::Texture texture;
	if (!texture.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}
	sf::Sprite background(texture);

	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Coudldn't load the file";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Which event in the bulgarian history has happend the following year? ");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);

	window.clear();
	window.draw(background);
	window.draw(text);
}