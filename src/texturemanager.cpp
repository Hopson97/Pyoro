#include "texturemanager.h"

TextureManager::TextureManager()
{

}

void TextureManager::loadTextures()
{
    if(!background.loadFromFile("img/backdrop.png"));
    mTextures["Background"] = background;
}
