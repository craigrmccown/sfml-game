#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "event_bus.hpp"
#include "texture_manager.hpp"

class GameState
{

public:

    EventBus event_bus;
    virtual void draw(sf::RenderWindow& window, int elapsed_ms) = 0;
};

#endif
