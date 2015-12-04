#ifndef ANIMATION_H
#define ANIMATION_H

#include "animationeffect.h"


class Animation : public AnimationEffect
{
    public:
        Animation();
        void animate(sf::Sprite &sprite, float currentTime);

    private:
        float longestFrameGap();

    private:
        bool beenAnimated;
};

#endif // ANIMATION_H
