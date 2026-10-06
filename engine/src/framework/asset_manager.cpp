#include "framework/asset_manager.h"
#include "framework/core.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace saga {
AssetManager::AssetManager()
    : m_textures{}, m_missing_texture{create_missing_texture()} {}

std::unique_ptr<AssetManager> AssetManager::m_asset_manager{nullptr};

AssetManager &AssetManager::get() {
  if (!m_asset_manager) {
    m_asset_manager = std::unique_ptr<AssetManager>{new AssetManager()};
  }
  return *m_asset_manager;
}

std::shared_ptr<sf::Texture>
AssetManager::load_texture(const std::string &path) {
  auto found = m_textures.find(path);
  if (found != m_textures.end())
    return found->second;

  SAGA_LOG("asset manager :: loading texture from path %s\n", path.c_str());
  std::shared_ptr<sf::Texture> new_texture = std::make_shared<sf::Texture>();
  if (new_texture->loadFromFile(path)) {
    m_textures.insert({path, new_texture});
    return new_texture;
  }

  SAGA_LOG("asset manager :: failed to load texture from path %s\n",
           path.c_str());
  m_textures.insert({path, m_missing_texture});
  return m_missing_texture;
}

void AssetManager::cleanup() {
  for (auto it = m_textures.begin(); it != m_textures.end();) {
    if (it->second.use_count() == 1) {
      SAGA_LOG("asset manager :: cleaning up texture with path %s\n",
               it->first.c_str());
      it = m_textures.erase(it);
    } else {
      ++it;
    }
  }
}

std::shared_ptr<sf::Texture> AssetManager::create_missing_texture() {
  constexpr unsigned size = 64;
  constexpr unsigned cell = 16;
  sf::Image image{{size, size}, sf::Color::Black};
  for (unsigned y = 0; y < size; ++y)
    for (unsigned x = 0; x < size; ++x)
      if ((x / cell + y / cell) % 2 == 0)
        image.setPixel({x, y}, sf::Color::Magenta);
  return std::make_shared<sf::Texture>(image);
}
} // namespace saga
