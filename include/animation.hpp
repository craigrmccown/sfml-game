#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include "include/sprite_sheet.hpp"

class Animation
{
public:

    Animation(SpriteSheet *sprite_sheet, int sprite_sheet_y, int num_frames, int duration_ms);
    void step(int elapsed_ms);
    void draw(sf::Sprite *sprite);
};

#endif
