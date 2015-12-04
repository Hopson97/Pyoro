#include "tongue.h"

/*
==============================================================================================
Tongue constructor sets the colour of the tongue to pink
==============================================================================================
*/
Tongue::Tongue()
{
    tongue.setFillColor(sf::Color(255, 192, 203));      //Set the tongue to be pink
}

/*
==============================================================================================
Tongue::createTongue() sets up the tongue
==============================================================================================
*/
void Tongue::createTongue(int dir, sf::Vector2f pos)
{

    mStartPos = pos;                //Set the "starting position" of the tongue to be where player is (pos)
    mEndPos = pos;                  //Do the same for the "end position", which is what will extend the tongue

    if(dir == 0) mDirection = left;     //Set the direction
    if(dir == 1) mDirection = right;    //of the tongue

    setPos(pos);
}

/*
==============================================================================================
Tongue::setPos() sets the position of the tongue (for creation)
==============================================================================================
*/
void Tongue::setPos(sf::Vector2f pos)
{
    if(mDirection == left)                          //If the direction is "left"
    {
        tongue.setPosition(pos.x - 24, pos.y - 5);  //Set the tongue to be left of player
        tongue.setRotation(135);                    //Set the rotation of tongue to extend left
    }
    else if(mDirection == right)                    //If the direction is "right"
    {
        tongue.setPosition(pos.x + 24, pos.y - 5);  //Set the tongue to be right of player
        tongue.setRotation(225);                    //Set the rotation of tongue to extend right
    }
}

/*
==============================================================================================
Tongue::logic() is where the tongue extends and other stuff too
==============================================================================================
*/
void Tongue::logic(float dt)
{
    int mTongueSpeed = 700 * dt;                //Set the speed of the tongue
    if(mDirection == left)                  //If the direction is left
    {
        mEndPos.x -= mTongueSpeed;          //End position of the tongue moves left
        mEndPos.y -= mTongueSpeed;          //In the X and Y direction, gradient of "1"
    }
    else if(mDirection == right)
    {
        mEndPos.x += mTongueSpeed;          //End position of the tongue moves right
        mEndPos.y -= mTongueSpeed;          //In the X and Y direction, gradient of "1"
    }
    setSize();
}
/*
==============================================================================================
Tongue::setSize() sets the size of the tongue
==============================================================================================
*/
void Tongue::setSize()
{
    double xd = mStartPos.x - mEndPos.x;            //Work out "x difference" between start and end of tongue
    double yd  = mStartPos.y - mEndPos.y;           //Work out "y difference" between start and end of tongue
    double length = sqrt(pow(xd, 2) + pow(yd, 2));  //Do basic Pythagoras's theorem

    sf::Vector2f tongueSize(3, length);         //Create a vector for the tongue length
    tongue.setSize(tongueSize);             //Set the size/length of tongue to what was worked out above
}


/*
==============================================================================================
Tongue::getRect() returns the rectangle (which is what tongue is; a rectangle)
==============================================================================================
*/
sf::RectangleShape Tongue::getRect()
{
    return tongue;  //"tongue" here is the rectangle that is what the player sees
}

/*
==============================================================================================
Tongue::getRectEndPos() returns the vector that is the end position of the tongue
==============================================================================================
*/
sf::Vector2f Tongue::getRectEndPos()
{
    return mEndPos;
}














