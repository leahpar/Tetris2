#ifndef PIECE_H
#define PIECE_H

#include "Config.h"
#include "Types.h"

class Piece
{
   public:
      Piece();
      ~Piece();

      // array of all pieces in all states
      static int tabPieces[NB_PIECE*4][LG_PIECE][LG_PIECE];

      // move the piece in the matrix
      void movePiece(int action);
      // rotate the piece
      void rotatePiece();
      // change the current position as the new position
      void validNewPos();
      // change the new position as the current position
      void cancelNewPos();

      /********************************
         accessors
      ********************************/

      // current and new type of the piece
      int getCurType();
      void setCurType(int curType);
      int getNewType();
      void setNewType(int newType);

      // current and new position of the piece
      Position getCurPos();
      void setCurPos(Position curPos);
      Position getNewPos();
      void setNewPos(Position newPos);

      /********************************
         end accessors
      ********************************/
   protected:

   private:

      // current type
      int curType;

      // new type
      int newType;
      
      // current position
      Position curPos;

      // new position
      Position newPos;
};

#endif // PIECE_H
