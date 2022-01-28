#include "Quiz.h"
#include "SFML/Graphics.hpp"

void startQuiz() {
    sf::Window window(sf::VideoMode(1180, 820), "Quiz");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }
}