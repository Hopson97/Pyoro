#include "animationeffect.h"

/*
====================================================================================================
AnimationEffect::getCurrentFrame() returns the current frame of which the animation is on
====================================================================================================
*/
int AnimationEffect::getCurrentFrame()
{
    return mCurrentFrame;
}

/*
====================================================================================================
AnimationEffect::addFrame() is the method used to add a frame to the animation
====================================================================================================
*/
void AnimationEffect::addFrame(sf::IntRect frame, float timeToNextFrame)
{
    Frame aFrame;                               //A frame is made

    aFrame.mFrame = frame;                      //A "sf::Intrect" is added to the frame
    aFrame.mTimeToNextFrame = timeToNextFrame;  //The time gap between this frame
                                                // and the next frame is added to the frame
    mFrames.push_back(aFrame);                  //Add the frame to the animation
}

/*
====================================================================================================
AnimationEffect::checkAnimationBounds() checks whether the animation is in its final frame,
                                    and goes to next frame if not and if the time is right
====================================================================================================
*/
void AnimationEffect::checkForAnimationBounds(float currentTime)
{
    if(currentTime >=mFrames[mCurrentFrame].mTimeToNextFrame + mOldTime)    //If it is time
    {
        if(mCurrentFrame == mFrames.size() - 1)         //If the animation is out of bounds
        {
            mCurrentFrame = 0;                          //Set its current frame to "0"
        }
        else                                            //But if it's not
        {
            mCurrentFrame++;                            //Go to the next frame
        }
        mOldTime = currentTime;                         //Set the "old time" to the current time
    }
}
