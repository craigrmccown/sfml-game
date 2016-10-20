#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/texture_manager.hpp"
#include "../include/game_state.hpp"
#include "../include/map_game_state.hpp"
#include "../include/event_bus.hpp"

void load_textures(TextureManager& texture_manager)
{
    texture_manager.load_texture("grass_tile", "assets/tile_grass.png");
    texture_manager.load_texture("player", "assets/player.png");
}

int main()
{
    const int window_width = 1500;
    const int window_height = window_width / 2;

    TextureManager texture_manager;
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My Window");
    sf::View view(sf::Vector2f(0, (float)((window_height / 2) - (GameObject::base_depth / 2.0))), sf::Vector2f((float)window_width, (float)window_height));
    std::stack<std::unique_ptr<GameState>> states;

    load_textures(texture_manager);
    window.setView(view);
    states.push(std::unique_ptr<GameState>(new MapGameState(texture_manager)));

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
            else
            {
                states.top()->event_bus.publish(event);
            }
        }

        window.clear(sf::Color::Black);
		states.top()->draw(window, elapsed.asMicroseconds() / 1000.0);
        window.display();
    }

    return 0;
}
