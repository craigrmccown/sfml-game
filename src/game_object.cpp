#include "include/game_object.hpp"

void GameObject::set_position(int pos_x, int pos_y)
{
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void GameObject::move(float delta_x, float delta_y)
{
    this->sprite.move(delta_x, delta_y);
}
