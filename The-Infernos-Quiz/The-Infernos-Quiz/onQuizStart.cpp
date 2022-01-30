#include <iostream>
#include "SFML/Graphics.hpp"

void onQuizStart(sf::RenderWindow& window)
{
	std::cout << "working";
	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Coudldn't load the file";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Which event in the bulgarian history has happend the following year? ");
	text.setCharacterSize(44);
	text.setFillColor(sf::Color::Red);

	window.clear();

	window.draw(text);

	//window.draw(background);
}