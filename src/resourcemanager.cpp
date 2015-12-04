#include "resourcemanager.h"

/*
============================================================================
ResourceManager::ResourceManager() loads up the fonts and textures
============================================================================
*/
ResourceManager::ResourceManager()
{
    loadFonts();
    loadTextures();
    loadSounds();
}

/*
============================================================================
ResourceManager::loadFonts() will load the fonts
============================================================================
*/
void ResourceManager::loadFonts()
{
    if(!arial.loadFromFile("fonts/arial.ttf")); //Load the Arial texture
    mFonts["arial"] = arial;                    //Add it to the "map"

    if(!instruction.loadFromFile("fonts/Instruction.ttf")); //Load the instruction font
    mFonts["instruction"] = instruction;                    //Add it to the "map"
}

/*
============================================================================
ResourceManager::loadTextures() will load the textures
============================================================================
*/
void ResourceManager::loadTextures()
{
    if(!background.loadFromFile("img/backdrop.png")); //Load the background texture
    mTextures["Background"] = background;             //Add it to the "map"

    if(!pyoro.loadFromFile("img/pyoro.png"));
    mTextures["Player"] = pyoro;

    if(!seed.loadFromFile("img/seed1.png"));
    mTextures["Seed1"] = seed;

    if(!tile.loadFromFile("img/tiles.png"));
    mTextures["Tile"] = tile;
}

/*
============================================================================
ResourceManager::loadAudio() will load the audio
============================================================================
*/
void ResourceManager::loadSounds()
{
    if(!playerWalk.loadFromFile("sfx/walking.ogg"));
    mSounds["Walking"] = playerWalk;

    if(!licking.loadFromFile("sfx/licking.ogg"));
    mSounds["Licking"] = licking;
}

/*
============================================================================
ResourceManager::getFont() returns a needed font as a reference
============================================================================
*/
sf::Font& ResourceManager::getFont(std::string fontName)
{
    return mFonts[fontName];
}

/*
============================================================================
ResourceManager::getTexture() returns a needed texture as a reference
============================================================================
*/
sf::Texture& ResourceManager::getTexture(std::string textureName)
{
    return mTextures[textureName];
}

/*
============================================================================
ResourceManager::getSound() returns a needed sound as a reference
============================================================================
*/
sf::SoundBuffer& ResourceManager::getSound(std::string soundName)
{
    return mSounds[soundName];
}


/*
============================================================================

============================================================================
*/
