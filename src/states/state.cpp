#include "state.h"

State::State()
{
}

/*
============================================================================
State::logic() does everything that needs doing
============================================================================
*/
void State::logic(float dt, float clockedTime)
{
    input(dt, clockedTime);
    update(dt, clockedTime);
    draw();
}

/*
============================================================================
These are here for v-lookup tables
============================================================================
*/
void State::input(float dt, float clockedTime){}
void State::update(float dt, float clockedTime){}
void State::draw(){}

