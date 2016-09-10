#ifndef WATER_TILE_HPP
#define WATER_TILE_HPP

#include <SFML/Graphics.hpp>
#include "map_tile.hpp"

class WaterTile : public MapTile
{
    SpriteSheet *sprite_sheet;
    Animation *animation;

public:

    WaterTile(sf::Texture *texture);
    void draw(sf::RenderWindow *window, int elapsed_ms);
    ~WaterTile();

};

#endif
