#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include "playstate.h"
#include "game.h"

class MenuState : public State
{
    public:
        MenuState(Game* game);
        void input  (float dt, float clockedTime)   override;
        void update (float dt, float clockedTime)   override;
        void draw()                                 override;

    private: //Methods
        void centerTextOrigin();

    private: //Properties
        sf::Text playText;      //The text that will display instructions on starting
};

#endif // MENUSTATE_H
