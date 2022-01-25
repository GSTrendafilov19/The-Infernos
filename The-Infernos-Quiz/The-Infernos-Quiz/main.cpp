#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "This is the title");
    window.setFramerateLimit(60);

    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(sf::Vector2f(50, 50));

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rect.move(0, -5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rect.move(0, 5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rect.move(-5, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rect.move(5, 0);
        }


        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {


                window.close();


            }
        }

        window.clear();

        window.draw(rect);

        window.display();
    }

    return 0;
}