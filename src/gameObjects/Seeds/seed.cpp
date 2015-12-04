#include "seed.h"

Seed::Seed(ResourceManager &manager, std::string textureName):
PyoroSprite(manager, textureName)
{

}

/*
============================================================================================================================================================================
Seed::logic() does logic of seeds children
============================================================================================================================================================================
*/
void Seed::logic(float dt, float clockedTime, phase currPhase)
{
    centerOrigin();                                 //Centre the origin of the seed     ~ PyoroSprite::centerOrigin()
    mSprite.setOrigin(mSprite.getOrigin().x,
                      mSprite.getOrigin().y + 10);  //Offset the centred origin by 10

    if(!amActive)                                    //If the seed is not active
    {
        tryForSpawn();                               //Try for a spawn                  ~ Seed::tryForSpawn
    }
    else
    {
        animSeedFalling.animate(mSprite, clockedTime);  //If it is active, play the "falling animation"     ~ Animation::animate(sf::sprite, float)
        fallToGround(dt);                               //Fall to the ground                                ~ Seed::fallToGround(float)
        checkForGround();                               //Check for the ground                              ~ Seed::checkForGround()
    }
}

/*
============================================================================================================================================================================
Seed::checkForGround() checks for the "ground" aka the bottom of the screen
============================================================================================================================================================================
*/
void Seed::checkForGround()
{
    if(mSprite.getPosition().y > 575)   //If the y position of the seed is greater than 575 (bottom, y=0 is top of screen in SFML)...
    {
        destroySeed();                  //Destroy the seed ~ seed::destroy()
    }
}

/*
============================================================================================================================================================================
Seed::fallToGround() causes the seed to fall to ground
============================================================================================================================================================================
*/
void Seed::fallToGround(float dt)
{
    mSprite.move(0, mFallSpeed * dt);    //Move the sprite down
}

/*
============================================================================================================================================================================
Seed::tryForSpawn() randomly picks a number, if it is 10 then the seed will spawn
============================================================================================================================================================================
*/
void Seed::tryForSpawn()
{
    int spawn;                              //Number which will be our choose
    spawn = randRange(0, mSpawnChance);     //Pick a number between 0 and Seed::mSpawnChance ~ Random randRange(int, int)
    if(spawn == 10)                         //If the "spawn" integer is 10
    {
        spawnMe();                          //Spawn the seed ~ Seed::spawnMe()
    }
}

/*
============================================================================================================================================================================
Seed::spawnMe() spawns the seed
============================================================================================================================================================================
*/
void Seed::spawnMe()
{
    amActive = true;                    //Set active to true
    int xPos = randRange(5, 640 - 20);  //Pick a random xPosition ~ Random.h randRange(int, int)
    int yPos = -50;                     //Y axis of seeds starts off-screen

    mSprite.setPosition(xPos, yPos);    //Make seed go to said position
}

/*
============================================================================================================================================================================
Seed::collect() is called when the seed needs to be collected
============================================================================================================================================================================
*/
void Seed::collect(int &score)
{
    score += mCollectionScore;  //Change the players score by the score that this seed gives aka Seed::mCollectionScore
    destroySeed();              //Destroy the seed ~ Seed::destroySeed()
}

/*
============================================================================================================================================================================
Seed::destroySeed() destroys the seed
============================================================================================================================================================================
*/
void Seed::destroySeed()
{
    mSprite.setPosition(mSprite.getPosition().x, -500); //Set sprite position to off-screen
    amActive = false;                                   //Set active to false
}

/*
============================================================================================================================================================================
Seed::getPos() returns the position of the seed
============================================================================================================================================================================
*/
sf::Vector2f Seed::getPos()
{
    return mSprite.getPosition();
}

/*
============================================================================================================================================================================
Seed::getScore() returns the score of the seed
============================================================================================================================================================================
*/
int Seed::getScore()
{
    return mCollectionScore;
}


void Seed::uniqueLogic(){}












