#include "../include/grass_tile.hpp"

GrassTile::GrassTile(TextureManager &texture_manager) : MapTile()
{
    this->sprite.setTexture(texture_manager.get_texture("grass_tile"));
}

void GrassTile::draw(sf::RenderWindow &window, int elapsed_ms)
{
    window.draw(this->sprite);
}
