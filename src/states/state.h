#ifndef STATE_H
#define STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class Game;
class State
{
    public:
        State();
        void logic(float dt, float clockedTime);
        virtual void input(float dt, float clockedTime);
        virtual void update(float dt, float clockedTime);
        virtual void draw();

    protected:
        Game* mGame;    //Pointer to the current game

};

#endif // STATE_H
