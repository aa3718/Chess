#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <cmath>
#include "Color.h"

class Piece {
 public:
  Color color;
  virtual bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter);
  virtual Color see_col();
  virtual int type();
};

#endif
