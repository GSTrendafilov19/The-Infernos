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

	window.draw(background);
}