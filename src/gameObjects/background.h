#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "pyorosprite.h"
#include "animation/fadeeffect.h"

class Background : public PyoroSprite
{
    public:
        Background(ResourceManager &manager, std::string textureName);
        void logic(float dt, float clockedTime, phase currPhase) override;
        bool fade (sf::RenderWindow &window, phase phaseTransition)    override;
    private:
        void setUpAnimation () override;
        void uniqueSetUp    (ResourceManager& resourceManager) override;

        FadeEffect test;


};

#endif // BACKGROUND_H
