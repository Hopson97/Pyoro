#ifndef SEED_H
#define SEED_H

#include "pyorosprite.h"
#include "Random.h"

enum Type
{
    norm,
    spec
};

class Seed : public PyoroSprite
{
    public:
        Seed(ResourceManager &manager, std::string textureName);
        void logic(float dt, float clockedTime, phase currPhase) override;

        void collect(int &score);
        void destroySeed();

        int getScore();

        sf::Vector2f getPos();

    protected:
        int mSpawnChance;           //The lower, the higher the chance of spawning is.
        int mFallSpeed;             //The speed at which the seed falls at.
        int mCollectionScore;       //Score received for collection of said seed.
        Type mType;          //Type of seed

        bool amActive;
        Animation animSeedFalling;

    private:
        void checkForGround();
        void tryForSpawn();
        void spawnMe();
        void fallToGround(float dt);
        virtual void uniqueLogic();
};

#endif // SEED_H
