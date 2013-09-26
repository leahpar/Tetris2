Tetris2
=======

Description
-----------

Two players Tetris.
Each player has his screen. When he complete a line, some random opponent's cases are deleted.

Dependencies
------------

* SDL >= 2.0.0
* SDL_ttf
* SDL_mixer

Compile
-------

no makefile for now, sorry...

```
cd Tetris2
g++ src/*.cpp `sdl2-config --cflags --libs` -Iinclude -DLINUX -lSDL2_ttf -lSDL2_mixer
```


