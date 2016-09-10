#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include <SFML/Graphics.hpp>

class SpriteSheet
{

public:

    SpriteSheet(sf::Texture *texture, int sprite_width, int sprite_height);
    int set_texture(sf::Sprite *sprite, int x, int y);

};

#endif