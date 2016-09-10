#include "include/animation.hpp"

class Animation
{
    SpriteSheet *sprite_sheet;
    int sprite_sheet_y;
    int sprite_sheet_x;
    int num_frames;
    int current_elapsed;
    int ms_per_frame;

public:

    Animation(SpriteSheet *sprite_sheet, int sprite_sheet_y, int num_frames, int duration_ms)
    {
        this->sprite_sheet = sprite_sheet;
        this->sprite_sheet_y = sprite_sheet_y;
        this->num_frames = num_frames;
        this->current_elapsed = 0;
        this->sprite_sheet_x = 0;
        this->ms_per_frame = (int)(1.0 * duration_ms / num_frames);
    }

    void step(int elapsed_ms)
    {
        this->current_elapsed += elapsed_ms;
        int frames_elapsed = this->current_elapsed / this->ms_per_frame;

        if (frames_elapsed > 0)
        {
            this->current_elapsed = this->current_elapsed % this->ms_per_frame;
            this->sprite_sheet_x = (this->sprite_sheet_x + frames_elapsed) % this->num_frames;
        }
    }

    void draw(sf::Sprite *sprite)
    {
        sprite_sheet->set_texture(sprite, this->sprite_sheet_x, this->sprite_sheet_y);
    }
};
