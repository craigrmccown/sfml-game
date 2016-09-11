#include "../include/animation.hpp"

Animation::Animation(SpriteSheet *sprite_sheet, int sprite_sheet_y, int num_frames, int duration_ms)
{
    this->sprite_sheet = sprite_sheet;
    this->sprite_sheet_y = sprite_sheet_y;
    this->num_frames = num_frames;
    this->duration_ms = duration_ms;
    this->current_elapsed = 0;
    this->sprite_sheet_x = 0;
    this->ms_per_frame = (int)(1.0 * duration_ms / num_frames);
}

void Animation::increase_duration(int amount_ms)
{
    int new_duration = this->duration_ms + amount_ms;

    if (new_duration > 10000)
    {
        new_duration = 10000;
    }

    this->duration_ms = new_duration;

    int new_val = (int)(1.0 * new_duration / num_frames);

    this->ms_per_frame = new_val;
}

void Animation::decrease_duration(int amount_ms)
{
    int new_duration = this->duration_ms - amount_ms;

    if (new_duration < 100)
    {
        new_duration = 100;
    }

    this->duration_ms = new_duration;

    int new_val = (int)(1.0 * new_duration / num_frames);

    this->ms_per_frame = new_val;
}

void Animation::step(int elapsed_ms)
{
    this->current_elapsed += elapsed_ms;
    int frames_elapsed = this->current_elapsed / this->ms_per_frame;

    if (frames_elapsed > 0)
    {
        this->current_elapsed = this->current_elapsed % this->ms_per_frame;
        this->sprite_sheet_x = (this->sprite_sheet_x + frames_elapsed) % this->num_frames;
    }
}

void Animation::draw(sf::Sprite *sprite)
{
    sprite_sheet->set_texture(sprite, this->sprite_sheet_x, this->sprite_sheet_y);
}
