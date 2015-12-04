#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
    public:
        ResourceManager();

        sf::Font&           getFont(std::string fontName);
        sf::Texture&        getTexture(std::string textureName);
        sf::SoundBuffer&    getSound(std::string soundName);

    private: //METHODS
        void loadTextures();
        void loadFonts();
        void loadSounds();

    private: //TEXTURES
        std::map<std::string, sf::Texture> mTextures;   //A dictionary as it were to store textures

        sf::Texture background;     //Background texture
        sf::Texture pyoro;          //Player/ Pyoro texture
        sf::Texture seed;           //Seeds/ "bomb" texture
        sf::Texture tile;           //Floor tile textures

    private: //FONTS
        std::map<std::string, sf::Font> mFonts;         //A dictionary as it were to store fonts

        sf::Font arial;             //Arial font
        sf::Font instruction;       //Instruction font (from 1001freefonts.com)

    private: //Sounds
        std::map<std::string, sf::SoundBuffer> mSounds;

        sf::SoundBuffer playerWalk;
        sf::SoundBuffer licking;

};

#endif // RESOURCEMANAGER_H
