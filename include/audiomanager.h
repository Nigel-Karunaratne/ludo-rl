#pragma once

#include <unordered_map>
#include <string>
#include "raylib-cpp.hpp"

namespace rl=raylib;

// Responsible for storing all loaded Sounds. It is up to individual classes to keep references and play when needed?
class AudioManager
{
private:
    rl::AudioDevice audioDevice;
    std::unordered_map<std::string, rl::Sound> soundTable;
public:
    AudioManager();
    ~AudioManager();
};
