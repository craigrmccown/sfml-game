#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include "map_tile.hpp"
#include "grass_tile.hpp"
#include "water_tile.hpp"

class Map
{
    int num_tiles_y;
    int num_tiles_x;
    std::vector<MapTile *> tiles;
    std::vector<sf::Texture *> textures;

public:

    Map(int map_width, int num_tiles_x, int num_tiles_y);
    void draw(sf::RenderWindow *window, int elapsed_ms);
    ~Map();
};

#endif
