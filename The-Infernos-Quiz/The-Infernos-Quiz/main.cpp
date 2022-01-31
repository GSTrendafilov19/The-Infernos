#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Quiz.h"
#include "Options.h"


void startQuiz(sf::RenderWindow& window);
void Options(sf::RenderWindow& window);

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

	sf::String playerInput;
	sf::Text playerText;

	bool checkPlay = false;
	bool checkOptions = false;
	bool quickCheck = false;

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
			startQuiz(window);
		}
		else {
			window.draw(sprite);
			menu.draw(window);
		}

		if (checkOptions == true)
		{
			Options(window);
		}
		window.display();
	}
}