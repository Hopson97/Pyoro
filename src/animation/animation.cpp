#include "animation.h"


/*
====================================================================================================
Animation constructor sets the frames and time etc to 0
====================================================================================================
*/
Animation::Animation():
    beenAnimated    (false)
{
    mCurrentFrame   = 0;
    mOldTime        = 0;

}
/*
====================================================================================================
Animation::animate() animates the sprites
====================================================================================================
*/
void Animation::animate(sf::Sprite &sprite, float currentTime)
{
    if(mFrames.size() < 1)
    {
        std::cerr << "Animation not set up!" << std::endl;
        return;
    }
    if(longestFrameGap() > (currentTime - mOldTime) + 0.5f )  //If last frame's time has been longer ago than
    {                               //the largest time gap between frames
        beenAnimated = false;       //Treat animation as not being animated
    }
    if(!beenAnimated)               //If not been animated
    {
        mOldTime = currentTime;     //Set the "old time" to the "current time"
        beenAnimated = true;        //Treat animation as animated
    }

    checkForAnimationBounds(currentTime);                   //Check for if the animation is in its final state
    sprite.setTextureRect(mFrames[mCurrentFrame].mFrame);   //Set the sprite frame of the player to current frame

}

/*
====================================================================================================
Animation::calculateLongestFrameGap() checks the longest time between frames
====================================================================================================
*/
float Animation::longestFrameGap()
{
    float longestFrameGap = 0;                              //float for the gap
    for(auto frames: mFrames)                               //Iterate through the frames
    {
        if(frames.mTimeToNextFrame > longestFrameGap + 0.1)  //Check if current frame is longest gap so far
        {
            longestFrameGap = frames.mTimeToNextFrame;       //Set the longest gap time to that frames time gap
        }
    }
    return longestFrameGap;                                  //Return the gap itself
}
