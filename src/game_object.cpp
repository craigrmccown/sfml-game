#include "../include/game_object.hpp"

GameObject::GameObject(int width, int depth, int height)
{
    this->width = width;
    this->depth = depth;
    this->height = height;

    this->sprite.setOrigin(sf::Vector2f(width / 2, height + depth / 2));
}

void GameObject::set_position(float x, float y, float z)
{
    int x_pos = (int)((x - y) * (GameObject::base_width / 2));
    int y_pos = (int)((x + y) * (GameObject::base_depth / 2) - (GameObject::base_height * z));
    this->sprite.setPosition(sf::Vector2f(x_pos, y_pos));
}

void GameObject::set_color(int color)
{
    this->sprite.setColor(sf::Color(color));
}
