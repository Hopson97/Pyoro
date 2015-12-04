#ifndef COLLECTIONSCORESHOWER_H
#define COLLECTIONSCORESHOWER_H

#include "resourcemanager.h"
#include "Random.h"


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

class collectionScoreShower
{
    public:
        collectionScoreShower(ResourceManager &manager, float currTime, int score, sf::Vector2f pos);
        bool isActive(float currTime) ;
        void draw(sf::RenderWindow&);
    protected:
    private:
        bool active;
        float mLifeTime;
        float mStartTime;
        sf::Text mText;


};

#endif // COLLECTIONSCORESHOWER_H
