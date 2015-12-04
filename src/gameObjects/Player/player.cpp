#include "player.h"

/*
=============================================================================================
Player::Player() sets the direction and position
=============================================================================================
*/
Player::Player(ResourceManager &manager, std::string textureName):
    PyoroSprite(manager, textureName),
    mDirection(right),                  //Set direction to face face
    licking(false),                     //Set the lick state of player to false
    mSpeed(200)
{

    mSprite.setTextureRect(sf::IntRect(0,66,60,66));   //Set the sprite's start frame
    mSprite.setPosition(300,575-64);    //Set the sprites position


    setUp(manager); //Set up animations and sounds (defined in PyoroSprite)

}


/*
=============================================================================================
Player::logic() checks for screen bounds, input, and does "lick logic" if the player is
                licking
=============================================================================================
*/
void Player::logic(float dt, float clockedTime, phase currPhase)
{
    centerOrigin();     //Centre the players origin
    if(mSprite.getPosition().x <= 0)   mSprite.move(640 * dt,0);      //Check for left  screen bound
    if(mSprite.getPosition().x >= 700) mSprite.move(-640 * dt,0);   //Check for right screen bound
    input(dt, clockedTime, currPhase);                                         //Check for input

    if(licking)                                          //If the player is "licking"
    {
        tongueLogic(dt, clockedTime);                        //Do licking stuff :^)
    }
}

/*
=============================================================================================
Player::tongueLogic() does stuff the is required to happen if the player is licking, for
                        example:
                        - it displays the sprite frame
                        - calls the logic of the tongue itself
=============================================================================================
*/
void Player::tongueLogic(float dt, float clockedTime)
{
    if(mDirection == left)                          //If facing left
    {
        sf::IntRect tongueRect(64 * 3, 0, 64, 64);  //Set sprite frame
        mSprite.setTextureRect(tongueRect);         // to "licking left"
    }
    if(mDirection == right)                         //If facing right
    {
        sf::IntRect tongueRect(64 * 3, 64, 64, 64); //Set sprite frame
        mSprite.setTextureRect(tongueRect);         // to "licking right"
    }
    mTongue.logic(dt);
}

/*
=============================================================================================
Player::input() checks for input obviously
=============================================================================================
*/
void Player::input(float dt, float clockedTime, phase currPhase)
{
    if(!licking)    //Seeing as input can only happen if the player is not actually licking,
    {               //it checks to see if the player is licking before allowing input
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {                                                   //If the left key is pressed
            mSprite.move(-mSpeed * dt, 0);                     //Move the player left
            animWalkLeft.animate(mSprite, clockedTime);     //Do the facing left animation
            mDirection = left;                              //Set direction to left
            mWalkSound.play();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //If the right key is pressed
        {
            mSprite.move(mSpeed * dt, 0);                      //Move the player right
            animWalkRight.animate(mSprite, clockedTime);    //Do the facing right animation
            mDirection = right;                             //Set direction to right
            mWalkSound.play();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))     //If the "Z key" is pressed
        {
            setLicking(true);                                //Set licking to true
            if(mDirection == left)                          //If direction is left
                mTongue.createTongue(0, mSprite.getPosition()); //Create a tongue going left
            else if(mDirection == right)                        //If direction is right
                mTongue.createTongue(1, mSprite.getPosition()); //Create a tongue going right
        }
    }
}
/*
=============================================================================================
Player::getTongue() returns the tongue itself as a pointer/ reference from where it was called
==============================================================================================
*/
Tongue& Player::getTongue()
{
    return mTongue;
}

/*
==============================================================================================
Player::isLicking() returns to the caller whether the player is licking or not
==============================================================================================
*/
bool Player::isLicking()
{
    return licking;
}

/*
==============================================================================================
Player::setLicking() sets whether the player is licking or not
==============================================================================================
*/
void Player::setLicking(bool _licking)
{
    licking = _licking;
    if(!licking)
    {
        sf::IntRect standingRect;       //Set texture/ sprite frame to be of the players
        if(mDirection == left) standingRect = sf::IntRect(0, 0, 64, 64);    //current
        if(mDirection == right) standingRect = sf::IntRect(0, 64, 64, 64);  //direction
        mSprite.setTextureRect(standingRect);
        mLickSound.stop();
    }
    else
    {
        mLickSound.play();
    }


}

/*
==============================================================================================
Player::setUpAnimation() sets up the animations for the player
==============================================================================================
*/
void Player::setUpAnimation()
{
    int spriteSize = 64;

    //Walking left animation
    animWalkLeft.addFrame(sf::IntRect(0,          0, spriteSize, spriteSize), 0.1);
    animWalkLeft.addFrame(sf::IntRect(spriteSize, 0, spriteSize, spriteSize), 0.1);

    //Walking right animation
    animWalkRight.addFrame(sf::IntRect(0,           spriteSize, spriteSize, spriteSize), 0.1);
    animWalkRight.addFrame(sf::IntRect(spriteSize,  spriteSize, spriteSize, spriteSize), 0.1);
}

/*
==============================================================================================
Player::uniqueSetUp() is for loading stuff unique to the player, such as the walking sounds.
==============================================================================================
*/
void Player::uniqueSetUp(ResourceManager& resourceManager)
{
    mWalkSound.setBuffer(resourceManager.getSound("Walking"));
    mLickSound.setBuffer(resourceManager.getSound("Licking"));
}
