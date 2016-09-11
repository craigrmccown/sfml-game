#ifndef WATER_TILE_HPP
#define WATER_TILE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include "map_tile.hpp"
#include "sprite_sheet.hpp"
#include "animation.hpp"
#include "event_bus.hpp"

class WaterTile : public MapTile
{
    SpriteSheet *sprite_sheet;
    Animation *animation;

public:

    WaterTile(sf::Texture *texture);
    void draw(sf::RenderWindow *window, int elapsed_ms);
    void handle_key_pressed(sf::Event event);
    ~WaterTile();

};

#endif
