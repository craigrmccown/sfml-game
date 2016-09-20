#ifndef GRASS_TILE_HPP
#define GRASS_TILE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "map_tile.hpp"
#include "texture_manager.hpp"

class GrassTile : public MapTile
{
public:

    GrassTile(TextureManager &texture);
    void draw(sf::RenderWindow &window, int elapsed_ms);
};

#endif
