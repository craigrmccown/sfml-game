#include "../include/map_game_state.hpp"
#include <iostream>

MapGameState::MapGameState(const TextureManager& texture_manager) :
    map(texture_manager, this->event_bus)
{
    this->event_bus.subscribe(sf::Event::EventType::KeyPressed, this, &MapGameState::handle_key_pressed);
}

void MapGameState::handle_key_pressed(sf::Event event)
{
}

void MapGameState::draw(sf::RenderWindow& window, double elapsed_ms)
{
    this->map.draw(window, elapsed_ms);
}
