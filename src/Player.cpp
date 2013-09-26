#include <cstddef>

#include <SDL2/SDL.h>

#include "Config.h"
#include "Player.h"
#include "Game.h"

Player::Player(Game * game, int id)
{
   this->idPlayer = id;
   this->game     = game;
   this->initMatrix();
   this->curPiece = NULL;
   this->newPiece = new Piece();
   this->drop     = 0;
   this->score    = 0;
   this->lines    = 0;
   this->level    = 0;
   this->pieces   = 0;
}

Player::~Player()
{
   delete this->curPiece;
   delete this->newPiece;
}

void Player::initMatrix()
{
   int x, y;
   // empty the matrix
   for (x=0; x<MATRIX_X; x++)
      for (y=0; y<MATRIX_Y; y++)
         this->matrix[x][y] = PX_V;

   // create edges
   for (x=0; x<MATRIX_X; x++)
   {
      this->matrix[x][0]          = PX_EL;
      this->matrix[x][MATRIX_Y-1] = PX_ER;
   }
   for (y=0; y<MATRIX_Y; y++)
   {
      this->matrix[MATRIX_X-1][y]  = PX_EB;
   }
}

int Player::getTic()
{
   return (100 - 2*this->level);
}

int Player::play(int a)
{
   int action = a;
   int res;

   // need a new piece
   if (this->curPiece == NULL)
   {
      // if the new piece can go into the matrix, use it
      if (this->checkPiece(this->newPiece) == 0)
      {
         this->curPiece = this->newPiece;
         this->newPiece = new Piece();
         this->tic = this->getTic();
         this->drop = 0;
         this->pieces++;
         this->score += SCORE_PIECE;
      }
      // else, game over !
      else
      {
         return 1;
      }
   }

   // Quit game
   if (action == ACTION_QUIT) return 1;

   // Reset tic counter so player can move piece
   if (action == ACTION_DROP && this->drop == 0)
   {
      this->tic = DROP_DELAY;
      this->drop = 1;
   }
   else if (action == ACTION_DROP)
   {
      this->tic = 0;
      this->drop = 0;
   }
   // move user's action
   this->movePiece(this->curPiece, action);

   // time is running out
   this->tic--;
   if (this->tic <= 0)
   {
      res = movePiece(this->curPiece, ACTION_MOVE_DOWN);
      this->drop = 0;
      if (res != 0)
      {
         // can't move, write piece
         this->writePiece(this->curPiece);
         // check if there is some complete lines
         this->checkLine();
         delete this->curPiece;
         this->curPiece = NULL;
      }
      this->tic = this->getTic();
   }
   return 0;
}

void Player::checkLine()
{

   int c = 0;
   int x,y;
   int lines = 1;

   for (x=0; x<MATRIX_X-1; x++)
   {
      c = 0;
      for(y=1; y<MATRIX_Y-1; y++)
      {
         if (this->matrix[x][y] != PX_V) c++;
      }
      if (c == MATRIX_Y-2)
      {
         this->deleteLine(x);
         this->lines++;
         this->score += SCORE_LINE * lines;
         lines++;
      }
   }
   // if line(s) deleted, level up
   if (lines > 1)
   {
      this->levelUp();

      // fight opponent
      if (this->opponent != NULL)
      {
         this->opponent->addLine(lines);
      }
   }
}

void Player::deleteLine(int line)
{
   int x, y;

   // FX complete line
   /*
   for (y=1; y<MATRIX_Y-1; y++)
   {
      this->matrix[line][y] = PX_FX;
   }
   printMatrix(NULL);
   usleep(300000);
   */

   // move upper
   for (x=line; x>0; x--)
   {
      for (y=1; y<MATRIX_Y-1; y++)
      {
         this->matrix[x][y] = this->matrix[x-1][y];
      }
   }
   // empty 0th line
   for (y=1; y<MATRIX_Y-1; y++)
   {
      this->matrix[0][y] = PX_V;
   }
}

void Player::addLine(int lines)
{
   int i;
   int x, y;
   for (i=0; i<2*lines; i++)
   {
      x = (rand() % (MATRIX_X/2)) + MATRIX_X/2;
      y = (rand() % (MATRIX_Y-2)) + 1;
      this->matrix[x][y] = PX_V;
   }
}

void Player::levelUp()
{
   this->level++;
}

int Player::checkPiece(Piece * piece)
{
   int x,y;
   Position pos = piece->getNewPos();
   // collision
   for (x=0; x<LG_PIECE; x++)
   {
      for(y=0; y<LG_PIECE; y++)
      {
         if (Piece::tabPieces[piece->getNewType()][x][y] != PX_V
          && this->matrix[pos.x + x][pos.y + y] != PX_V)
         {
            return 1;
         }
      }
   }
   return 0;
}

int Player::movePiece(Piece * piece, int action)
{
   switch(action)
   {
      case ACTION_MOVE_DOWN:
      case ACTION_MOVE_LEFT:
      case ACTION_MOVE_RIGHT:
         piece->movePiece(action);
         break;
      case ACTION_ROTATE:
         piece->rotatePiece();
         break;
      case ACTION_DROP:
         do {
            piece->validNewPos();
            piece->movePiece(ACTION_MOVE_DOWN);
            this->score += SCORE_DROP;
         } while (this->checkPiece(piece) == 0);
         break;
      default:
         // unknown move
         return 0;
         break;
   }

   if (this->checkPiece(piece) == 0)
   {
      piece->validNewPos();
      return 0;
   }
   else
   {
      piece->cancelNewPos();
      return 1;
   }
}

void Player::writePiece(Piece * piece)
{
   int x,y;
   int px;
   Position pos = piece->getCurPos();

   for (x=0; x<LG_PIECE; x++)
   {
      for(y=0; y<LG_PIECE; y++)
      {
         px = Piece::tabPieces[piece->getNewType()][x][y];
         if (px != PX_V)
         {
            this->matrix[pos.x + x][pos.y + y] = px;
         }
      }
   }
}


/********************************
	accessors
********************************/

int Player::getLines() {
	return this->lines;
}

void Player::setLines(int lines) {
	this->lines = lines;
}

int Player::getLevel() {
	return this->level;
}

void Player::setLevel(int level) {
	this->level = level;
}

int Player::getScore() {
	return this->score;
}

void Player::setScore(int score) {
	this->score = score;
}

int Player::getPieces() {
	return this->pieces;
}

void Player::setPieces(int pieces) {
	this->pieces = pieces;
}

Piece * Player::getNewPiece() {
	return this->newPiece;
}

void Player::setNewPiece(Piece * newPiece) {
	this->newPiece = newPiece;
}

Piece * Player::getCurPiece() {
	return this->curPiece;
}

void Player::setCurPiece(Piece * curPiece) {
	this->curPiece = curPiece;
}

int Player::getDrop() {
	return this->drop;
}

void Player::setDrop(int drop) {
	this->drop = drop;
}

Player * Player::getOpponent() {
	return this->opponent;
}

void Player::setOpponent(Player * opponent) {
	this->opponent = opponent;
}

/********************************
	end accessors
********************************/

