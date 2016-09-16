#include "../include/map_game_state.hpp"
#include <iostream>

MapGameState::MapGameState(sf::RenderWindow *window) : GameState(window)
{
    /* TODO fix memory leak */
    sf::Texture *player_texture = new sf::Texture();
    player_texture->loadFromFile("assets/player.png");

    this->map = new Map(15, 15);
    this->player = new Player(player_texture);
    this->player->set_position(0, 0, 1);
    this->event_bus.subscribe(sf::Event::EventType::KeyPressed, this, &MapGameState::handle_key_pressed);
}

void MapGameState::handle_key_pressed(sf::Event event)
{
    this->player->walk();
}

void MapGameState::draw(int elapsed_ms)
{
    this->map->draw(this->window, elapsed_ms);
    this->player->draw(this->window, elapsed_ms);
}

MapGameState::~MapGameState()
{
    delete this->map;
    delete this->player;
}
