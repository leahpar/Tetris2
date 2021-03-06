#include <iostream>
#include <time.h>

#include "Device.h"
#include "Game.h"
#include "Config.h"
#include "Exceptions.h"

using namespace std;
#ifdef WIN32
#undef main
#endif
int main(int argc, char **argv)
{
   Game * _game;
   int action = 0;

   // init rand
   srand(time(NULL));

   try
   {
      _game = new Game();
      _game->setPlayers(2);
      //_game->display();

      action = _game->play();

      // wait for end pause or quit
      SDL_Event event;
      while(action != ACTION_QUIT)
      {
         SDL_WaitEvent(&event);
         switch(event.type)
         {
            case SDL_QUIT:
               action = 1;
               break;
            case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
               {
                  case SDLK_ESCAPE:
                     action = 1;
                     break;
               }
         }
         SDL_Delay(10);
      }
      delete _game;
   }
   catch (int e)
   {
      Alert(NULL, "KO", NULL, 0);
      return e;
   }

   // Alert(NULL, "OK", NULL, 0);

   return 0;
}
