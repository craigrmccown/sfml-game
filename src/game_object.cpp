#include "../include/game_object.hpp"

GameObject::GameObject(int width, int depth, int height)
{
    this->width = width;
    this->depth = depth;
    this->height = height;

    this->sprite.setOrigin(sf::Vector2f(0, 0 - height));
}

void GameObject::set_position(float x, float y, float z)
{
    int x_pos = (int)((x - y - 1) * (GameObject::tile_width / 2) - this->width - 2);
    int y_pos = (int)((x + y) * (GameObject::tile_depth / 2) - (GameObject::tile_height * z));
    this->sprite.setPosition(sf::Vector2f(x_pos, y_pos));
}
