#include <SFML/Graphics.hpp>
#include "include/map.hpp"

int main()
{
    const int window_width = 1500;
    const int window_height = window_width / 2;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My Window");
    Map map = Map(window_width, 15, 15);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        map.draw(&window, elapsed.asMilliseconds());
        window.display();
    }

    return 0;
}
