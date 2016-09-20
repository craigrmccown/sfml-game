#include "../include/map_game_state.hpp"
#include <iostream>

MapGameState::MapGameState(sf::RenderWindow &window, TextureManager &texture_manager) :
    map(Map(texture_manager, 15, 15)),
    player(Player(texture_manager)),
    GameState(window, texture_manager)
{
    this->player.set_position(0, 0, 1);
    this->event_bus.subscribe(sf::Event::EventType::KeyPressed, this, &MapGameState::handle_key_pressed);
}

void MapGameState::handle_key_pressed(sf::Event event)
{
    this->player.walk();
}

void MapGameState::draw(int elapsed_ms)
{
    this->map.draw(this->window, elapsed_ms);
    this->player.draw(this->window, elapsed_ms);
}
