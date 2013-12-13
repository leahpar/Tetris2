#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <SDL2/SDL.h>

// Some userful structures

typedef struct
{
    SDL_Rect R;
    int type;
} TileProp;

typedef struct
{
   int player;
   int action;
} Action;

typedef struct
{
   int x;
   int y;
} Position;



#endif // TYPES_H_INCLUDED
