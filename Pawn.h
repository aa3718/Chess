#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <cmath>
#include "Piece.h"
#include "Color.h"

class Pawn : public Piece {
 public:
  Color color;
  Pawn(Color col);
  bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) override;
  Color see_col() override;
  int type() override;
};

#endif
