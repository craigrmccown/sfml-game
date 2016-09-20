#include "../include/texture_manager.hpp"
#include <iostream>

void TextureManager::load_texture(std::string key, std::string path)
{
    this->textures[key].loadFromFile(path);
}

sf::Texture &TextureManager::get_texture(std::string key)
{
    return this->textures.at(key);
}
