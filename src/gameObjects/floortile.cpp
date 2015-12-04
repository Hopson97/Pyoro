#include "floortile.h"

/*
==============================================================================================
The constructor sets the called position
==============================================================================================
*/
FloorTile::FloorTile(int xPos, int yPos, ResourceManager &manager, std::string textureName):
    PyoroSprite(manager, textureName),
    active(true)
{
    mSprite.setPosition(xPos, yPos);
    mSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    setUp(manager); //Set up animations and sounds (defined in PyoroSprite)
}

/*
==============================================================================================
Floortile::logic() sets the animation of the tile (for now)
==============================================================================================
*/
void FloorTile::logic(float dt, float clockedTime, phase currPhase)
{
    //anim.animate(mSprite, clockedTime); //Animate the sprite
}

/*
==============================================================================================
Floortile::setActive() sets whether the tile is active or not (true/ false respectively)
Floortile::isActive() returns the current state of the tile
==============================================================================================
*/
void FloorTile::setActive(bool active)
{
    this->active = active;
}

bool FloorTile::isActive()
{
    return active;
}

/*
==============================================================================================
Floortile::setUpAnimation sets the animations of tile. This is probably temporary
==============================================================================================
*/
void FloorTile::setUpAnimation()
{
    sf::IntRect f1(0, 0, 32, 32);
    sf::IntRect f2(32, 0, 32, 32);
    sf::IntRect f3(64, 0, 32, 32);
}

void FloorTile::uniqueSetUp(ResourceManager& resourceManager)
{

}
