#ifndef FADEEFFECT_H
#define FADEEFFECT_H

#include "animationeffect.h"

class FadeEffect : public AnimationEffect
{
    public:
        FadeEffect(sf::Sprite sprite);
        void fade(sf::RenderWindow& window);
        bool fadeFinished();
    private:
    private:
        sf::Sprite firstFrame;
        sf::Sprite nextFrame;

        int opacityMain;
        int opacityNext;
};

#endif // FADEEFFECT_H
