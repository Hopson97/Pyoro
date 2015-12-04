#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <memory>
#include <sstream>

#include "../game.h"
#include "state.h"
#include "gameobjects.h"
#include "phaseenums.h"

class playState : public State
{
    public:
        playState(Game* game);
        void input  (float dt, float clockedTime)   override;
        void update (float dt, float clockedTime)   override;
        void draw()                                 override;

    private: //Methods
        void addFloorTiles(int amount);
        void addNormSeeds(int amount);

        typedef std::shared_ptr<Seed> seedptr;              //Typedef for shorter method names
        void checkSeed         (seedptr seed, float dt, float currTime);
        void seedsVsTongue     (seedptr seed, float currTime);
        void seedsVsFloorTiles (seedptr seed, float dt, float currTime);
        void seedsVsPlayer     (seedptr seed);

        void checkTongue(float currTime);
        void endLick();

        void checkCollText(float clockedTime);

    private: //Drawing methods
        void drawFloorTiles();
        void drawSeeds();
        void drawTongue();
        void drawScoreTexts();

        void nextPhase();


    private:
        std::vector<std::unique_ptr<FloorTile>>             mFloorTiles;    //"List" of floor tiles
        std::vector<std::shared_ptr<Seed>>                  mSeeds;         //List of seeds
        std::vector<std::shared_ptr<collectionScoreShower>> mColScoreTexts; //List of "score texts"

        Player mPlayer;         //The player
        Tongue* mTongue;        //Pointer to the players tongue
        Background mBackground; //The background

        sf::Text mScoreText;

        int mScore;
        int mHighScore;

        phase mPhase;
        drawMode mDrawMode;
};

#endif // PLAYSTATE_H
