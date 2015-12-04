#ifndef PLAYER_H
#define PLAYER_H

#include "pyorosprite.h"
#include "tongue.h"


class Player : public PyoroSprite
{
    public:
        Player(ResourceManager &manager, std::string textureName);
        void logic(float dt, float clockedTime, phase currPhase) override;

        void setLicking(bool _licking);
        bool isLicking();
        Tongue& getTongue();

    private:
        void input(float dt, float clockedTime, phase currPhase);
        void tongueLogic(float dt, float clockedTime);
        void setUpAnimation() override;
        void uniqueSetUp(ResourceManager& resourceManager) override;
    private:
        enum direction          //Type for checking the direction of which player is facing
        {
            left,
            right
        } mDirection;           //Variable for the direction


        bool licking;           //True if player is licking, false otherwise
        Tongue mTongue;         //The tongue of the player

        Animation animWalkLeft; //Animation for walking left
        Animation animWalkRight;//Animation for walking right

        sf::Sound mWalkSound;
        sf::Sound mLickSound;

        float mSpeed;
};

#endif // PLAYER_H
