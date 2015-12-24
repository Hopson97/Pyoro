#include "fadeeffect.h"

FadeEffect::FadeEffect(sf::Sprite sprite):
    firstFrame      (sprite),
    nextFrame       (sprite),
    opacityMain(255),
    opacityNext(0)
{
}

void FadeEffect::fade(sf::RenderWindow& window)
{
    if(mFrames.size() < 1)
    {
        std::cerr << "Fade effect not set up!" << std::endl;
        return;
    }
    firstFrame.setTextureRect(mFrames[0].mFrame);
    nextFrame .setTextureRect(mFrames[1].mFrame);

    firstFrame.setColor(sf::Color(255, 255, 255, opacityMain));
    nextFrame.setColor(sf::Color(255, 255, 255, opacityNext));

    opacityMain--;
    opacityNext++;

    window.draw(firstFrame);
    window.draw(nextFrame);
}

bool FadeEffect::fadeFinished()
{
  if(opacityMain == 0)
  {
      return true;
  }
  return false;
}
