#include "../include/map_game_state.hpp"
#include <iostream>

MapGameState::MapGameState(const TextureManager& texture_manager) :
    map(texture_manager, 15, 15),
    player(texture_manager)
{
    this->player.set_position(0, 0, 1);
    this->event_bus.subscribe(sf::Event::EventType::KeyPressed, this, &MapGameState::handle_key_pressed);
}

void MapGameState::handle_key_pressed(sf::Event event)
{
    this->player.walk();
}

void MapGameState::draw(sf::RenderWindow& window, int elapsed_ms)
{
    this->map.draw(window, elapsed_ms);
    this->player.draw(window, elapsed_ms);
}
