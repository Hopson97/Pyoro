#ifndef FLOORTILE_H
#define FLOORTILE_H

#include <SFML/Graphics.hpp>
#include "pyorosprite.h"

class FloorTile : public PyoroSprite
{
    public:
        FloorTile(int xPos, int yPos, ResourceManager &manager, std::string textureName);
        void logic(float dt, float clockedTime, phase currPhase) override;
        void setActive(bool active);
        bool isActive();


    private:
        void setUpAnimation () override;
        void uniqueSetUp    (ResourceManager& resourceManager) override;

    private:
        bool active;    //For checking if the tile is active
        Animation anim; //The animation of the tile
};

#endif // FLOORTILE_H
