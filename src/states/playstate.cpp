#include "playstate.h"

/*
============================================================================================================================================================================
The constructor sets up the sprites
============================================================================================================================================================================
*/
playState::playState(Game* game):
    mPlayer     (game->getResourceManager(), "Player"),
    mBackground (game->getResourceManager(), "Background")
{
    mScoreText.setFont(game->getResourceManager().getFont("arial"));

    mGame = game;                   //Assign a pointer the current game ~this
    addFloorTiles(20);              //Add the 20 floor tiles            ~this
    addNormSeeds(10);               //Add normal seeds                  ~this

    mTongue = &mPlayer.getTongue(); //Set up a pointer to the players tongue ~Player::getTongue

    mPhase = norm1;
    mDrawMode = normalDraw;
}
/*

============================================================================================================================================================================
playState::input() is unused (for now?)
============================================================================================================================================================================
*/
void playState::input  (float dt, float clockedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        mDrawMode = fadeDraw;
    }
}

/*
============================================================================================================================================================================
playState::update() updates whatnot to do with sprites
============================================================================================================================================================================
*/
void playState::update (float dt, float clockedTime)
{
    for(auto& tile: mFloorTiles)    tile->logic(dt, clockedTime, mPhase);       //Do logic for the tiles                            ~FloorTile::logic(float, float)
    for(auto& seed: mSeeds)         checkSeed(seed, dt, clockedTime);   //Iterate through seeds and check for interactions  ~this

    checkCollText(clockedTime);
    mPlayer.logic(dt, clockedTime, mPhase);         //Do logic for the player       ~Player::logic(float, float)
    mBackground.logic(dt, clockedTime, mPhase);

    if(mPlayer.isLicking())                 //If the player is licking
        checkTongue(clockedTime);           //check the tongue for events   ~this

    nextPhase();
}

/*
============================================================================================================================================================================
playState::draw()   draws the sprite, taking advantage of the pointer to the game so that it can use it's window
============================================================================================================================================================================
*/
void playState::draw()
{
    if(mDrawMode == normalDraw)
    {
        mBackground.draw(mGame->gameWindow());  //Draw the background
        mPlayer.    draw(mGame->gameWindow());  //Draw the player
    }
    else
    {
        bool transitionComplete = false;
        transitionComplete = mBackground.fade(mGame->gameWindow(), mPhase);
        if(transitionComplete)
            mDrawMode = normalDraw;
    }

    drawFloorTiles();                       //Draw the tiles        ~this
    drawSeeds();                            //Draw the seeds        ~this
    drawTongue();                           //Draw the tongue       ~this
    drawScoreTexts();                       //Draw the score texts  ~this
}

