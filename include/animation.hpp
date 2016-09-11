#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include "sprite_sheet.hpp"

class Animation
{
    SpriteSheet *sprite_sheet;
    int sprite_sheet_y;
    int sprite_sheet_x;
    int num_frames;
    int duration_ms;
    int current_elapsed;
    int ms_per_frame;

public:

    Animation(SpriteSheet *sprite_sheet, int sprite_sheet_y, int num_frames, int duration_ms);
    void increase_duration(int amount_ms);
    void decrease_duration(int amount_ms);
    void step(int elapsed_ms);
    void draw(sf::Sprite *sprite);
};

#endif
