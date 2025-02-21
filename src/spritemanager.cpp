#include "spritemanager.h"

SpriteManager::SpriteManager()
{
    rl::Image pattern = ::GenImageChecked(32,32,4,4,rl::Color::RayWhite(),rl::Color::DarkPurple());
    defaultTexture.Load(pattern);
}

SpriteManager::~SpriteManager()
{
}

bool SpriteManager::AddTexture(std::string name, std::string path)
{
    std::string newname = path.substr(0,path.find('.'));
    Texture2D texture = ::LoadTexture(path.c_str());
    textureTable.insert({name,texture});
}

const rl::Texture2D &SpriteManager::GetSprite(std::string name)
{
    if(textureTable.find(name) == textureTable.end())
    {
        ::TraceLog(TraceLogLevel::LOG_ERROR, std::string("Invalid name requested from SpriteManager \"" + name + "\"").c_str());
        return defaultTexture;
    }
    return textureTable[name];
}
