#include "../include/map_game_state.hpp"

MapGameState::MapGameState(sf::RenderWindow *window) : GameState(window)
{
    this->map = new Map(this->window->getSize().x, 15, 15);
    this->event_bus.subscribe(sf::Event::EventType::KeyPressed, this, &MapGameState::handle_key_pressed);
}

void MapGameState::handle_key_pressed(sf::Event event)
{
    for(int i = 0; i < this->map->get_tiles().size(); i++)
    {
        this->map->get_tiles()[i]->set_color(rand());
    }
}

void MapGameState::draw(int elapsed_ms)
{
    this->map->draw(this->window, elapsed_ms);
}

MapGameState::~MapGameState()
{
    delete this->map;
}
