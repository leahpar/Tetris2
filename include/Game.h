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

      void setPlayers(int n);

      void play();
      void display();
      void displayScore();

      int actionPause(string str);
      Action getAction();

      /********************************
         accessors
      ********************************/

      /********************************
         end accessors
      ********************************/


   protected:
   private:

      // screen display
      SDL_Window    *screen;
      SDL_Renderer  *renderer;

      // textures
      SDL_Texture   *tileset;
      TileProp      props[NB_PX];

      // font
      TTF_Font      *font;

      // audio
      Mix_Music     *sound;
      int           pause;

      // player(s)
      int           nbPlayers;
      Player       *players[];

      // Init functions - called by constructor
      void initSDL_Video();
      void initSDL_ttf();
      void initSDL_Mixer();
      void loadTextures();

};

#endif // GAME_H