/*
============================================================================================================================================================================
playState::checkSeed() and seedsVsX() is a collection of methods, testing for interactions and interceptions between the seeds in the mSeed vector,
                                        against whatever "X" is.
============================================================================================================================================================================
*/
void playState::checkSeed(seedptr seed, float dt, float currTime)
{
    seed->logic         (dt, currTime, mPhase);         //Do the logic of the seeds
    seedsVsTongue       (seed, currTime);       //Check for interactions between seed and tongue
    seedsVsFloorTiles   (seed, dt, currTime);   //Check for interactions between seed and floor tiles
    seedsVsPlayer       (seed);                 //Check for interactions between seed and the player
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void playState::seedsVsTongue(seedptr seed, float currTime) //seedptr is a "typedef" for "std::shared_ptr<Seed>"
{
    int dx = mTongue->getRectEndPos().x - seed->getPos().x; //Distance between seed and tongue (x axis)
    int dy = mTongue->getRectEndPos().y - seed->getPos().y; //Distance between seed and tongue (y axis)
    int distance = sqrt(pow(dx, 2) + pow(dy, 2));           //Distance between seed and tongue (overall)
    if(distance < 25)                                       //If the distance is less than 25 pixels
    {
        mColScoreTexts.emplace_back(new collectionScoreShower(mGame->getResourceManager(),  //Add a new collection text to the vector, along with the resource manager
                                                           currTime,                            //The current time
                                                           seed->getScore(),                    //The current score
                                                           seed->getSprite().getPosition()));   //The position of the seed
        seed->collect(mScore);
        endLick();
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void playState::seedsVsFloorTiles(seedptr seed, float dt, float currTime)
{
    for(auto& tile: mFloorTiles)                                 //For all the floor tiles...
    {
        sf::Vector2f tilePos = tile->getSprite().getPosition();  //"Tile sprite position" short hand
        sf::Vector2f seedPos = seed->getSprite().getPosition();  //"Seed sprite position" short hand

        if((seedPos.y + 20) > (tilePos.y))                   //If seed is below "y" coordinate
        {
            if((seedPos.x + 12) > (tilePos.x)             //and seed is to the right of the tile
                &&
                (seedPos.x - 12) < (tilePos.x + 32))    //... and to the left of the tile
            {
                tile->setActive(false);               //"Destroy" the tile
                seed->destroySeed();              //Destroy the seed
            }
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void playState::seedsVsPlayer(seedptr seed)
{
    sf::Vector2f playerPos = mPlayer.getSprite().getPosition();  //"Tile sprite position" short hand
    sf::Vector2f seedPos = seed->getSprite().getPosition();     //"Seed sprite position" short hand

    if((seedPos.y + 20) > (playerPos.y)                      //If seed is below "y" coordinate of player
        &&
        (seedPos.y - 12) < (playerPos.y + 50))           //and above bottom of player
    {
        if((seedPos.x + 12) > (playerPos.x)         //and seed is to the right of the player
            &&
            (seedPos.x - 0) < (playerPos.x + 50))   //... and to the left of the player
        {
            std::cout << "rip player 2015-2015 :(((" << std::endl;
        }
    }
}

/*
===========================================================================================================================================================================
playState::checkColScoreTextVector()    is a bad name for a method that checks if a text in the "collection text" vector list is "dead"...
                                        If it is, it erases that element;
============================================================================================================================================================================
*/
void playState::checkCollText(float clockedTime)
{
    for(unsigned int i = 0; i < mColScoreTexts.size(); i++)     //Loop cycling through the collection text
    {
        if(!mColScoreTexts[i]->isActive(clockedTime))           //If the text is "dead"
        {
            mColScoreTexts.erase(mColScoreTexts.begin() + i);   //Remove them from the list
        }
    }
}


/*
============================================================================================================================================================================
playState::drawX() is a collection of methods that draw stuff that would originally looked horrible clustered together in one method.
============================================================================================================================================================================
*/
void  playState::drawFloorTiles()
{
    for(auto& tile : mFloorTiles)   //If the tile is active
    {
        if(tile->isActive())
            tile->draw(mGame->gameWindow());   //Draw the tiles
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  playState::drawSeeds()
{
     for(auto& seed : mSeeds )   seed->draw(mGame->gameWindow());   //Draw the seeds
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  playState::drawTongue()
{
    if(mPlayer.isLicking())                                 //If the player is licking
    {
        mGame->gameWindow().draw(mTongue->getRect());       //Draw the tongue
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  playState::drawScoreTexts()
{
    for(auto& collectionText: mColScoreTexts)
    {
        collectionText->draw(mGame->gameWindow());
    }
}

/*
============================================================================================================================================================================
playState::nextPhase() changes the "phase"
============================================================================================================================================================================
*/
void playState::nextPhase()
{

}

/*
============================================================================================================================================================================
playState::checkTongue...() is a collection of methods for checking if the tongue is
                            touching anything, eg a seed or screen edge.
============================================================================================================================================================================
*/
void playState::checkTongue(float currTime)
{
    if(mTongue->getRectEndPos().x > 640  || //if the tongue is out to the right of the window
       mTongue->getRectEndPos().x < 0    || //or the tongue is out to the left  of the window
       mTongue->getRectEndPos().y < 0      )//or the tongue is out to the top   of the window
    {
         endLick();                         //Stop the licking of the player
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void playState::endLick()
{
    mPlayer.setLicking(false);
}

/*
============================================================================================================================================================================
playState::addFloorTiles() adds the floor tiles in correct position
============================================================================================================================================================================
*/
void playState::addFloorTiles(int amount)
{
    for(int i = 0; i < amount; i++) //Add floor tiles into the "list"
    {
        mFloorTiles.emplace_back(new FloorTile(i*32, mGame->gameWindowHeight() - 32, mGame->getResourceManager(), "Tile" ));
    }
}

/*
============================================================================================================================================================================
playState::addNormSeeds() adds the seeds into the "list" of seeds
============================================================================================================================================================================
*/
void playState::addNormSeeds(int amount)
{
    for(int i = 0; i < amount; i++)
    {
        mSeeds.emplace_back(new NormSeed(mGame->getResourceManager(), "Seed1"));
    }
}
