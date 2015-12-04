#include "seed1.h"

/*
============================================================================================================================================================================
The constructor sets up the seed
============================================================================================================================================================================
*/
NormSeed::NormSeed(ResourceManager &manager, std::string textureName):
    Seed(manager, textureName)
{
    mSpawnChance        = 1000;                 //Set spawn chance (meaning it has a 1/ mSpawnChance chance of spawning)
    mCollectionScore    = 100;                  //Set the score increase of seed collection
    mFallSpeed          = 100;                  //Set the speed of what said seed falls at
    amActive            = false;                //Set its active to false
    mType               = norm;                 //Set type of seed to normal

    mSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));  //Set the frame at which the seed starts at

    mSprite.setPosition(0, -100);                       //Set the position of the seed to off-screen

    setUp(manager); //Set up animations and sounds (defined in PyoroSprite)
}

/*
============================================================================================================================================================================
The constructor sets up the seed
============================================================================================================================================================================
*/
void NormSeed::uniqueLogic()
{

}

void NormSeed::setUpAnimation()
{
    int spriteSize = 64;

    animSeedFalling.addFrame(sf::IntRect(0,                0, spriteSize, spriteSize), 0.3);
    animSeedFalling.addFrame(sf::IntRect(spriteSize,       0, spriteSize, spriteSize), 0.3);
    animSeedFalling.addFrame(sf::IntRect(spriteSize * 2,   0, spriteSize, spriteSize), 0.3);
    animSeedFalling.addFrame(sf::IntRect(spriteSize,       0, spriteSize, spriteSize), 0.3);
}


void NormSeed::uniqueSetUp(ResourceManager& resourceManager)
{

}
