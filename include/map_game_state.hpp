#ifndef MAP_GAME_STATE_HPP
#define MAP_GAME_STATE_HPP

#include <SFML/Window.hpp>
#include "game_state.hpp"
#include "map.hpp"

class MapGameState : public GameState
{
    Map *map;

public:

    MapGameState(sf::RenderWindow *window);
    void draw(int elapsed_ms);
    void publish_event(sf::Event event);
    ~MapGameState();
};

#endif
