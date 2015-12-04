#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

int randRange(int low, int high);   //Generate a random number between low and high
sf::Color randColour();

#endif // RANDOM_H_INCLUDED
