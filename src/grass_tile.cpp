#include <SFML/Graphics.hpp>

GrassTile::GrassTile(sf::Texture *texture)
{
    this->sprite.setTexture(*texture);
}

void GrassTile::draw(sf::RenderWindow *window, int elapsed_ms)
{
    window->draw(this->sprite);
}
