#include "Options.h"
#include "SFML/Graphics.hpp"
#include <iostream>

void Options(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}
	sf::Sprite background(texture);

	window.draw(background);
}