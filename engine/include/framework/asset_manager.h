#pragma once

#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <unordered_map>

namespace saga {
class AssetManager {
protected:
  AssetManager();

public:
  static AssetManager &get();
  std::shared_ptr<sf::Texture> load_texture(const std::string &path);

private:
  static std::unique_ptr<AssetManager> m_asset_manager;
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
};
} // namespace saga
