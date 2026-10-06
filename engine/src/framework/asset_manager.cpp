#include "framework/asset_manager.h"
#include "framework/core.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace saga {
AssetManager::AssetManager() : m_textures{} {}

std::unique_ptr<AssetManager> AssetManager::m_asset_manager{nullptr};

AssetManager &AssetManager::get() {
  if (!m_asset_manager) {
    m_asset_manager = std::unique_ptr<AssetManager>{new AssetManager()};
  }
  return *m_asset_manager;
}

std::shared_ptr<sf::Texture>
AssetManager::load_texture(const std::string &path) {
  SAGA_LOG("asset manager :: loading texture from path %s\n", path.c_str());

  auto found = m_textures.find(path);
  if (found != m_textures.end())
    return found->second;

  std::shared_ptr<sf::Texture> new_texture = std::make_shared<sf::Texture>();
  if (new_texture->loadFromFile(path)) {
    m_textures.insert({path, new_texture});
    return new_texture;
  }

  return nullptr;
}
} // namespace saga
