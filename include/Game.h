#ifndef GAME_H
#define GAME_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Types.h"
#include "Player.h"


using namespace std;

class Player;
class Game
{
   public:
      Game();
      ~Game();
      
      // Create 1 or 2 player(s)
      void setPlayers(int n);

      // Game content
      int play();
      
      // Display the game on screen
      void display();
      // Print scores
      void displayScore();
 
      // Pause game
      int actionPause(string str);
      string pauseStr;

   protected:
   private:

      // screen display
      SDL_Window   *screen;
      SDL_Renderer *renderer;

      // textures
      SDL_Texture  *tileset;
      TileProp      props[NB_PX];

      // font
      TTF_Font     *font;

      // audio
      Mix_Music    *sound;
      int           pause;

      // player(s)
      int           nbPlayers;
      Player       *players[2];

      // Init functions - called by constructor
      void initSDL_Video();
      void initSDL_ttf();
      void initSDL_Mixer();
      void loadTextures();

      // get player's keyboard action
      Action getAction();

};

#endif // GAME_H
