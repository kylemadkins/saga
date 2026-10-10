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
  std::shared_ptr<sf::Texture> load_texture(const std::string &texture_path);
  void cleanup();

private:
  std::shared_ptr<sf::Texture> create_missing_texture();

  static std::unique_ptr<AssetManager> m_asset_manager;
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
  std::shared_ptr<sf::Texture> m_missing_texture;
};
} // namespace saga
