#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include <SFML/Graphics.hpp>

class SpriteSheet
{
    sf::Texture *texture;
    int sprite_width;
    int sprite_height;

public:

    SpriteSheet(sf::Texture *texture, int sprite_width, int sprite_height);
    void set_texture(sf::Sprite *sprite, int x, int y);

};

#endif
