#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game_object.hpp"
#include "texture_manager.hpp"

class Map
{
    std::map<int, std::vector<std::shared_ptr<GameObject>>> map;

public:

    Map(const TextureManager& texture_manager, int num_tiles_x, int num_tiles_y);
    void draw(sf::RenderWindow& window, int elapsed_ms);
};

#endif
