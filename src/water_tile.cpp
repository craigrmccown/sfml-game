#include "../include/water_tile.hpp"

WaterTile::WaterTile(sf::Texture *texture)
{
    this->sprite_sheet = new SpriteSheet(texture, this->width, this->depth + this->height);
    this->animation = new Animation(this->sprite_sheet, 0, 5, 1000);
    EventBus::subscribe(sf::Event::EventType::KeyPressed, this, &WaterTile::handle_key_pressed);
}

void WaterTile::draw(sf::RenderWindow *window, int elapsed_ms)
{
    this->animation->step(elapsed_ms);
    this->animation->draw(&this->sprite);
    window->draw(this->sprite);
}

void WaterTile::handle_key_pressed(sf::Event event)
{
    switch(event.key.code)
    {
        case sf::Keyboard::Key::Down :
        {
            this->animation->increase_duration(100);
            break;
        }
        case sf::Keyboard::Key::Up :
        {
            this->animation->decrease_duration(100);
            break;
        }
        default :
        {

        }
    }
}

WaterTile::~WaterTile()
{
    delete this->sprite_sheet;
    delete this->animation;
}

