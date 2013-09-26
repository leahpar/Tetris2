#include <iostream>


#include "Piece.h"
#include <stdlib.h>

Piece::Piece()
{
   // new random piece
   this->newType  = (rand() % NB_PIECE);
   this->curType  = this->newType;

   this->curPos.x = 0;
   this->curPos.y = MATRIX_Y/2-2;
   this->newPos   = this->curPos;
}

Piece::~Piece()
{
   //dtor
}

void Piece::movePiece(int action)
{
   switch(action)
   {
      case ACTION_MOVE_DOWN:
         this->newPos.x++;
         break;
      case ACTION_MOVE_LEFT:
         this->newPos.y--;
         break;
      case ACTION_MOVE_RIGHT:
         this->newPos.y++;
         break;
   }
}
void Piece::rotatePiece()
{
   this->newType = (this->curType + NB_PIECE)%(4 * NB_PIECE);
}
void Piece::validNewPos()
{
   this->curPos  = this->newPos;
   this->curType = this->newType;
}
void Piece::cancelNewPos()
{
   this->newPos  = this->curPos;
   this->newType = this->curType;
}

/********************************
	accessors
********************************/

int Piece::getCurType() {
	return this->curType;
}

void Piece::setCurType(int curType) {
	this->curType = curType;
}

int Piece::getNewType() {
	return this->newType;
}

void Piece::setNewType(int newType) {
	this->newType = newType;
}

Position Piece::getCurPos() {
	return this->curPos;
}

void Piece::setCurPos(Position curPos) {
	this->curPos = curPos;
}

Position Piece::getNewPos() {
	return this->newPos;
}

void Piece::setNewPos(Position newPos) {
	this->newPos = newPos;
}

/********************************
	end accessors
********************************/



int Piece::tabPieces[NB_PIECE*4][LG_PIECE][LG_PIECE] =
{
   /************************ 0 *****************************/
   // I  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_I, PX_I, PX_I, PX_I},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // O  0
   {{PX_O, PX_O, PX_V, PX_V},
    {PX_O, PX_O, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // T  0
   {{PX_V, PX_T, PX_V, PX_V},
    {PX_T, PX_T, PX_T, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // L  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_L, PX_L, PX_L, PX_V},
    {PX_L, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // J  0
   {{PX_J, PX_V, PX_V, PX_V},
    {PX_J, PX_J, PX_J, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // Z  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_Z, PX_Z, PX_V, PX_V},
    {PX_V, PX_Z, PX_Z, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // S  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_S, PX_S, PX_V},
    {PX_S, PX_S, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   /************************ 90 *****************************/
   // I  90
   {{PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V}},

   // O  90
   {{PX_O, PX_O, PX_V, PX_V},
    {PX_O, PX_O, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // T  90
   {{PX_V, PX_T, PX_V, PX_V},
    {PX_V, PX_T, PX_T, PX_V},
    {PX_V, PX_T, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // L  90
   {{PX_L, PX_L, PX_V, PX_V},
    {PX_V, PX_L, PX_V, PX_V},
    {PX_V, PX_L, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // J  90
   {{PX_V, PX_J, PX_J, PX_V},
    {PX_V, PX_J, PX_V, PX_V},
    {PX_V, PX_J, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // Z  90
   {{PX_V, PX_V, PX_Z, PX_V},
    {PX_V, PX_Z, PX_Z, PX_V},
    {PX_V, PX_Z, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // S  90
   {{PX_V, PX_S, PX_V, PX_V},
    {PX_V, PX_S, PX_S, PX_V},
    {PX_V, PX_V, PX_S, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

    /************************ 180 *****************************/
   // I  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_I, PX_I, PX_I, PX_I},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // O  0
   {{PX_O, PX_O, PX_V, PX_V},
    {PX_O, PX_O, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // T  0
   {{PX_T, PX_T, PX_T, PX_V},
    {PX_V, PX_T, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // L  0
   {{PX_V, PX_V, PX_L, PX_V},
    {PX_L, PX_L, PX_L, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // J  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_J, PX_J, PX_J, PX_V},
    {PX_V, PX_V, PX_J, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // Z  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_Z, PX_Z, PX_V, PX_V},
    {PX_V, PX_Z, PX_Z, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // S  0
   {{PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_S, PX_S, PX_V},
    {PX_S, PX_S, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   /************************ 270 *****************************/
   // I  270
   {{PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V},
    {PX_V, PX_I, PX_V, PX_V}},

   // O  270
   {{PX_O, PX_O, PX_V, PX_V},
    {PX_O, PX_O, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // T  270
   {{PX_V, PX_T, PX_V, PX_V},
    {PX_T, PX_T, PX_V, PX_V},
    {PX_V, PX_T, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // L  270
   {{PX_V, PX_L, PX_V, PX_V},
    {PX_V, PX_L, PX_V, PX_V},
    {PX_V, PX_L, PX_L, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // J  270
   {{PX_V, PX_J, PX_V, PX_V},
    {PX_V, PX_J, PX_V, PX_V},
    {PX_J, PX_J, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // Z  270
   {{PX_V, PX_V, PX_Z, PX_V},
    {PX_V, PX_Z, PX_Z, PX_V},
    {PX_V, PX_Z, PX_V, PX_V},
    {PX_V, PX_V, PX_V, PX_V}},

   // S  270
   {{PX_V, PX_S, PX_V, PX_V},
    {PX_V, PX_S, PX_S, PX_V},
    {PX_V, PX_V, PX_S, PX_V},
    {PX_V, PX_V, PX_V, PX_V}}
};

