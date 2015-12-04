#ifndef TONGUE_H
#define TONGUE_H

#include <SFML/Graphics.hpp>
#include <cmath> //sqrt(), pow()

class Tongue
{
    public:
        Tongue();
        void createTongue(int direction, sf::Vector2f pos);
        void logic(float dt);
        sf::RectangleShape getRect();
        sf::Vector2f getRectEndPos();
    private:
        void setSize();
        void setPos(sf::Vector2f pos);

    private:
        enum direction              //type for the direction
        {
            left,
            right
        } mDirection;               //Variable for the direction

        sf::Vector2f mStartPos;     //Vector for start position of the player
        sf::Vector2f mEndPos;       //Vector for end   position of the player

        sf::RectangleShape tongue;  //Rectangle for the tongue itself


};

#endif // TONGUE_H
