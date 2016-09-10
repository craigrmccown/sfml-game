#include <SFML/Graphics.hpp>

class GrassTile : public MapTile
{
public:

    GrassTile(sf::Texture *texture)
    {
        this->sprite.setTexture(*texture);
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        window->draw(this->sprite);
    }
};
