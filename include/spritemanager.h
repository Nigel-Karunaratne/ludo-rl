#pragma once

#include <unordered_map>
#include <string>
#include "raylib-cpp.hpp"

namespace rl=raylib;

// Responsible for storing all loaded Texture2Ds. It is up to individual classes to keep references and draw when needed.
class SpriteManager
{
private:
    std::unordered_map<std::string, rl::Texture2D> textureTable;
    rl::Texture2D defaultTexture;
public:
    SpriteManager();
    ~SpriteManager();

    bool AddTexture(std::string name, std::string path);

    const rl::Texture2D& GetSprite(std::string name);
};
