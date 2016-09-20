#ifndef MAP_GAME_STATE_HPP
#define MAP_GAME_STATE_HPP

#include <stdlib.h>
#include <SFML/Window.hpp>
#include "texture_manager.hpp"
#include "game_state.hpp"
#include "event_bus.hpp"
#include "map.hpp"
#include "player.hpp"

class MapGameState : public GameState
{
    Map map;
    Player player;

public:
 
    MapGameState(sf::RenderWindow &window, TextureManager &texture_manager);
    void handle_key_pressed(sf::Event event);
    void draw(int elapsed_ms);
};

#endif
