#include <stack>
#include <SFML/Graphics.hpp>
#include "../include/game_state.hpp"
#include "../include/map_game_state.hpp"
#include "../include/event_bus.hpp"

int main()
{
    const int window_width = 1500;
    const int window_height = window_width / 2;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My Window");
    sf::View view(sf::Vector2f(0, (window_height / 2) - (GameObject::base_depth / 2)), sf::Vector2f(window_width, window_height));
    std::stack<GameState *> states;

    window.setView(view);
    states.push(new MapGameState(&window));

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
            else
            {
                states.top()->publish_event(event);
            }
        }

        window.clear(sf::Color::Black);
        states.top()->draw(elapsed.asMilliseconds());
        window.display();
    }

    while (!states.empty())
    {
        delete states.top();
        states.pop();
    }

    return 0;
}
