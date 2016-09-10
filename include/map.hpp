#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

class Map
{
public:

    Map(int map_width, int num_tiles_x, int num_tiles_y);
    void draw(sf::RenderWindow *window, int elapsed_ms);
    ~Map();
};

#endif
