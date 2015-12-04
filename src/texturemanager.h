#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureManager
{
    public:
        TextureManager();
    private:
        void loadTextures();

    private:
        sf::Texture background;

        std::map<std::string, sf::Texture> mTextures;

};

#endif // TEXTUREMANAGER_H
