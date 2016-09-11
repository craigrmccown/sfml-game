#ifndef MAP_GAME_STATE_HPP
#define MAP_GAME_STATE_HPP

#include "game_state.hpp"
#include "map.hpp"

class MapGameState : public GameState
{
    Map *map;

public:

    MapGameState(sf::RenderWindow *window);
    void draw(int elapsed_ms);
    ~MapGameState();

};

#endif
