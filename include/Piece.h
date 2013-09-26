#ifndef PIECE_H
#define PIECE_H

#include "Config.h"
#include "Types.h"

class Piece
{
   public:
      Piece();
      ~Piece();

      static int tabPieces[NB_PIECE*4][LG_PIECE][LG_PIECE];

      void movePiece(int action);
      void rotatePiece();
      void validNewPos();
      void cancelNewPos();

      /********************************
         accessors
      ********************************/

      int getCurType();
      void setCurType(int curType);
      int getNewType();
      void setNewType(int newType);
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

      Position curPos;
      Position newPos;
};



#endif // PIECE_H
