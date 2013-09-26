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

      // game matrix
      int matrix[MATRIX_X][MATRIX_Y];

      Player(Game * game, int id);
      ~Player();

      int play(int action);
      int checkPiece(Piece * piece);
      void checkLine();
      void deleteLine(int line);
      void addLine(int level);

      int movePiece(Piece * p, int action);
      void writePiece(Piece * piece);


      int getTic();
      void levelUp();

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

      void initMatrix();

   protected:

   private:

      int lines;
      int level;
      int score;
      int pieces;

      int tic;
      int drop;
      int action;

      Piece * newPiece;
      Piece * curPiece;

      int      idPlayer;
      Player * opponent;

      Game * game;

};
#endif // PLAYER_H
