#include "game.h"

/*
============================================================================
main()  is the start point of the program, which is where the
        game is created and the loop is begun.
============================================================================
*/
int main()
{
    srand(time(NULL));  //Set up the game ready for generating random numbers

    Game game;          //Create the game
    game.runMainLoop(); //Start the main game loop

    return 0;           //Exit
}
