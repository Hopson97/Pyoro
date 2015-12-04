#include "pyorosprite.h"

PyoroSprite::PyoroSprite(ResourceManager &manager, std::string textureName):
    normToSephia(mSprite),
    SephiaToNight(mSprite)
{
    mSprite.setTexture(manager.getTexture(textureName));//Set the texture to something from the resource manager
}
/*
==============================================================================================
PyoroSprite::draw() draws the sprite
==============================================================================================
*/
void PyoroSprite::draw(sf::RenderWindow &window)
{
    window.draw(mSprite);
}

/*
==============================================================================================
PyoroSprite::centerOrigin() centres the origin of the sprite
==============================================================================================
*/
void PyoroSprite::centerOrigin()
{
    mSprite.setOrigin(mSprite.getLocalBounds().width / 2,
                      mSprite.getLocalBounds().height / 2);
}

/*
==============================================================================================
PyoroSprite::getSprite() returns the sprite from where called
==============================================================================================
*/
sf::Sprite PyoroSprite::getSprite()
{
    return mSprite;
}

bool PyoroSprite::fade(sf::RenderWindow &window, phase phaseTransition)
{
    switch(phaseTransition)
    {
    case toSephia:
        normToSephia.fade(window);
        break;
    case toNight:
        normToSephia.fade(window);
        break;
    default:
        break;
    }


    return false;
}

void PyoroSprite::setUp(ResourceManager &manager)
{
    uniqueSetUp(manager);
    setUpAnimation();
}

/*
==============================================================================================
THESE ARE FOR VTABLES/ virtual tables thing
==============================================================================================
*/
void PyoroSprite::setUpAnimation(){}
void PyoroSprite::logic         (float dt, float clockedTime, phase currPhase){}
void PyoroSprite::uniqueSetUp   (ResourceManager& resourceManager){}
