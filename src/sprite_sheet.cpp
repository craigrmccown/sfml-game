#include "include/sprite_sheet.hpp"

SpriteSheet::SpriteSheet(sf::Texture *texture, int sprite_width, int sprite_height)
{
    this->texture = texture;
    this->sprite_width = sprite_width;
    this->sprite_height = sprite_height;
}

int SpriteSheet::set_texture(sf::Sprite *sprite, int x, int y)
{
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(x * this->sprite_width, y * this->sprite_height, sprite_width, sprite_height));
}
