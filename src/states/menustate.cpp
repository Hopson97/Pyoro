#include "menustate.h"
/*
============================================================================
This constructor points to the game class and then sets up some text to be
displayed
============================================================================
*/
MenuState::MenuState(Game* game)
{
    mGame = game;           //Point to the game, "&" is not needed as the argument is already a pointer

    playText.setFont(mGame->getResourceManager().getFont("arial")); //Set the font
    playText.setString("Press <spacebar> to play");                 //Set the text

    centerTextOrigin();                                             //Centre the origin of the text
}

/*
============================================================================
MenuState::input checks for input:
~Space-bar will call the next game state
============================================================================
*/
void MenuState::input(float dt, float clockedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //If space is pressed
    {
        mGame->changeState(new playState(mGame));       //Set the gameState to "play"
    }
}

/*
============================================================================
MenuState::update does nothing in this class, but is here for sake of errors("V table")
============================================================================
*/
void MenuState::update(float dt, float clockedTime)
{

}

/*
============================================================================
MenuState::draw() draws text to the screen
============================================================================
*/
void MenuState::draw()
{
    mGame->gameWindow().draw(playText);
}

void MenuState::centerTextOrigin()
{
    sf::FloatRect textRect = playText.getLocalBounds();

    playText.setOrigin  (textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    playText.setPosition(sf::Vector2f(mGame->gameWindowWidth()/2.0f,
                                       mGame->gameWindowHeight()/2.0f));
}


