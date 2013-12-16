#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define WINDOW_TITLE "Tetris beta"

#define DT_USLEEP  30000

#define MATRIX_X (20+1)
#define MATRIX_Y (10+2)
#define MATRIX_SPACE (12)

#define LG_PIECE   4
#define NB_PIECE   7

#define SCORE_DISPLAY_Y (MATRIX_Y*(TILE_S+2))
#define SCORE_DISPLAY_X (6*TILE_S)

#define FONT_SIZE 22
#define FONT_FILE "tetris.ttf"
#define FONT_COLOR (SDL_Color){128,128,128}

#define TILESET_FILE "texture.bmp"
#define TILE_S 30

#define AUDIO_FILE "tetris.ogg"
#define AUDIO_RATE 22050
#define AUDIO_FORMAT AUDIO_S16SYS
/* mono */
#define AUDIO_CHANNELS 1
#define AUDIO_BUFFERS 4096

#define SCORE_FILENAME "scores.dat"
#define NB_HIGHSCORE 4
#define SCORE_PIECE 10
#define SCORE_DROP  1
#define SCORE_LINE  100
#define SCORE_BONUS 100

#define PLAYER_A  0
#define PLAYER_B  1

#define DROP_DELAY 50


/**** PIXELS ******************************/
#define PX_I   0
#define PX_O   1
#define PX_T   2
#define PX_L   3
#define PX_J   4
#define PX_Z   5
#define PX_S   6
#define PX_V   7   /* void pixel */
#define PX_ET  8   /* edge top pixel */
#define PX_EB  9   /* edge bottom pixel */
#define PX_ER  10  /* edge right pixel */
#define PX_EL  11  /* edge left pixel */
#define PX_FX  12  /* FX complete line */
#define NB_PX  13

/**** USER ACTIONS ************************/
#define ACTION_NONE        -1
#define ACTION_QUIT        99
#define ACTION_PAUSE       98
#define ACTION_OVER        97
#define ACTION_MOVE_DOWN    0
#define ACTION_MOVE_LEFT    1
#define ACTION_MOVE_RIGHT   2
#define ACTION_ROTATE       3
#define ACTION_DROP         4

#endif // CONFIG_H_INCLUDED
