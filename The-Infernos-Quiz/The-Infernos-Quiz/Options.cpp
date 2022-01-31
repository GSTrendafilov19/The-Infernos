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

	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Coudldn't load the file";
	}

	sf::Text changeColor;
	changeColor.setFont(font);
	changeColor.setString("Change Color");
	changeColor.setStyle(sf::Text::Bold);
	changeColor.setCharacterSize(44);
	changeColor.setFillColor(sf::Color::White);
	changeColor.setPosition(sf::Vector2f(1030 / 2, 820 / (2 + 1) * 1));

	window.clear();
	window.draw(background);
	window.draw(changeColor);
}