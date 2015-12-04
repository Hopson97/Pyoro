#ifndef PYOROSPRITE_H
#define PYOROSPRITE_H

#include <iostream>

#include "resourcemanager.h"
#include "animation/animation.h"
#include "animation/fadeeffect.h"
#include "phaseenums.h"

/**
        When inheriting from this class, you must implement the following methods:
        public:
            void logic(float dt, float clockedTime) override;
        private:
            void setUpAnimation() override;
*/

class PyoroSprite
{
    public:
        PyoroSprite(ResourceManager &manager, std::string textureName);
        virtual void logic(float dt, float clockedTime, phase currPhase) = 0;
        virtual bool fade (sf::RenderWindow &window, phase phaseTransition);

        void         draw(sf::RenderWindow &window);
        void         centerOrigin();
        sf::Sprite   getSprite();
    protected:
        virtual void setUpAnimation() = 0;
        virtual void uniqueSetUp(ResourceManager& resourceManager) = 0;
        void setUp(ResourceManager &manager);

    protected:
        sf::Sprite mSprite;     //The sprite itself

        FadeEffect normToSephia;
        FadeEffect SephiaToNight;

};

#endif // PYOROSPRITE_H
