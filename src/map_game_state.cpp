#include "../include/map_game_state.hpp"

MapGameState::MapGameState(sf::RenderWindow *window) : GameState(window)
{
    this->map = new Map(this->window->getSize().x, 15, 15);
}

void MapGameState::draw(int elapsed_ms)
{
    this->map->draw(this->window, elapsed_ms);
}

void MapGameState::publish_event(sf::Event event)
{

}

MapGameState::~MapGameState()
{
    delete this->map;
}
