#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Could not load font";
	}

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setStyle(sf::Text::Bold);
		menu[i].setCharacterSize(44);
		menu[i].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * (i+1)));
	}

	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");

	menu[1].setString("Options");

	menu[2].setString("Add questions");

	menu[3].setString("Exit");

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}