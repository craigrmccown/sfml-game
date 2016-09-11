#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "map_tile.hpp"
#include "grass_tile.hpp"
#include "water_tile.hpp"

class Map
{
    int map_width;
    std::vector<MapTile *> tiles;
    std::vector<sf::Texture *> textures;

    void set_tile_position(MapTile *tile, int x, int y, int z);

public:

    Map(int map_width, int num_tiles_x, int num_tiles_y);
    void draw(sf::RenderWindow *window, int elapsed_ms);
    ~Map();
};

#endif
