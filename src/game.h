#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <resourcemanager.h>
#include "menustate.h"


class State;
class Game
{
    public:
        Game();
        void runMainLoop();
        void changeState(State* state);
        ResourceManager& getResourceManager();
        sf::RenderWindow& gameWindow();

        const int gameWindowHeight();
        const int gameWindowWidth();

    private:
        void windowEvents();

    private:
        sf::RenderWindow mWindow;       //The window where everything is drawn
        ResourceManager mResources;     //The object that stores textures, fonts, sounds ...

        std::shared_ptr<State> mState;  //Pointer to the current game state

        const int WINDOW_WIDTH;         //Window width
        const int WINDOW_HEIGHT;        //Window height

        sf::Text framesPerSecond;
        sf::Font arial;

        void displayFPS(float currentTime);
        float lastTime;





};

#endif // GAME_H
