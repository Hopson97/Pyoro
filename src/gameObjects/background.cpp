#include "background.h"

Background::Background(ResourceManager &manager, std::string textureName):
    PyoroSprite(manager, textureName),
    test(mSprite)
{
    setUp(manager); //Set up animations and sounds (defined in PyoroSprite)
}

void Background::logic(float dt, float clockedTime, phase currPhase)
{

}

void Background::setUpAnimation()
{
    test.addFrame(sf::IntRect(0, 0,   640, 575), 0);
    test.addFrame(sf::IntRect(0, 575, 640, 575), 0);
}

bool Background::fade(sf::RenderWindow &window, phase phaseTransition)
{
    test.fade(window);
    return false;

    if(test.fadeFinished())
        return true;
}

void Background::uniqueSetUp(ResourceManager& resourceManager)
{

}
