#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "map_tile.hpp"
#include "grass_tile.hpp"
#include "texture_manager.hpp"

class Map
{
    std::vector<std::unique_ptr<MapTile>> tiles;

public:

    Map(const TextureManager& texture_manager, int num_tiles_x, int num_tiles_y);
    void draw(sf::RenderWindow& window, double elapsed_ms);
};

#endif
