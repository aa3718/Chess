#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
#include <cmath>
#include "Piece.h"
#include "Color.h"

class Castle : public Piece {
 public:
  Color color;
  Castle(Color col);
  bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) override;
  Color see_col() override;
  int type() override;


};


#endif
