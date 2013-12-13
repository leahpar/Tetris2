#ifndef PLAYER_H
#define PLAYER_H

#include "Config.h"
#include "Types.h"
#include "Game.h"
#include "Piece.h"

class Game;
class Player
{
   public:

      Player(Game * game, int id);
      ~Player();

      // playrs's matrix
      int matrix[MATRIX_X][MATRIX_Y];
      void initMatrix();

      // player's turn to play
      int play(int action);

      /********************************
         accessors
      ********************************/

      int getLines();
      void setLines(int lines);

      int getLevel();
      void setLevel(int level);

      int getScore();
      void setScore(int score);

      int getPieces();
      void setPieces(int pieces);

      Piece * getNewPiece();
      void setNewPiece(Piece * newPiece);

      Piece * getCurPiece();
      void setCurPiece(Piece * CurPiece);

      int getDrop();
      void setDrop(int drop);

      Player * getOpponent();
      void setOpponent(Player * opponent);

      /********************************
         end accessors
      ********************************/


   protected:

   private:

      Game    *game;
      int      idPlayer;
      Player  *opponent;
     
      int lines;  // total lines completed
      int level;  // current level
      int score;  // current score
      int pieces; // total pieces used

      int tic;    // tics left to play
      int drop;   // flag indicate player has dropped his piece
      int action; // current player's action

      // current piece
      Piece   *newPiece;
      // new piece (same piece, but new position and new rotation)
      Piece   *curPiece;

      // get tics available to play, depend on the level 
      int getTic();

      // update level
      void levelUp();

      // check if the piece has no collision with other piece or edge
      int checkPiece(Piece * piece);

      // check if there is complete line(s)
      void checkLine();
      // delete a (complete) line
      void deleteLine(int line);
      // add a line (opponent fight). Actually delete random PX
      void addLine(int level);

      // move, rotate or drop a piece
      int movePiece(Piece * p, int action);

      // write the piece in the player's matrix
      void writePiece(Piece * piece);

};
#endif // PLAYER_H
