#ifndef ANIMATIONEFFECT_H
#define ANIMATIONEFFECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class AnimationEffect
{
    public:
        void addFrame(sf::IntRect frame, float timeToNextFrame);
        void checkForAnimationBounds(float currentTime);
        int getCurrentFrame();

    protected:
        /*
        ==================================================================================================
        A structure for the animation frames; it contains: the section of the sprite sheet of that frame,
                                                and the time gap for the next frame to come.
        ==================================================================================================
        */
        struct Frame
        {
            sf::IntRect mFrame;     //section
            float mTimeToNextFrame; //time gap
        };

        std::vector<Frame> mFrames;     //"list" of animation frames
        unsigned int mCurrentFrame;      //The current frame the animation is on
        float mOldTime;                 //The "time" the previous frame had played

};

#endif // ANIMATIONEFFECT_H
