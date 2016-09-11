#include "../include/water_tile.hpp"

WaterTile::WaterTile(sf::Texture *texture)
{
    this->sprite_sheet = new SpriteSheet(texture, 100, 50);
    this->animation = new Animation(this->sprite_sheet, 0, 5, 1000);
    EventBus::subscribe(sf::Event::EventType::KeyPressed, this, &WaterTile::handle_event);
}

void WaterTile::draw(sf::RenderWindow *window, int elapsed_ms)
{
    this->animation->step(elapsed_ms);
    this->animation->draw(&this->sprite);
    window->draw(this->sprite);
}

void WaterTile::handle_event(sf::Event event)
{
    this->animation->change_duration(3000);
}

WaterTile::~WaterTile()
{
    delete this->sprite_sheet;
    delete this->animation;
}

