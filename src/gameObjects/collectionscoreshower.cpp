#include "collectionscoreshower.h"

/*
============================================================================================================================================================================
The constructor sets the font and stuff
============================================================================================================================================================================
*/
collectionScoreShower::collectionScoreShower(ResourceManager &manager, float currTime, int score, sf::Vector2f pos):
    active(true),           //The score shower is active
    mLifeTime(1),           //Set the life time of the score shower to (x) seconds
    mStartTime(currTime)    //Set the start time aka time since start of game
{
    mText.setFont(manager.getFont("instruction"));  //Set font
    mText.setPosition(pos);                         //Set position

    std::ostringstream buff;                        //Set the
    buff << score;                                  //string of the sf::Text
    mText.setString(buff.str());                    //to the score of seed collected
}

/*
============================================================================================================================================================================
collectionScoreShower::isActive() checks if the text should be active
============================================================================================================================================================================
*/
bool collectionScoreShower::isActive(float currTime)
{
    if (mStartTime + mLifeTime < currTime)  //If the lifetime of teh seed has been longer than its lifetime
    {
        active = false;                     //Tell game it should not be alive
    }
    return active;              //Return the state of active
}


/*
============================================================================================================================================================================
collectionScoreShower::draw() draws the text
============================================================================================================================================================================
*/
void collectionScoreShower::draw(sf::RenderWindow& window)
{
    mText.setColor(randColour());   //Set to random colour (aka flash the text)
    window.draw(mText);             //Draw text to window

}












