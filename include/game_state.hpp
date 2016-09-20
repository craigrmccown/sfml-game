#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "event_bus.hpp"
#include "texture_manager.hpp"

class GameState
{

protected:

    sf::RenderWindow &window;
    TextureManager &texture_manager;

public:

    EventBus event_bus;

    GameState(sf::RenderWindow &window, TextureManager &texture_manager);
    virtual void draw(int elapsed_ms) = 0;
};

#endif
