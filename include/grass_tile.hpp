#ifndef GRASS_TILE_HPP
#define GRASS_TILE_HPP

#include <SFML/Graphics.hpp>
#include "map_tile.hpp"

class GrassTile : public MapTile
{
public:

    GrassTile(sf::Texture *texture);
    void draw(sf::RenderWindow *window, int elapsed_ms);
};

#endif
