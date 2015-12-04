#include "game.h"

/*
============================================================================
Game::Game()    sets some constants for the window height and width and then
                proceeds to create the window itself. It then finally sets
                the current game-state to the menu screen.
============================================================================
*/
Game::Game():
    WINDOW_WIDTH(640),  //Sets the screen width
    WINDOW_HEIGHT(575), //Sets the screen height
    lastTime(0)
{
    mWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pyoro"); //Create the window
    mWindow.setFramerateLimit(60);  //Set the frame rate limit of window to 60

    changeState(new MenuState(this)); //Change the game state to "menu"

    arial.loadFromFile("fonts/arial.ttf");
    framesPerSecond.setFont(arial);
}
/*

====================================================================================================
Game::runMainLoop() does exactly what you expect: Runs the main loop for the game :P
====================================================================================================
*/
void Game::runMainLoop()
{
    sf::Clock clockSinceStart;  //Clock to measure time since opened
    sf::Clock deltaClock;       //Clock to measure time since last frame

    while(mWindow.isOpen())     //While the window is opened...
    {
        float deltaTime = deltaClock.restart().asSeconds();  //Set delta time
        sf::Time timeSinceStart = clockSinceStart.getElapsedTime(); //Elapsed time

        windowEvents();             //Does the window events such as checking if window is closed

        auto stateGuard = mState;            //This stops the program from crashing
        mState->logic(deltaTime,
                      timeSinceStart.asSeconds()); //Make the game do stuff!


       // displayFPS(deltaTime);

        mWindow.display();                      //Display anything that had been drawn to the window
    }
}

/*
====================================================================================================
Game::changeState() changes the current state the game is in
====================================================================================================
*/
void Game::changeState(State* state)
{
    mState.reset(std::move(state)); //Reset the state to the state in the argument
}

/*
============================================================================
Game::getResourceManager returns the resources as a reference to save space
============================================================================
*/
ResourceManager& Game::getResourceManager()
{
    return mResources;
}
/*
============================================================================
Game::gameWindow()  is primarily for other classes for the sake of manipulating
                    the window
============================================================================
*/
sf::RenderWindow& Game::gameWindow()
{
    return mWindow;
}

/*
============================================================================
Game::gameWindowHeight() returns the height of the window
============================================================================
*/
const int Game::gameWindowHeight()
{
    return WINDOW_HEIGHT;
}

/*
============================================================================
Game::gameWindowWidth() returns the width of the window
============================================================================
*/
const int Game::gameWindowWidth()
{
    return WINDOW_WIDTH;
}

/*
============================================================================
Game::windowEvents() handles the events of the window such as closing
============================================================================
*/
void Game::windowEvents()
{
    mWindow.clear();
    sf::Event event;    //The object to handle events

    while(mWindow.pollEvent(event)) //While the window is looking for events
    {
        if(event.type == sf::Event::Closed) //If the event is of type "close"
        {
            mWindow.close();    //Close the window
            exit(0);             //Exit the program
        }
    }
}

void Game::displayFPS(float currentTime)
{
    float fps = 1.0f / (currentTime - lastTime);
    lastTime = currentTime;

    std::cout << fps << std::endl;

    std::ostringstream buff;
    buff << fps;

    framesPerSecond.setString(buff.str());


    mWindow.draw(framesPerSecond);

}


























