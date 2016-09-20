#include "../include/texture_manager.hpp"

void TextureManager::load_texture(const std::string& key, const std::string& path)
{
    sf::Texture texture;
    texture.loadFromFile(path);
    this->textures[key] = texture;
}

const sf::Texture& TextureManager::get_texture(const std::string& key) const
{
    return this->textures.at(key);
}
