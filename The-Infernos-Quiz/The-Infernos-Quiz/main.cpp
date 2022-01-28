#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Button.h"

void onPlayClick(sf::RenderWindow& window1)
{
	sf::Texture texture;
	if (!texture.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}
	sf::Sprite background(texture);

	window1.draw(background);
}

void onPlayDisplay()
{
	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Coudldn't load the file";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Which event in the bulgarian history has happend the following year? ");
	text.setFillColor(sf::Color::Red);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1180, 820), "HISTORY QUIZ");
	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture background;
	if (!background.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}

	sf::Sprite sprite;
	sprite.setTexture(background);

	bool checkPlay = false;
	bool checkOptions = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0: // play button
						std::cout << "Play button has been pressed" << std::endl;
						checkPlay = true;
						break;
					case 1: // option button
						std::cout << "Option button has been pressed" << std::endl;
						checkOptions = true;
						break;
					case 2: // exit button
						window.close();
						break;
					}

					break;
				}
				break;
			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		if (checkPlay == true)
		{
			onPlayClick(window);
		}
		else {
			window.draw(sprite);
			menu.draw(window);
		}
		if (checkOptions == true)
		{
			onPlayClick(window);
		}
		else {
			window.draw(sprite);
			menu.draw(window);
		}

		window.display();
		window.clear();
	}
}