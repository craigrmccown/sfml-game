#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "event_bus.hpp"

class GameState
{

protected:

    sf::RenderWindow *window;

public:

    GameState(sf::RenderWindow *window);
    virtual void draw(int elapsed_ms) = 0;
    virtual void publish_event(sf::Event event);
    virtual ~GameState();
};

#endif
