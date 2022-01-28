#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1180, 820), "HISTORY QUIZ");
	Menu menu(window.getSize().x, window.getSize().y);
	sf::Texture texture;

	if (!texture.loadFromFile("textures/history.jpg"))
	{
		std::cout << "Could not load texture";
	}

	sf::Sprite sprite;

	sprite.setTexture(texture);

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
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
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

		window.clear();

		window.draw(sprite);

		menu.draw(window);

		window.display();
	}
}