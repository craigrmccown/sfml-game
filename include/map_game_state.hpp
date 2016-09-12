#ifndef MAP_GAME_STATE_HPP
#define MAP_GAME_STATE_HPP

#include <SFML/Window.hpp>
#include "game_state.hpp"
#include "event_bus.hpp"
#include <stdlib.h>
#include "map.hpp"

class MapGameState : public GameState
{
    Map *map;

public:
 
    MapGameState(sf::RenderWindow *window);
    void handle_key_pressed(sf::Event event);
    void draw(int elapsed_ms);
    ~MapGameState();
};

#endif
