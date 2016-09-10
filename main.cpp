#include <SFML/Graphics.hpp>

class SpriteSheet
{
    sf::Texture *texture;
    int sprite_width;
    int sprite_height;

    public:

    SpriteSheet(sf::Texture *texture, int sprite_width, int sprite_height)
    {
        this->texture = texture;
        this->sprite_width = sprite_width;
        this->sprite_height = sprite_height;
    }

    int set_texture(sf::Sprite *sprite, int x, int y)
    {
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(x * this->sprite_width, y * this->sprite_height, sprite_width, sprite_height));
    }
};


class MapTile : public GameObject
{
    public:

    static const int width = 100;
    static const int height = 50;
};

class WaterTile : public MapTile
{
    SpriteSheet *sprite_sheet;
    Animation *animation;

    public:

    WaterTile(sf::Texture *texture)
    {
        this->sprite_sheet = new SpriteSheet(texture, 100, 50);
        this->animation = new Animation(this->sprite_sheet, 0, 5, 1000);
    }

    void draw(sf::RenderWindow *window, int elapsed_ms)
    {
        this->animation->step(elapsed_ms);
        this->animation->draw(&this->sprite);
        window->draw(this->sprite);
    }

    ~WaterTile()
    {
        delete this->sprite_sheet;
        delete this->animation;
    }
};

int main()
{
    const int window_width = 1500;
    const int window_height = window_width / 2;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My Window");
    Map map = Map(window_width, 15, 15);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        map.draw(&window, elapsed.asMilliseconds());
        window.display();
    }

    return 0;
}
