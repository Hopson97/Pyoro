#include "Random.h"

/*
====================================================================================================
randRange() returns to the caller a random number between "low and high"
====================================================================================================
*/
int randRange(int low, int high)
{
	return rand() % (high - low + 1) + low;
}

sf::Color randColour()
{
    sf::Color c;
    c.r = randRange(0, 255);
    c.g = randRange(0, 255);
    c.b = randRange(0, 255);

    return c;
}
