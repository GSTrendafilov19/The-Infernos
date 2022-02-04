#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Quiz.h"
#include "Options.h"
#include "Textbox.h"


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

	sf::Font arial;
	arial.loadFromFile("font/arial.ttf");
	Textbox textbox1(15, sf::Color::White,true);
	textbox1.setFont(arial);
	textbox1.setPosition({ 100,100 });

	bool checkPlay = false;
	bool checkOptions = false;
	bool checkAddQuestion = false;

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
						checkPlay = true;
						break;
					case 1: // option button
						checkOptions = true;
						break;
					case 2: // add question
						checkAddQuestion = true;
						break;
					case 3: // exit button
						window.close();
						break;

					}

					break;
				}
				break;
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::TextEntered:
				textbox1.typedOn(event);
			}
		}

		if (checkPlay == true)
		{
			startQuiz(window);
			textbox1.drawTo(window);
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