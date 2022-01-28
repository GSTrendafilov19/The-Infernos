#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Button.h"

void onPlayClick(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}
	sf::Sprite background(texture);

	window.draw(background);
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

	bool checked = false;

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
						checked = true;
						break;
					case 1: // option button
						std::cout << "Option button has been pressed" << std::endl;
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
		if (checked == true)
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